class Solution {
public:
    bool isPrime( int n ) {

        if ( n <= 1 ) return false ;

        for ( int i = 2 ; i * i <= n ; i++ ) {

            if ( n % i == 0 ) return false ;
            
        }

        return true ;
        
    }

    int sumOfPrimesInRange(int n) {

        int num = n ;

        int ans = 0 ;

        while ( num ) {

            int dig = num % 10 ;
            ans = ans * 10 + dig ;
            num /= 10 ;
            
        }

        int range1 = min( n , ans ) ;
        int range2 = max( n , ans ) ;

        int sum = 0 ;

        for ( int i = range1 ; i <= range2 ; i++ ) {

            if ( isPrime(i) ) sum += i ;
            
        }

        return sum ;
        
    }
};