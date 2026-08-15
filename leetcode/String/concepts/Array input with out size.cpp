#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    cout<<"write something"<<endl;
    string s;

    getline(cin, s);
    stringstream ss(s);
    

    vector<int> arr;
    int num;

    while(ss >> num){
        arr.push_back(num);
    }

    cout<<"array output is ";
    for(int i = 0; i< arr.size(); i++){
        cout<< arr[i]<<" ";
    }

    return 0;
}




// if coma separeted values
// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

int main() {
    // Write C++ code here
    cout<<"write something"<<endl;
    cout<<"In case of coma separeted values: 1,2,3,4"<<endl;
    string s;

    getline(cin, s);
    stringstream ss(s);

    vector<int> arr;
    // int num;
    string temp;

    while(getline(ss, temp, ',')){
        int num = stoi(temp);
        arr.push_back(num);
    }

    cout<<"array output is ";
    for(int i = 0; i< arr.size(); i++){
        cout<< arr[i]<<" ";
    }

    return 0;
}
