class Solution {
public:
    int minPenalty(int period, vector<int>& lights, vector<int>& arrivalTime) {

        int maxi = *max_element( lights.begin() , lights.end() ) ;

        int ans = 0 ;

        for ( auto it : arrivalTime ) {

            int r = it % period ;

            if ( r < maxi ) continue ;

            ans = max( ans , period - r ) ;

        }

        return ans ;
        
    }
};