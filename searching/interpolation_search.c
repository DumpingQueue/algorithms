#include <stdio.h>
#include <math.h>

/*
 * https://de.wikipedia.org/wiki/Interpolationssuche
 * complexity: O(log(log(n)))
 * author: peakstack
 * 19.01.2019
 */

int interpolation_search(const int array[], int v, int max)
{
    int left = 0, right = max - 1;

    while (left <= right)
    {
        //x = l + ((v-A[l]) / (A[r]-A[l])) * (r-l)
        double x = left + ((double)(v - array[left]) / (double)(array[right] - array[left])) * (right - left);

        //checks if number has to be floored or ceiled
        double temp = floor(x);
        int pos = (x - 0.5) > temp ? (int)ceil(x) : (int)temp;
        int current = array[pos];

        if(current == v)
        {
            return pos;
        }
        else if(current < v)
        {
            left = pos + 1;
        }
        else
        {
            right = pos - 1;
        }
    }
    return -1;
}

#define SIZE 9

int main()
{
    int number_to_search = 21;
    const int array[SIZE] = {2, 4, 7, 9, 12, 21, 26, 31, 37};//array needs to be sorted
    printf("%i", interpolation_search(array, number_to_search, SIZE));
}
