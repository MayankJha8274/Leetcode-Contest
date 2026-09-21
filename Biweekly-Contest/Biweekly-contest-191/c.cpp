class Solution {
public:
    int minDays(int n) {

        vector<int> dp( n+1 , 1e9 ) ;

        // base case
        dp[0] = 0 ;
        dp[1] = 1 ;

        for ( int score = 2 ; score <= n ; score++ ) {

            long long sum = 0 ;

            for ( int k = 1 ; k <= score ; k++ ) {

                sum += k ;

                if ( sum > score ) break ;

                int remaining = score - sum ;

                if ( remaining == 0 ) dp[score] = min( dp[score] , k ) ;

                else if ( dp[remaining] != 1e9 ) dp[score] = min( dp[score] , dp[remaining] + 1 + k ) ;

            }
        }
        
        return dp[n] ;

    }
};