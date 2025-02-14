// 1352. Product of the Last K Numbers
// Solved
// Medium
// Topics
// Companies
// Hint
// Design an algorithm that accepts a stream of integers and retrieves the product of the last k integers of the stream.

// Implement the ProductOfNumbers class:

// ProductOfNumbers() Initializes the object with an empty stream.
// void add(int num) Appends the integer num to the stream.
// int getProduct(int k) Returns the product of the last k numbers in the current list. You can assume that always the current list has at least k numbers.
// The test cases are generated so that, at any time, the product of any contiguous sequence of numbers will fit into a single 32-bit integer without overflowing.

class ProductOfNumbers {
public:
    vector<int> ans = {1};
    int idx;
    int lastZero;
    ProductOfNumbers() {
        idx = 1;
        lastZero = -1;
    }
    
    void add(int num) {
        if(num == 0) lastZero = idx;
        if(ans.back() == 0) ans.push_back(num);
        else{
            ans.push_back(ans.back() * num);
        }
        idx++;
    }
    
    int getProduct(int k) {
        if(lastZero >= idx - k){
            return 0;
        }
        if(ans[idx - k -1] == 0) return ans[idx - 1];
        return ans[idx - 1] / ans[idx - k - 1];
    }
};

/*
 * Your ProductOfNumbers object will be instantiated and called as such:
 * ProductOfNumbers* obj = new ProductOfNumbers();
 * obj->add(num);
 * int param_2 = obj->getProduct(k);
 */
