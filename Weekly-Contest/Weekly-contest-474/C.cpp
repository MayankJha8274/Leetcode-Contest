class Solution {
public:
    long long minimumTime(vector<int>& d, vector<int>& r) {
        
        using ll = long long ;

        ll start = 1 ;
        ll end = 1e15 ;
        ll ans = 1e15 ;

        while ( start <= end ) {

            ll mid = ( start + end ) / 2 ;

            ll d01 = mid - ( mid / lcm( r[0] , r[1] ) ) ;
            ll d0 = mid - mid/r[0] ;
            ll d1 = mid - mid/r[1] ;

            if ( d[0] + d[1] <= d01 && d[0] <= d0 && d[1] <= d1 ) {

                ans = min( ans , mid ) ;
                end = mid - 1 ;

            } 

            else start = mid + 1 ;

        }

        return ans ;

        // T.C = O( LOGN )
        // S.C = O(1)
    }
};