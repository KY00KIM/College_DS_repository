#include <stdio.h>
#include <stdlib.h>
#define    N    10
void merge(int arr[], int low, int mid, int high);
void mergeSort(int arr[], int low, int high);
void printArr(int arr[], const size_t size);



void mergeSort(int arr[], int low, int high)
{
    if(low==high)return;
    mergeSort(arr, low, (low+high)/2);
    mergeSort(arr, (low+high)/2+1, high);
    merge(arr, low, (high+low)/2, high);
}


void merge(int arr[], int low, int mid, int high)
{
    int res[high+1];
    int firstIdx = low;
    int secIdx = mid+1;
    int resIdx = low;
    
    while(firstIdx<=mid && secIdx<=high){
        if(arr[firstIdx]<arr[secIdx]){
            res[resIdx]=arr[firstIdx];
            firstIdx++;
        }else{
            res[resIdx]=arr[secIdx];
            secIdx++;
        }
        resIdx++;
    }
    
    
    while(firstIdx<=mid){
        res[resIdx]=arr[firstIdx];
        resIdx++;
        firstIdx++;
    }
    while(secIdx <= high){
        res[resIdx]=arr[secIdx];
        secIdx++;
        resIdx++;
    }
    
    for(int i = low ; i <= high ; i++)
        arr[i] = res[i];
    
}




void printArr(int arr[], const size_t size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}



int main()
{
    int values[N] = { 1,0,6,7,3, 9,6,6,2,8 };

    printArr(values, N);

    mergeSort(values, 0, N - 1);

    printArr(values, N);

    return 0;
}
