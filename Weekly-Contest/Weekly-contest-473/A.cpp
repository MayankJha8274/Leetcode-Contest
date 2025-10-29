class Solution {
public:
    long long removeZeros(long long n) {

       /* long long ans = 0 ;
        long long place = 1 ;

        while ( n > 0 ) {

            int dig = n % 10 ;

            if ( dig != 0 ) {

                ans += dig * place ;
                place *= 10 ;
                
            }

            n /= 10 ;
            
        }

        // T.C = O(D)
        // S.C = O(1)

        return ans ; */

        string s = to_string(n) ;
        string ans = "" ;

        for ( auto it : s ) {

            if ( it != '0' ) ans += it ;

        }
        
        return stoll(ans) ;

        // T.C = O(D)
        // S.C = O(D)
        
    }
};