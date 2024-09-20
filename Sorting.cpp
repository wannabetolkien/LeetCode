#include <bits/stdc++.h>
using namespace std;

#define lint long long int

void selectionSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        int min_i=i;
        for(int j=i+1;j<n;j++){
            if(arr[min_i]>arr[j]){
                min_i=j;
            }
        }
        swap(arr[min_i],arr[i]);
    }
}

void bubbleSort(int arr[],int n){
    for(int i=0;i<n-1;i++){
        bool isSorted=true;
        for(int j=0;j<n-i-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSorted=false;
            }
        }
        if(isSorted)
        break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void insertionSort(int arr[],int n){
    for(int i=1;i<n;i++){
        int toSwap=arr[i];
        int j=i-1;
        while(arr[j]>toSwap && j>=0){
            arr[j+1]=arr[j];
            j--;
        }

        arr[j+1]=toSwap;
    }
}

void merge(int arr[], int l, int m, int r){
    vector<int> temp;
    int first=l;
    int second=m+1;
         
    while(first<=m && second<=r){
        if(arr[first]<=arr[second]){
            temp.push_back(arr[first]);
            first++;
        }
        else{
            temp.push_back(arr[second]);
            second++;
        }
    }
    while(first<=m){
        temp.push_back(arr[first]);
        first++;
    }
    while(second<=r){
        temp.push_back(arr[second]);
        second++;
    }
         
    for(int i=l;i<=r;i++){
        arr[i]=temp[i-l];
    }
}

void mergeSort(int arr[], int l, int r){
    if(l>=r) return;
        
    int mid=l+(r-l)/2;
        
    mergeSort(arr,l,mid);
    mergeSort(arr,mid+1,r);
        
    merge(arr,l,mid,r);
}

void quickSort(int arr[], int low, int high) {
    if (low >= high) return;

    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i <= j) {
        while (i <= j && arr[i] <= pivot) {
            i++;
        }
        while (i <= j && arr[j] > pivot) {
            j--;
        }
        if (i < j) {
            std::swap(arr[i], arr[j]);
        }
    }

    std::swap(arr[low], arr[j]);

    
    quickSort(arr, low, j - 1);
    quickSort(arr, j + 1, high);
}

int main() {
    int arr[]={3,4,2,1,187,-1,1};
    quickSort(arr,0,7);
    
    for(auto a:arr){
        cout<<a<<" ";
    }
}
