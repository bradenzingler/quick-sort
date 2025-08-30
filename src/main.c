#include "printf.h"
#include "main.h"

int partition(int *arr, int low, int high)
{
    int pivot = arr[high];

    int curr_indx = low - 1;
    for (int i = low; i < high; i++)
    {
        if (*(arr + i) < pivot)
        {
            // swap
            curr_indx++;
            int temp = *(arr + i);
            *(arr + i) = *(arr + curr_indx);
            *(arr + curr_indx) = temp;
        }
    }

    int temp = arr[curr_indx + 1];
    arr[curr_indx + 1] = pivot;
    arr[high] = temp;
    return curr_indx + 1;
}

void quicksort(int *arr, int low, int high)
{
    if (low > high)
    {
        return;
    }

    int partition_index = partition(arr, low, high);

    quicksort(arr, low, partition_index - 1);
    quicksort(arr, partition_index + 1, high);
}
