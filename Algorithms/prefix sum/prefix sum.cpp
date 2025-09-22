// 1. prefix sum sum in a given range

vector<int> prefixSum(vector<int> arr, int n){
    int sum = 0;
    vector<int> ans;

    for(int i = 0; i< n; i++){
        sum += arr[i];
        ans.push_back(sum);
    }
    return ans;
}

int sumRange(int left, int right, vector<int> arr){
    vector<int> prefix = prefixSum(arr, arr.size());

    int rightSum = prefix[right];
    int leftSum = left > 0? prefix[left-1] : 0;
    return rightSum - leftSum;
}