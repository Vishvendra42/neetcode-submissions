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
    int minMeetingRooms(vector<Interval>& intervals) {
        int maxRoom=0;
         int n=intervals.size();
        
         sort( intervals.begin() ,intervals.end(), []( Interval & a ,Interval &b){
            if( a.start!=b.start)
            return a.start <b.start;

            return a.end < b.end;
        });

        priority_queue<int,vector<int>,greater<int>>pq;
       
         int i=0;
         while( i<n ){
            int needed_from = intervals[i].start;
            //empty those whose occupancy not needed till now
            while( !pq.empty() && pq.top() <=needed_from){
                pq.pop();
            }

            if( pq.size() <maxRoom){
                //room empty 
                // pushing till we need
                pq.push( intervals[i].end);

            }else {
                maxRoom++;
                pq.push( intervals[i].end);
            }
            i++;
         }
         return maxRoom;

    


    }
};
