// bubble sort -> o(n^2)

vector<int> bubbleSort(vector<int> &arr){
    int n = arr.size();
    bool flag = true;
    for(int i = 0; i< n-1 && flag; i++){
        flag = false;
        for(int j = 0; j< n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                flag = true;
            }
        }

        if(flag == false) break;
    }
    return arr;
}

// selection sort -> o(n^2)
// need minimum position
vector<int> selectionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 0; i< n-1; i++){
        int min_pos = i;

        for(int j = i+1; j< n; j++){
            if(arr[min_pos] > arr[j]){
                min_pos = j;
            }
        }
        swap(arr[min_pos], arr[i]);
    }
    return arr;
}

// insertion sort -> o(n^2)
// need key and while loop
vector<int> insertionSort(vector<int> &arr){
    int n = arr.size();
    for(int i = 1; i< n; i++){
        int key = arr[i];
        int j = i-1;
        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
    return arr;
}

// mergesort -> for all condition o(nlog(n))
// divide and merge
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
        mergeSort(arr, mid+1, high);

        merge(arr, low, mid, high);
    }
};

int main(){
    Solution s;
    // vector<int> arr = {5, 2, 1, 3, 4, 7, 6};
    // vector<int> arr = {1, 5, 3, 2, 4};
    vector<int> arr = {5, 2, 1};
    int n = arr.size();
    s.mergeSort(arr,0, n-1);
    cout<<"The answer is: ";
    for(int i = 0; i< n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

// quick sort -> o(nlog(n)) [except worst case array is already sorted]
// use pivot
#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &arr, int low, int high){
    int pivot = arr[low];
    int i = low;
    int j = high;

    while(i < j){
        // please write the index condition first
        while(arr[i] <= pivot && i <= high){
            i++;
        }
        while(arr[j] > pivot && j >= low){
            j--;
        }

        if(i < j) swap(arr[i], arr[j]);
    }

    swap(arr[low], arr[j]);
    return j;
}

void quickSort(vector<int> &arr, int low, int high){
    if(low >= high) return;

    int partitionIdx = partition(arr, low, high);
    quickSort(arr, low, partitionIdx-1);
    quickSort(arr, partitionIdx+1, high);

}

int main(){
    vector<int> arr = {1, 3, 4, 2, 5, 7};
    quickSort(arr, 0, 5);
    for(int i = 0; i< arr.size(); i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
