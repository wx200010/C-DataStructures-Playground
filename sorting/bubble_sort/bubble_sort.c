#include "bubble_sort.h"
/*  swapping the value of a and b  */
static void swap_int(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

/*  Sorting the array using bubble sort method.

    The descending parameter determines whether the sorting
    is in ascending or descending order.
*/
void bubble_sort(int nums[], int size, int descending)
{
    for (int i = 1; i < size; ++i)
        for (int j = 0; j < size - i; ++j)
            if ((nums[j] > nums[j + 1]) ^ descending)
                swap_int(&nums[j], &nums[j + 1]);
}