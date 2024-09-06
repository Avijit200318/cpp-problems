
bool isEven(string s,int n)
{
    int dotPos = false;
    for(int i = n-1; i>= 0; i--){
        if(s[i] == '0' && dotPos == false){
            continue;
        }
        
        if(s[i] == '.'){
            dotPos = true;
            continue;
        }
        
        if((s[i] - '0') % 2 == 0){
            return true;
        }
        return false;
    }
}
