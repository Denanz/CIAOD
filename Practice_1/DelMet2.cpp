#include <iostream>
#include <ctime> // Для использования функции time
#include <cstdlib> // Для использования функций rand и srand
#include <chrono>

using namespace std;

void DelOtherMethod(int* x, int& n, int key) {
    int count1 = 1, count2 = 0;
    int j = 0;
    for (int i = 0; i < n; i++) {
        count1++;
        x[j] = x[i];
        count2++;
        count1++;
        if (x[i] != key) {
            j++;
        }
    }
    n = j;
    cout << "Number of comparisons:" << count1 << endl;
    cout << "Number of permutations:" << count2 << endl;
}

void FillArrayManually(int* arr, int n) {
    cout << "Enter " << n << " elements:" << endl;
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
}

void FillArrayAutomatically(int* arr, int n) {
    srand(time(nullptr)); // Инициализация генератора случайных чисел текущим временем
    for (int i = 0; i < n; ++i) {
        arr[i] = rand() % 100 + 1; // Генерация случайного числа в диапазоне от 1 до 10
    }
}

int main() {
    int arr[100]; // Массив для хранения данных
    int n;
    char choice;

    cout << "Enter the size of the array: ";
    cin >> n;

    cout << "Do you want to fill the array manually? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        FillArrayManually(arr, n);
    } else {
        FillArrayAutomatically(arr, n);
    }

    int key; // Элемент для удаления
    cout << "Enter the element to remove: ";
    cin >> key;

    auto start = chrono::steady_clock::now(); // Начало измерения времени
    cout << "Array:";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    DelOtherMethod(arr, n, key); // Удаляем элементы равные key из массива arr

    cout << "Array after removal: ";
    for (int i = 0; i < n; ++i) {
        cout << arr[i] << " ";
    }
    auto end = chrono::steady_clock::now(); // Конец измерения времени
    cout << endl;
    cout << "Elapsed time in milliseconds: " << chrono::duration_cast<chrono::milliseconds>(end - start).count() << " ms" << endl;

    return 0;
}
