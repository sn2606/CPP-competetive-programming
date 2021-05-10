#include <iostream>
#include <algorithm>

namespace quickSortImp
{
    int partition(int arr[], int low, int high)
    {
        int pivot = arr[high];
        int pos = low - 1;

        for (int i = low; i <= high; i++)
        {
            if (arr[i] < pivot)
            {
                pos++;
                std::swap(arr[i], arr[pos]);
            }
        }

        std::swap(arr[high], arr[pos + 1]);
        return pos + 1;
    }

    void quickSort(int arr[], int low, int high)
    {
        if (low < high)
        {
            int p = partition(arr, low, high);
            quickSort(arr, low, p - 1);
            quickSort(arr, p + 1, high);
        }
    }

} // namespace quickSort

void printArr(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        std::cout << arr[i] << " ";
    }

    std::cout << "\n";
}

/** Driver program to test above functions */
int main()
{
    int size;
    std::cout << "\nEnter the number of elements : ";

    std::cin >> size;

    int *arr = new int[size];

    std::cout << "\nEnter the unsorted elements : ";

    for (int i = 0; i < size; ++i)
    {
        std::cin >> arr[i];
    }

    quickSortImp::quickSort(arr, 0, size-1);
    
    std::cout << "Sorted array\n";    
    printArr(arr, size);
    
    delete[] arr;
    
    return 0;
}