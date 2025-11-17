#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//MERGE SORT BEGINS

void merge(vector<int>& arr, int a0, int b0, int bn) {
    int n1 = b0 - a0;
    int n2 = bn - b0 +1;
    int i=0,j=0,k=0;
    vector<int> r;
    vector<int> r;
    r.reserve(n1 + n2);
        
    while (i < n1 && j < n2) {
        if (arr[a0+i] < arr[b0+j]) {
            r.push_back(arr[a0+i]);
            i++;
        }
        else if(arr[a0+i] > arr[b0+j]) {
            r.push_back(arr[b0+j]);
            j++;
        }
        else{
            r.push_back(arr[a0+i]);
            i++;
            r.push_back(arr[b0+j]);
            j++;
        }
    }
    
    while (i < n1) {
        r.push_back(arr[a0+i]);
        i++;
    }
    
    while (j < n2) {
        r.push_back(arr[b0+j]);
        j++;
    }
    for(int m=a0, n=0; m <= bn; m++, n++)
    {
        arr[m] = r[n];
    }
}

void mergeSort(vector<int>& arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        
        merge(arr, left, mid+1, right);
    }
}

//MERGE SORT ENDS.

//QUICK SORT BEGINS

int partition(vector<int>& arr, int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    
    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quicksort(vector<int>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quicksort(arr, low, pi - 1);
        quicksort(arr, pi + 1, high);
    }
}

void quick_sort(vector<int>& arr) {
    if (arr.size() <= 1) return;
    quicksort(arr, 0, arr.size() - 1);
}

//QUICK SORT ENDS