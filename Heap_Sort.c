#include<stdio.h>
#include<stdlib.h>

void swap(int *a,int *b)
{
    int t=*a;
    *a=*b;
    *b=t;
}
void heapify(int A[],int n,int i)
{
    int largest=i;
    int left=2*i+1;
    int right=2*i+2;
    if(left<n && A[largest]<A[left])
    {
        largest=left;

    }
    if(right<n && A[largest]<A[right])
    {
        largest=right;
    }
    if(i!=largest)
    {
        swap(&A[i],&A[largest]);
        heapify(A,n,largest);
    }
}
void heapsort(int A[],int n)
{
    int i;
    for(i=(n/2)-1;i>=0;i--)
    {
        heapify(A,n,i);
    }
    for(i=n-1;i>0;i--)
    {
        swap(&A[0],&A[i]);
        heapify(A,i,0);
    }
}
void printarray(int A[],int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",A[i]);
    }
    printf("\n");
}
int main()
{
    int n,i;
    printf("Enter the size of the array: ");
    scanf("%d",&n);

    int *A=malloc(n * sizeof(int));

    printf("Enter the elements of the array: ");
    for(i=0;i<n;i++)
    {
        scanf("%d",&A[i]);
    }

    printf("heap sorted elements are: ");
    heapsort(A,n);
    printarray(A,n);

    return 0;
}
