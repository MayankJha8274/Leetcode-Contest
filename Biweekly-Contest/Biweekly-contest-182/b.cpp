class Solution {
public:
    int minFlips(string s) {

        int ones = 0 ;
        int zeros = 0 ;

        int n = s.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( s[i] == '0' ) zeros++ ;

            else ones++ ;

        }

        int ans = n ;

        // case 1 : converting to all zeros ( 00000 )
        ans = min( ans , ones ) ;

        // case 2 : converting to all ones ( 111111 ) 
        ans = min( ans , zeros ) ;

        // case 3 : converting to only 1 ones ( 00010000 )
        ans = min( ans , abs( ones - 1 ) ) ;

        // case 4 : converting to string 10000001
        int cost = 0 ;

        if ( n > 1 ) {

            if ( s[0] == '0' ) cost++ ;

            if ( s[n-1] == '0' ) cost++ ;

            for ( int i = 1 ; i < n-1 ; i++ ) {

                if ( s[i] == '1' ) cost ++ ;

            }

        }

        return min( ans , cost ) ;
        
    }
};