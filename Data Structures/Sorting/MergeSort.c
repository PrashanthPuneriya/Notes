#include<stdio.h>
#include<stdlib.h>

void Merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;   //index is counted from 0. Hence, mid + 1
    int n2 = right - mid;
    int i, j, k;
    int L[n1], R[n2];

    for(i = 0; i < n1; i++)
        L[i] = arr[left + i];   // sorted L array
    for(j = 0; j < n2; j++) 
        R[j] = arr[mid + 1 + j];    // sorted R array

    i = 0;
    j = 0;
    k = left;

    while(i < n1 && j < n2) {
        if(i < n1 && L[i] <= R[j]) {   // compare L and R array elements(sorted) and then push it into arr array. This makes arr sorted.
            arr[k] = L[i]; // Push the L array elements(sorted)
            i++;
        }
        else {
            arr[k] = R[j];  // Push the R array elements(sorted)
            j++;
        }
        k++;
    }
    
    while (i < n1) // Copy the remaining elements of L[], if there are any
    { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 

    while (j < n2) // Copy the remaining elements of R[], if there are any
    { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
}

void MergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = (left + right) / 2;   // defines the current array in 2 parts .
        MergeSort (arr, left, mid);   // sort the 1st part of array .
        MergeSort (arr, mid + 1, right); // sort the 2nd part of array.
        // merge the both parts by comparing elements of both the parts.
        Merge (arr, left, mid, right);
    }                    
}

void printArray(int A[], int size) 
{ 
    int i; 
    for (i=0; i < size; i++) 
        printf("%d ", A[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int arr[] = {12, 11, 13, 5, 6, 7}; 
    int arr_size = sizeof(arr)/sizeof(arr[0]); 
  
    printf("Given array is \n"); 
    printArray(arr, arr_size); 
  
    MergeSort(arr, 0, arr_size - 1); 
  
    printf("\nSorted array is \n"); 
    printArray(arr, arr_size); 
    return 0; 
}
