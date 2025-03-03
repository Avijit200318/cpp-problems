class Solution {
public:
    string baseNeg2(int n) {
        string ans = "";
        if(n == 0) return "0";

        while(n != 0){
            if(n & 1){
                ans = '1' + ans;
            }
            else{
                ans = '0' + ans;
            }

            n = -1*(n>>1);
            // this will divide by -2 but in binary -1 represent as 1111 1111. (n>>1) let n = 3 -> 11 after shift it willbe 1 only and since we are multiplying 1 with -1 then the next loop bits become 1111 1111
        }

        return ans;
    }
};
