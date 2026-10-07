/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    bool canAttendMeetings(vector<Interval>& intervals) {
        sort( intervals.begin() ,intervals.end(), []( Interval & a ,Interval &b){
            if( a.start!=b.start)
            return a.start <b.start;

            return a.end < b.end;
        });

        int i=1;
        int last=intervals[0].end;
        int n =intervals.size();

        while( i<n){
            if( intervals[i].start < last ){
                //conflict
                return false;
            }else{
                last = intervals[i].end;
            }
            i++;
        }
        return true;
    }
};
