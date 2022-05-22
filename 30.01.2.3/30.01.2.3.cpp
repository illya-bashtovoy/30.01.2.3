/*
Завдання 3. Написати функцію, яка отримує покажчик  на статичний масив і його розмір.Функція розподіляє
додатні, від’ємні та нульові елементи в окремі динамічні масиви
*/

#include <iostream>
#include <ctime>
#include <Windows.h>

using namespace std;

void fillingArr(int* arr, int size);
void printArr(const int* arr, const int size);
void dellArr(const int* arr, const int newsize);
void divisionArr(int* arr, int size, int* posArr, int& posCount, int* zeroArr, int& zeroCount, int* negArr, int& negCount);

int main() {
    srand(time(NULL));
    SetConsoleCP(1251); 
    SetConsoleOutputCP(1251);  

    int size = 0;
    int posCount = 0; 
    int zeroCount = 0; 
    int negCount = 0; 

    cout << "Введіть розмір size елементів масиву" << endl;
    cin >> size;

    int* arr = new int[size];
    int* posArr = new int[posCount]; 
    int* zeroArr = new int[zeroCount]; 
    int* negArr = new int[negCount]; 

    fillingArr(arr, size);
    cout << "Елементи масиву" << endl;

    printArr(arr, size);
    cout << endl;

    divisionArr(arr, size, posArr, posCount, zeroArr, zeroCount, negArr, negCount);
    cout << "Позитивні елементи окремого масиву  " << endl;

    printArr(posArr, posCount);
    cout << "Числа 0 окремого масиву  " << endl;

    printArr(zeroArr, zeroCount);  
    cout << "Негативні елементи окремого масиву  " << endl;

    printArr(negArr, negCount);
    
    delete[]arr;
    delete[]posArr;
    delete[]zeroArr; 
    delete[]negArr; 
}


void fillingArr(int* arr, int size) { 
    for (int i = 0; i < size; i++)  {
        arr[i] = rand() % 50 - 20; 
    }
}


void printArr(const int* arr, const int size) {
    for (int i = 0; i < size; i++) {
        cout << "arr [" << i << "] =" << " " << arr[i] << endl;
    }
}


void dellArr(const int* arr, const int newsize) {
    for (int i = 0; i < newsize; i++) {
        cout << "arr [" << i << "] =" << " " << arr[i] << endl;
    }
}


void divisionArr(int* arr, int size, int* posArr, int& posCount, int* zeroArr, int& zeroCount, int* negArr, int& negCount) {
    for (int i = 0; i < size; i++) {
        if (arr[i] > 0) {
            posArr[posCount] = arr[i]; 
            posCount++;
        }

        if (arr[i] == 0) {
            zeroArr[zeroCount] = arr[i];
            zeroCount++;
        }

        if (arr[i] < 0) {
            negArr[negCount] = arr[i]; 
            negCount++;
        }
    }
}