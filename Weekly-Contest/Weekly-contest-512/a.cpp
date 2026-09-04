class Solution {
public:
    int largestInteger(int n, int s) {

        // int sum = 0 ;
        int maxi = -1 ;

        for ( int i = 0 ; i <= 99999 ; i++ ) {

            int cnt = 0 ;
            int sum = 0 ;

            int num = i ;

            while ( num ) {

                int dig = num%10 ;
                cnt++ ;
                num = num/10 ;
                sum += dig ;
                
            }

            if ( cnt <= n && sum == s ) maxi = max( i , maxi ) ;
            
        }

        return maxi ;
        
    }
};