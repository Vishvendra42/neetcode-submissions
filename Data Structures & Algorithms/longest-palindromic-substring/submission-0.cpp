class Solution {
public:
    string longestPalindrome(string s) {
        int n =s.size();


        //odd
        int maxlen =0;
        string ans="";
        for( int center=0;center<n;center++){
            // center is basically the center of string

            int left=center;
            int right =center;

            while(  left>=0 && right<n && s[left]==s[right]){
                
                int len = right-left+1;
                if( len>maxlen){
                    maxlen = len;
                    ans = s.substr(left,maxlen);
                }
                left--;
                right++;
            }
        }



        //even

        for( int l=0;l<n-1;l++){
            int left =l;
            int right=l+1;
            
             while(  left>=0 && right<n && s[left]==s[right]){
                
                int len = right-left+1;
                if( len>maxlen){
                    maxlen = len;
                    ans = s.substr(left,maxlen);
                }
                left--;
                right++;
            }

        }

        return  ans;
    }
};
