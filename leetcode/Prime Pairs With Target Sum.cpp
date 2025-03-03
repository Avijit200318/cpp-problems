// Prime Pairs With Target Sum
class Solution {
public:

    // bool isPrime(int n){
    //     if(n <= 1) return false;

    //     for(int i = 2; i<= sqrt(n); i++){
    //         if(n % i == 0){
    //             return false;
    //         }

    //     }
    //     return true;
    // }

    // vector<vector<int>> findPrimePairs(int n) {
    //     set<vector<int>> ans;

    //     for(int i = 2; i<= n/2; i++){
    //         if(isPrime(i) && isPrime(n-i)){
    //             vector<int> temp;
    //             temp.push_back(i);
    //             temp.push_back(n-i);
    //             sort(temp.begin(), temp.end());
    //             ans.insert(temp);
    //         }
    //     }

    //     return vector<vector<int>> (ans.begin(), ans.end());
    // }

    vector<bool> seive(int n){
        vector<bool> prime(n+1, true);

        for(int i = 2; i*i <= n; i++){
            if(prime[i]){
                for(int j = i*i; j <= n; j = j+i){
                    prime[j] = false;
                }
            }
        }
        return prime;
    }

    vector<vector<int>> findPrimePairs(int n) {
        vector<vector<int>> ans;

        vector<bool> prime;
        prime = seive(n);

        for(int i = 2; i<= n/2; i++){
            if(prime[i] && prime[n-i]){
                ans.push_back({i, n-i});
            }
        }
        return ans;
    }
};
