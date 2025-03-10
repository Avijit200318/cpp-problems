#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    vector<int> stringToArray(string s){
        vector<int> ans;

        // string s;
        // getline(cin, s)
        // if we need to get the string using cin then we can just write the above two line.
        stringstream ss(s);

        string s1;

        while(getline(ss, s1, ',')){
            int num = stoi(s1);
            ans.push_back(num);
        }
        return ans;
    }

    vector<int> stringtoArraySpaceSeparated(string s){
        // string s;
        // getline(cin, s)
        // if we need to get the string using cin then we can just write the above two line.
        vector<int> ans;

        stringstream ss(s);
        string s1 = "";

        // this seperate any space ' ' or '        ' is just give us the next value
        while(ss >> s1){
            int num = stoi(s1);
            ans.push_back(num);
        }

        return ans;
    }

    vector<int> stringtoArraySpaceSeparatedUseingGetline(string s){
        // string s;
        // getline(cin, s)
        // if we need to get the string using cin then we can just write the above two line.
        vector<int> ans;

        stringstream ss(s);
        string s1 = "";

        // this only seperate single space ' ' not double
        while(getline(ss, s1, ' ')){
            int num = stoi(s1);
            ans.push_back(num);
        }

        return ans;
    }
};


int main(){
    Solution s;
    // vector<int> a = s.stringToArray("1,2,3,4,5");
    // vector<int> a = s.stringtoArraySpaceSeparated("1 2             3 4 5");
    vector<int> a = s.stringtoArraySpaceSeparatedUseingGetline("1 2 3 4 5");
    cout<<"The answer is: "<<endl;
    for(int i = 0; i< a.size(); i++){
        cout<<a[i]<<" ";
    }
    return 0;
}
