#include "sortingAlgorithms.h"
#include <iostream>
#include <algorithm>
#include <thread>
#include <chrono>

// Bubble Sort Visualization
void bubbleSort(sf::RenderWindow &window, std::vector<int> &arr)
{
    for (size_t i = 0; i < arr.size() - 1; ++i)
    {
        for (size_t j = 0; j < arr.size() - i - 1; ++j)
        {
            if (arr[j] > arr[j + 1])
            {
                std::swap(arr[j], arr[j + 1]);
            }
            visualizeArray(window, arr, j);
            std::cout << i << " iteration: \n";
            std::cout << "i = " << i << ", j = " << j << "\n";
            for (size_t k = 0; k < arr.size(); k++)
            {
                std::cout << arr[k] << " ";
            }
            std::cout << "\n";
        }
    }
}

// Quick Sort Visualization
int x = 0;
void quickSort(sf::RenderWindow &window, std::vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int pi = partition(arr, low, high);
        std::cout << "Partition at: " << pi << "\n";
        visualizeArray(window, arr, pi);

        quickSort(window, arr, low, pi - 1);
        quickSort(window, arr, pi + 1, high);
    }
}

int partition(std::vector<int> &arr, int low, int high)
{
    int pivot = arr[high];
    std::cout << "Pivot element: " << pivot << "\n";
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++)
    {
        if (arr[j] < pivot)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    std::cout << x << " iteration: \n";
    x++;
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
    return (i + 1);
}

// Merge Sort Visualization
int m = 0;
void mergeSort(sf::RenderWindow &window, std::vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;

        mergeSort(window, arr, left, mid);
        mergeSort(window, arr, mid + 1, right);

        merge(arr, left, mid, right);
        visualizeArray(window, arr);
    }
}

void merge(std::vector<int> &arr, int left, int mid, int right)
{
    std::cout << "Mid index: " << mid << "\n";
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> leftArr(n1), rightArr(n2);

    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    std::cout << "Left Array: ";
    for (size_t i = 0; i < n1; ++i)
    {
        std::cout << leftArr[i] << " ";
    }
    std::cout << "\n";
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];
    std::cout << "Right  Array: ";
    for (size_t i = 0; i < n2; ++i)
    {
        std::cout << rightArr[i] << " ";
    }
    std::cout << "\n";

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2)
    {
        if (leftArr[i] <= rightArr[j])
        {
            arr[k] = leftArr[i];
            i++;
        }
        else
        {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    while (j < n2)
    {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    std::cout << m << " iteration: \n";
    m++;
    for (size_t i = 0; i < arr.size(); i++)
    {
        std::cout << arr[i] << " ";
    }
    std::cout << "\n";
}
