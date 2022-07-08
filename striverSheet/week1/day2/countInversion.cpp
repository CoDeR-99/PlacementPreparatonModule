#include <bits/stdc++.h> 

long long int res= 0;

void merge(long long *arr, long long start, long long mid, long long end){
    long long n1= mid-start+1;
    long long n2= end-mid;
    long long a[n1], b[n2];
    for(long long i=0; i<n1; i++){
        a[i]= arr[start+i];
    }
    for(long long i=0; i<n2; i++){
        b[i]= arr[mid+1+i];
    }
    int i=0, j=0, k=start;
    while(i<n1 && j<n2){
        if(a[i]<=b[j]){
            arr[k++]= a[i++];
        }
        else{
            arr[k++]= b[j++];
            res+= (n1-i);
        }
    }
    while(i<n1){
        arr[k++]= a[i++];
    }
    while(j<n2){
        arr[k++]= b[j++];
    }
}

void mergeSort(long long *arr, long long start, long long end){
    if(start >= end)
        return;
    
        long long mid= (start+end)/2;
        mergeSort(arr, start, mid);
        mergeSort(arr, mid+1, end);
        merge(arr, start, mid, end);
}
long long getInversions(long long *arr, int n){
    // Write your code here.
    mergeSort(arr, 0, n-1);
    return res;
}