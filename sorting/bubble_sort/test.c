#include <stdio.h>
#include <stdlib.h>
#include "bubble_sort.h"

#define N 20
int main()
{
    /* Initialize the random array */
    int *nums = (int *)malloc(N * sizeof(int));
    for (int i = 0; i < N; ++i)
        nums[i] = rand();

    /* Print the array before bubble sorting */
    printf("Before sorting : ");
    for (int i = 0; i < N; ++i)
        printf("%d ", nums[i]);
    printf("\n");

    /* Do bubble sort */
    bubble_sort(nums, N, 0);

    /* Print the array after bubble sorting */
    printf("After sorting : ");
    for (int i = 0; i < N; ++i)
        printf("%d ", nums[i]);
    printf("\n");
}