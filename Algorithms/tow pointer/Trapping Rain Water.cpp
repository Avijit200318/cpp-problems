// Trapping Rain Water (hard)

// Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6
// Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.
// Example 2:

// Input: height = [4,2,0,3,2,5]
// Output: 9

// class Solution {
// public:
//     int trap(vector<int>& height) {
//         // min(left max height - right max height) - height[i] => for each position is the water ammount
//         int n = height.size();

//         // right array is fill with value to index 0 so that we can edit at any index
//         vector<int> leftMax, rightMax(n, 0);
//         int lMax = INT_MIN, rMax = INT_MIN;

//         for(int i = 0; i< n; i++){
//             lMax = max(lMax, height[i]);
//             leftMax.push_back(lMax);

//             // get right max value then store it to that position (note not 1st then order will reverse)
//             rMax = max(rMax, height[n-1-i]);
//             rightMax[n-1-i] = rMax;
//         }

//         int sum = 0;
//         for(int i = 0; i< n; i++){
//             int a = min(leftMax[i], rightMax[i]) - height[i];
//             if(a > 0){
//                 sum += a;
//             }
//         }
//         return sum;
//     }
// };

class Solution {
public:
    int trap(vector<int>& height) {
        // min(left max height - right max height) - height[i] => for each position is the water ammount
        int n = height.size();

        int left = 0, right = n-1;
        int lMax = height[0], rMax = height[n-1];
        int sum = 0;

        while(left < right){
            if(lMax < rMax){
                //since at the edge no water will store
                left++;
                // update the left max value
                lMax = max(lMax, height[left]);
                sum += (lMax - height[left]) < 0? 0 : lMax - height[left];
            }
            else{
                //since at the edge no water will store
                right--;
                // update the rightMax value
                rMax = max(rMax, height[right]);
                sum += (rMax - height[right]) < 0? 0 : rMax - height[right];
            }
        }
        return sum;
    }
};