class Solution {
public:
    string maxSumOfSquares(int num, int sum) {

        if ( sum > 9 * num ) return "" ;

        string ans( num , '0' ) ;

        for ( int i = 0 ; i < num; i++ ) {

            if ( sum < 9 ) {

                ans[i] = '0' + sum ;
                break ;

            }

            else {

                ans[i] = '9' ;
                sum -= 9 ;

            }
        }

        return ans ;

        // T.C = O( N )
        // S.C = O( 1 )
        
    }

};
