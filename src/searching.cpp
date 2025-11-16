#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int linearSearch(const vector<int>& arr, int key){
    for(int i=0; i<arr.size(); i++)
    {
        if(arr[i] == key)
            return i;
    }
    return -1;
}

int binarySearch(const vector<int>& arr, int key){
    int low=0;
    int high=(arr.size())-1;
    int mid;
    while(low <= high)
    {
        mid=low+((high-low)/2);
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            high=mid-1;
        else{
            low=mid+1;
        }
    }
    return -1;
}
