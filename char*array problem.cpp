#include<bits/stdc++.h>
using namespace std;

class Solution{
    public:
    const char* helper(const char* input){
        int n = strlen(input);
        string s = "";
        for(int i = 0; i< n; i++){
            s += input[i];
        }
        int sum = stoi(s);
        cout<<sum<<endl;
        for(int i = n-1; i > 0; i--){
            sum += stoi(s.substr(0, i));
            sum += stoi(s.substr(i, n));
        }
        cout<<sum<<endl;
        for(int i = 0; i< n; i++){
            sum += s[i] - '0';
        }
        cout<< sum;
        string res = to_string(sum);
        return res.c_str();
    }
};

int main(){
    // const char* a = "125";
    // 176
    const char* a = "111";
    // 138
    // const char* a = "1234";
    // ?
    
    // int size = sizeof(a) / sizeof(a[0]);
    // it return the size is 4. because it also add the null charecter.
    // cout<< "the array size is"<< strlen(a);
    // in this case strlen is used it gives me the value of 3.
    Solution s;
    const char* arr = s.helper(a);

    return 0;
}
