// leetcode -> Stock span problem

class StockSpanner {
public:
    stack<pair<int, int>> st;
    int idx = -1;
    StockSpanner() {
        idx = -1;
    }
    
    int next(int price) {
        idx++;
        while(!st.empty() && price >= st.top().first){
            st.pop();
        }
        int ans;

        if(st.empty()){
            ans = idx+1;
        }
        else{
            ans = idx - st.top().second;
        }

        st.push({price, idx});
        return ans;
    }
};

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */


// gfg ->

class Solution {
  public:
    vector<int> calculateSpan(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans;
        stack<pair<int, int>> st;
        int idx = -1;
        
        for(int i = 0; i< n; i++){
            while (!st.empty() && arr[i] >= st.top().first) {
                st.pop();
            }

            if (st.empty()) {
                ans.push_back(i + 1);
            } else {
                ans.push_back(i - st.top().second);
            }

            st.push({arr[i], i});
        }
        
        return ans;
    }
};
