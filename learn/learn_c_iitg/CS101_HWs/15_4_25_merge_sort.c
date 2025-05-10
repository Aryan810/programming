#include <stdio.h>

void mergeSortedArrays(int A[], int first, int mid, int last)
{
    int i, j, k;
    int sl = mid - first;
    int sr = last - mid + 1;
    int L[sl], R[sr];
    for (i = 0; i < sl; i++)
        L[i] = A[first + i];
    for (i = 0; i < sr; i++)
        R[i] = A[mid + i];
    i = j = 0;
    k = first;
    while (i < sl && j < sr)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < sl)
    { // If R remains
        A[k] = L[i];
        i++;
        k++;
    }
    while (j < sr)
    { // If L remains
        A[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int A[], int first, int last)
{
    if (first < last)
    {
        mergeSort(A, first, (first + last + 1) / 2 - 1);
        mergeSort(A, (first + last + 1) / 2, last);
        mergeSortedArrays(A, first, (first + last + 1) / 2, last);
    }
}

int main()
{
    int A[] = {3, 2, 1, 4, 4, 24, 252, 5, 0, -1, -39294, 424242, -242424242};
    mergeSort(A, 0, 12);
    for (int i=0;i<13;i++){
        printf("%d ", A[i]);
    }printf("\n");
    return 0;
}