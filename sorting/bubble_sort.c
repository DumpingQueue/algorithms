#include <stdio.h>
/*
 * https://de.wikipedia.org/wiki/Bubblesort
 * complexity: O(n²)
 * author: peakstack
 * 23.01.2019
 */

#define SIZE 12

void bubble_sort(int list[])
{
    for (int i = 0; i < SIZE - 1; ++i)
    {
        for (int j = 0; j < SIZE - i - 1; ++j)
        {
            if (list[j] > list[j + 1]) {
                {
                    int tmp = list[j];
                    list[j] = list[j + 1];
                    list[j + 1] = tmp;
                }
            }
        }
    }
}

int main()
{
    int list[SIZE] = {3, 8, 0, 4, 3 ,5 , 6, 3, 2, 0, 1, 2};
    bubble_sort(list);
    for (int i = 0; i < SIZE; ++i)
    {
        printf("%i\t", list[i]);
    }
}
