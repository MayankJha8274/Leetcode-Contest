class Solution {
public:
    long long minEnergy(int n, int brightness, vector<vector<int>>& intervals) {

        sort( intervals.begin() , intervals.end() ) ;

        typedef long long ll ;

       // ll bright = ceil( (double)brightness / 3 ) ;
        ll bright = ( brightness + 2 ) / 3 ;

        int start = intervals[0][0] ;
        int end = intervals[0][1] ;

        int v = intervals.size() ;

        ll length = 0 ;

        for ( int i = 1 ; i < intervals.size() ; i++ ) {

            if ( intervals[i][0] <= end ) end = max( end , intervals[i][1] ) ;

            else {
            
                length += 1ll * ( end - start + 1 ) ;

                start = intervals[i][0] ;
                end = intervals[i][1] ;

            }

        }
        
        length += 1LL * ( end - start + 1 ) ;

        ll ans = 1LL * bright * length ;

        return ans ;
        
    }
};