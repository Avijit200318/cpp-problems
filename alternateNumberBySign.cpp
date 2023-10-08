// same as the rearrange number by sign but input = [1,2, -4, -5, 3,6]. output = [1, -4, 2, -5, 3, 6]. in case where the number of + and - are not same.
#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    vector <int> alternateNumberBySign(vector <int> arr)
    {
        vector <int> pos, neg;
        for(auto it : arr)
        {
            if(it < 0)
            {
                neg.push_back(it);
            }
            else{
                pos.push_back(it);
            }
        }

        if(pos.size() > neg.size())
        {
            for(int i = 0; i< neg.size(); i++)
            {
                arr[2*i] = pos[i];
                arr[2*i + 1] = neg[i];
            }
            int index = neg.size() *2;
            for(int i = neg.size(); i< pos.size(); i++)
            {
                arr[index] = pos[i];
                index++;
            }
        }
        else{
           for(int i = 0; i< pos.size(); i++)
            {
                arr[2*i] = pos[i];
                arr[2*i + 1] = pos[i];
            }
            int index = pos.size() *2;
            for(int i = pos.size(); i< neg.size(); i++)
            {
                arr[index] = neg[i];
                index++;
            } 
        }
        return arr;
    }
};

// the time complexity of this code is o(n)+o(pos)+o(neg) = o(2n).

int main()
{
    vector <int> v = {1,2, -4, -5, 3, 6};
    Solution s;
    vector <int> a = s.alternateNumberBySign(v);
    for(auto it : a)
    {
        cout<< it << " ";
    }
    return 0;
}