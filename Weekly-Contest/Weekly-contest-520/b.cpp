class Solution {
public:
    long long countIntersectingIntervals(vector<vector<int>>& intervals) {

        sort( intervals.begin() , intervals.end() ) ;

        typedef long long ll ;

        ll cnt = 0 ;
        int n = intervals.size() ;

        for ( int i = 0 ; i < n ; i++ ) {
            
            ll curr_end = intervals[i][1] ;

            int start = i+1 ;
            int end = n-1 ;
            int pos = i ;

            while ( start <= end ) {

                int mid = ( start + end ) >> 1 ;

                if ( intervals[mid][0] <= curr_end ) {

                    pos = mid ;
                    start = mid + 1 ;

                }

                else end = mid - 1 ;

            }

            cnt += ( pos - i ) ;

        }

        return cnt ;
        
    }
};