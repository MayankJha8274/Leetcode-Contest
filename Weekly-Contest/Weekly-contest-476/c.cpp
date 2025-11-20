class Solution {
public:
    long long countDistinct(long long n) {

        using ll = long long ;
        
        string s = to_string(n) ;
        int D = s.size() ;

        vector<ll> nine_pow( D+1 , 0 ) ;

        nine_pow[0] = 1 ;

        for ( int i = 1 ; i < D+1 ; i++ ) {

            nine_pow[i] = 1ll * nine_pow[i-1] * 9 ;

        }

        ll ans = 0 ;

        for ( int i = 1 ; i < D ; i++ ) {

            ans += nine_pow[i] ;

        }

        bool hasZero = false ;

        for ( int i = 0 ; i < D ; i++ ) {

            int d = s[i] - '0' ;

            if ( d == 0 ) {

                hasZero = true ;
                break ;

            }

            ans += 1ll * ( d-1 ) * nine_pow[D-i-1] ;

        }

        if( !hasZero ) {
            
            ans++;
            return ans ;

        }

        return ans ;

        // T.C = O( D )
        // S.C = O( D )
        
    }
};