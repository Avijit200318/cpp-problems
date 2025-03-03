// Greatest Common Divisor of Strings


class Solution {
public:
    bool divisible(int size, int n, int m, string str1, string str2){
        // if substr size can not create str1 or str2 then just return false
        if(n % size != 0 || m % size != 0){
            return false;
        }

        // set the sub string inside the str variable
        string str (str1.begin(), str1.begin() + size);

        // no of times we need to add sub string to generate the actual stirng(str1 and str2)
        int repeat1 = n/size, repeat2 = m / size;

        string s1 = "", s2 = "";
        for(int i = 0; i< repeat1; i++){
            s1 += str;
        }
        if(s1 != str1) return false;
        // after generating string from substring is it equal to str1 or not

        for(int i = 0; i< repeat2; i++){
            s2 += str;
        }
        if(s2 != str2) return false;
        // after generating the second string just check if it equal to str2 or not

        return true;
    }

    string gcdOfStrings(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        if(n < m) return gcdOfStrings(str2, str1);

        // the loop will run till 1 because for 0 there is no substring. we are using the min length of string first then we are reducing the value of size so that we can find maimum length string that can devide the both string.
        for(int i = m; i>= 1; i--){
            if(divisible(i, n, m, str1, str2)){
                return string (str1.begin(), str1.begin()+i);
            }
        }
        return "";
    }
};
