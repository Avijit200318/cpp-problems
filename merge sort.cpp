#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    void merge(vector<int> &arr, int low, int mid, int high){
        int left = low, right = mid + 1;
        vector<int> temp;
        while(left <= mid && right <= high){
            if(arr[left] <= arr[right]){
                temp.push_back(arr[left]);
                left++;
            }
            else{
                temp.push_back(arr[right]);
                right++;
            }
        }

        while(left <= mid){
            temp.push_back(arr[left]);
                left++;
        }

        while(right <= high){
            temp.push_back(arr[right]);
                right++;
        }

        for(int i = low; i<= high; i++){
            arr[i] = temp[i-low];
        }
    }

    void mergeSort(vector<int> &arr, int low, int high){
        if(low >= high) return;
        int mid = (low + high)/2;

        mergeSort(arr, low, mid);
        mergeSort(arr, high, mid);

        merge(arr, low, mid, high);
    }
};

int main(){
    Solution s;
    // vector<int> arr = {5, 2, 1, 3, 4, 7, 6};
    // vector<int> arr = {1, 5, 3, 2, 4};
    vector<int> arr = {5, 2, 1};
    int n = arr.size();
    s.mergeSort(arr,0, n);
    cout<<"The answer is: ";
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
