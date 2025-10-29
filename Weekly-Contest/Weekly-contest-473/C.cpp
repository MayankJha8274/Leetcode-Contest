class Solution {
public:
    long long countStableSubarrays(vector<int>& cap) {

        using ll = long long ;

        int n = cap.size() ;

        vector<ll> prefix(n) ;
        prefix[0] = cap[0] ;

        for ( int i = 1 ; i < n ; i++ ) {

            prefix[i] = prefix[i-1] + cap[i] ;

        }

        map<pair<int,ll> , int>mpp ;

        ll ans = 0 ;

        for ( int i = n-1 ; i >= 0 ; i-- ) {

            ans += mpp[{ cap[i] , prefix[i] + 2 * cap[i] }] ;
            
            if ( i+1 < n ) mpp[{ cap[i+1] , prefix[i+1] }]++ ;

        }
       
       return ans ;

       // T.C = O( NLOGN )
       // S.C = O( N )
        
    }
};