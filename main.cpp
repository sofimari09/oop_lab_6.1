#include <iostream>
#include "Array.h"
#include <time.h>

Array returnDynamicArray(int arr[], const int size)
{
    Array dynamicArray = Array(size);

    for (int i = 0; i < size; i++)
        dynamicArray[i] = arr[i];

    return dynamicArray;
}

int main()
{
    srand((unsigned)time(NULL));
    const int size = 20;
    int arr[size];

    for (int i = 0; i < size; i++)
        arr[i] = -50 + rand() % int(50 - (-50) + 1);

    Array taskArray = returnDynamicArray(arr, size);
    taskArray.Print();

    taskArray.MyTask();
    taskArray.Print();

    taskArray.GeneralTask();
    taskArray.Print();

    return 0;
}
