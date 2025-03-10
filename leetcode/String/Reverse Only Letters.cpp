class Solution {
public:
    string reverseOnlyLetters(string s) {
        int n = s.size();
        string arr = s;

        int low = 0, high = n-1;

        while(low < high){
            if(!isalpha(arr[low])){
                low++;
            }
            else if(!isalpha(arr[high])){
                high--;
            }
            else{
                swap(arr[low], arr[high]);
                low++;
                high--;
            }
        }
        return arr;
    }
};
