#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i];
        if (i < size - 1) cout << " ";
    }
    cout << endl;
}

int main() {
    setlocale(LC_ALL, "Russian");

    string input1, input2;

    cout << "Введите первый массив чисел через пробел: ";
    getline(cin, input1);

    cout << "Введите второй массив чисел через пробел: ";
    getline(cin, input2);

    int size1 = 0, size2 = 0;
    stringstream ss1(input1), ss2(input2);
    int num;

    while (ss1 >> num) size1++;
    while (ss2 >> num) size2++;

    int* arr1 = new int[size1];
    int* arr2 = new int[size2];
    int* result = new int[size1 + size2];

    ss1.clear();
    ss1.str(input1);
    ss2.clear();
    ss2.str(input2);

    for (int i = 0; i < size1; i++) {
        ss1 >> arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        ss2 >> arr2[i];
    }

    cout << "\nПервый массив: ";
    printArray(arr1, size1);
    cout << "Второй массив: ";
    printArray(arr2, size2);

    bubbleSort(arr1, size1);
    bubbleSort(arr2, size2);

    cout << "Первый массив после сортировки: ";
    printArray(arr1, size1);
    cout << "Второй массив после сортировки: ";
    printArray(arr2, size2);

    for (int i = 0; i < size1; i++) {
        result[i] = arr1[i];
    }

    for (int i = 0; i < size2; i++) {
        result[size1 + i] = arr2[i];
    }

    cout << "Результирующий массив: ";
    printArray(result, size1 + size2);


    //задание 2

    using namespace std;

    setlocale(LC_ALL, "");

    string text;
    cout << "Введите строку: ";
    getline(cin, text);

    if (text.empty()) {
        cout << "Строка пуста" << endl;
        return 0;
    }

    stringstream ss(text);
    string word;
    int minLength = -1;
    int countShortWords = 0;

    while (ss >> word) {
        int wordLength = word.length();

        if (minLength == -1 || wordLength < minLength) {
            minLength = wordLength;
            countShortWords = 1;
        }
        else if (wordLength == minLength) {
            countShortWords++;
        }
    }

    if (minLength > 0) {
        cout << "Длина самого короткого слова: " << minLength << endl;
        cout << "Количество слов такой длины: " << countShortWords << endl;
    }

    return 0;
}
