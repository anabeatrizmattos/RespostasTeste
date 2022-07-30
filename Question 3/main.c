#include <stdio.h>
//Calculate the array size
#define ARRAY_SIZE(a)  sizeof(a)/sizeof(a[0])

// Function to find the minimum and maximum element of the array
int* calc(int arr[], int N)
{
    int i;
    int sum = 0;
    int min = arr[0], max = arr[0];
    double average; 
    int *even_numbers;
    int i, numb_even_numbers;

    for (i = 0, numb_even_numbers = 0; i < N; i++)
    {
        // checking min value
        if (arr[i] < min)
        {
            min = arr[i];
        }
        // checking max value
        if (arr[i] > max)
        {
            max = arr[i];
        }

        if (arr[i] % 2 == 0)
        {
            numb_even_numbers++;
        }

        sum = sum + arr[i];
    }

    average = sum/N;

    even_numbers = malloc(sizeof(int) * numb_even_numbers);
    if (!even_numbers)
    {
        perror("malloc");
        return 1;
    }
    for (i = 0, numb_even_numbers = 0; i < N; i++)
    {
        if (arr[i] % 2 == 0)
            even_numbers[numb_even_numbers++] = arr[i];
    }

    // Print the minimum and maximum element
    printf("Min element is %d\n", min);
    printf("Max element is %d\n", max);
    printf("Average %f\n", average);

    return even_numbers;
}
int main()
{
    int * p;
    // an array to test
    int arr[] = {2, 3, 4, 1};
    // length of the array
    int N = ARRAY_SIZE(arr);
    // Function call, returning even numbers
    p = calc(arr, N);
    return 0;
}