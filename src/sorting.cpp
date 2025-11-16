#include<iostream>
#include<vector>

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