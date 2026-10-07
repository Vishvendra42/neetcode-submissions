class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        
        sort( intervals.begin() ,intervals.end());

       int last= intervals[0][1];
        int i=1;
        int n =intervals.size();
        int count=0;
        while( i<n ){
            if( intervals[i][0] < last){
                //overlappint
                count++;
                 last = min( last ,intervals[i][1]);
                i++;
            }
            else{ 
                  last =intervals[i][1];
                  i++;
            }
            
        }
        return count;
    }
};
