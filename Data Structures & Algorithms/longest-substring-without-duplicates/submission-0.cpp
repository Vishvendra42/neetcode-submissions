class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();

        int i=0,j=0;

        vector<int>count(256,0);
        int length=0;

        while( j<n){
          count[s[j]]++;

          while( count[s[j]] >1){
            count[s[i]]--;
            i++;
          }
           
           length = max( length , j-i+1);
           j++;
        }
        return length;
    }
};
