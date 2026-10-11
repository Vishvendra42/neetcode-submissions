class Solution {
public:
    int countSubstrings(string s) {
        int n =s.size();
        //odd
        int count =0;
        
        for( int center=0;center<n;center++){
            // center is basically the center of string

            int left=center;
            int right =center;

            while(  left>=0 && right<n && s[left]==s[right]){
                
                count++;
                left--;
                right++;
            }
        }



        //even

        for( int l=0;l<n-1;l++){
            int left =l;
            int right=l+1;
            
             while(  left>=0 && right<n && s[left]==s[right]){
               count++;
                left--;
                right++;
            }

        }

        return  count;
    }
};
