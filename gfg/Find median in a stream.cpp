// Find median in a stream

#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    priority_queue<int> maxHeap;
    priority_queue<int, vector<int>, greater<int>> minHeap;

    void addNum(int num){
        int lsize = maxHeap.size();
        int rsize = minHeap.size();

        if(lsize == 0){
            // means both are the max and min heap is empty so we first push element inside the max heap
            maxHeap.push(num);
        }
        else if(lsize == rsize){
            // means both of the max and min heap contain same no of elements and we want to add an extra value. So it will be goest to maxHeap.
            if(num < minHeap.top()){
                // all the bigger numbers are store inside the minHeap(low -> high) and the top value is the lowest value if num is lesser than the top means it surely goes to maxHeap
                maxHeap.push(num);
            }
            else{
                // the num value is bigger than the min heap top. so the num's right position is inside the minHeap but we need to add element inside maxHeap. So pop the top elemnet from min heap and push it inside the maxHeap and push num inside the min heap
                int temp = minHeap.top();
                minHeap.pop();
                minHeap.push(num);
                maxHeap.push(temp);
            }
        }
        else{
            // max heap is not empty and both of the heaps  size are not same
            // it contain again 3 condition - 1) minHeap is empty 2) if the num is greater than the minHeap's top or equal 3) if the num is smaller than the maxHeap's top

            // for any case we need to add element inside the minHeap
            if(minHeap.size() == 0){
                if(num > maxHeap.top()){
                    // the number is bigger than the maxHeap's(big -> low) top which is the highest value of maxHeap. then the num is surely goes inside the minHeap
                    minHeap.push(num);
                }
                else{
                    // number is smaller than the maxHeap top. so it's correct position is inside the maxHeap. but we need to add element inside the minHeap. so pop the top value from maxHeap and push inside the minHeap and push num inside the maxHeap

                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
            }
            else if(num >= minHeap.top()){
                // if the number is greater than the minHeap top then it always goes inside the minHeap
                minHeap.push(num);
            }
            else{
                if(num < maxHeap.top()){
                    // the number will go inside the maxHeap but we need to add element inside the minHeap
                    int temp = maxHeap.top();
                    maxHeap.pop();
                    maxHeap.push(num);
                    minHeap.push(temp);
                }
                else{
                    // else then
                    minHeap.push(num);
                }
            }
        }
    }

    double findMedian(){
        int lsize = maxHeap.size();
        int rsize = minHeap.size();

        if(lsize == rsize){
            return double((maxHeap.top() + minHeap.top())/2.0);
        }
        return double(maxHeap.top());
    }

    vector<double> median(vector<int> arr){
        int n = arr.size();
        vector<double> ans;
        for(int i = 0; i< n; i++){
            addNum(arr[i]);
            ans.push_back(findMedian());
        }
        return ans;
    }
};

int main(){
    Solution s;
    vector<double> a = s.median({5, 15, 1, 3, 2, 8});
    // vector<double> a = s.median({2, 2, 2, 2});
    cout<<"The answer is: "<<endl;
    for(int i = 0; i< a.size(); i++){
        cout<< a[i]<<" ";
    }
    return 0;
}
