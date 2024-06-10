class Solution {
  public:
    bool classArrangement(int n, vector<int> &arr) {
        vector<int> res = arr;
        sort(res.begin(), res.end());
        int count = 0;
        bool duplicate = false;
        for(int i = 0; i< n; i++){
            if(arr[i] != res[i]){
                count ++;
            }
            if(i > 0 && arr[i] == arr[i-1]){
                duplicate = true;
            }
        }
        if(count == 2){
            return true;
        }
        if(count == 0){
            return duplicate;
        }
        return false;
    }
};
