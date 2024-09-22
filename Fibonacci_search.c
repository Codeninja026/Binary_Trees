#include<stdio.h>

int min(int a,int b)
{
    return (a<b)?a:b;
}
int fibonacciSearch(int a[], int n, int key)
{
    // Initialize Fibonacci numbers
    int fib2 = 0;  // (m-2)'th Fibonacci number
    int fib1 = 1;  // (m-1)'th Fibonacci number
    int fibM = fib1 + fib2;  // m'th Fibonacci number

    // Find the smallest Fibonacci number greater than or equal to n
    while (fibM < n) 
    {
        fib2 = fib1;
        fib1 = fibM;
        fibM = fib1 + fib2;
    }

    // Marks the eliminated range from front
    int offset = -1;

    // While there are elements to be inspected, compare with the Fibonacci numbers
    while (fibM > 1)
    {
        // Check if fib2 is a valid location
        int i = min(offset + fib2, n - 1);

        // If key is greater than the value at index fib2, cut the subarray from offset to i
        if (a[i] < key)
        {
            fibM = fib1;
            fib1 = fib2;
            fib2 = fibM - fib1;
            offset = i;
        }
        // If key is smaller, cut the subarray after i+1
        else if (a[i] > key)
        {
            fibM = fib2;
            fib1 = fib1 - fib2;
            fib2 = fibM - fib1;
        }
        // Key found
        else
        {
            return i;
        }
    }

    // Comparing the last element with the key
    if (fib1 && a[offset + 1] == key)
    {
        return offset + 1;
    }

    // If the element is not found, return -1
    return -1;
}
int main()
{
    int n,key;
    
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int a[100];
    printf("Enter the elements: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);    
    }

    printf("\n");

    printf("Enter the key value: ");
    scanf("%d",&key);

    int result = fibonacciSearch(a,n,key);

    if(result!=-1)
    {
        printf("............Element found..........\n");
    }
    else
    {
        printf("...........Element Not found...........\n");
    }

    return 0;
}
