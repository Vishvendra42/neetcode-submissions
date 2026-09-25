class Solution {
public:
    bool isPalindrome(string s) {
        string str="";
        for(auto &it:s){
            if(isalnum(it)){

                str+=tolower(it);
            }
        }
    
    
        int n =str.size();
        int limit =n/2;
        int i=0;
        int j =n-1;
        while( limit>0){
            if( str[i]!=str[j])return false;
            i++;
            j--;
            limit--;
        }
        return true;
    }
};
