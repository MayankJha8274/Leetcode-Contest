class Solution {
public:
    int countValidPrefixes(string s) {

        int maxi = 0 ;
        int zero = 0 , one = 0 ;

        for ( int i = 0 ; i < s.size() ; i++ ) {

            if ( s[i] == '0' ) zero++ ;

            else one++ ;

            if ( abs(zero-one) <= 1 ) maxi++ ;

        }

        return maxi ;
        
    }
};