// class Solution {
//   public:
//     int hIndex(vector<int>& citations) {
//         // code here
//         sort(citations.begin(), citations.end());
//         reverse(citations.begin(), citations.end());
        
//         int idx = 0;
//         int n = citations.size();
        
//         while(idx< n && citations[idx] > idx){
//             idx++;
//         }
//         return idx;
//     }
// };
class Solution {
  public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> feq(n+1, 0);
        
        for(int i = 0; i < n; i++){
            if(citations[i] > n){
                feq[n] += 1;
            }
            else{
                feq[citations[i]] += 1;
            }
        }
        
        
        int s = feq[n];
        int i = n;
        while(i >= 0 && i > s){
            i--;
            s += feq[i];
        }
        return i;
    }
};
