class Solution {
public:
    int countIntersectingIntervals(vector<vector<int>>& intervals) {

        int n = intervals.size() ;
        int cnt = 0 ;
        sort( intervals.begin() , intervals.end() ) ;

        for ( int i = 0 ; i < n-1 ; i++ ) {

            for ( int j = i+1 ; j < n ; j++ ) {

                if ( intervals[i][1] >= intervals[j][0] ) cnt++ ;

            }
        } 

        return cnt ;
        
    }
};