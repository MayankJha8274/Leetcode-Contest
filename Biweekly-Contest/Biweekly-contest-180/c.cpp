class Solution {
public:
    bool isPrime(int n) {

        if (n <= 1) return false;

        for (int i = 2; i * i <= n; i++) {
            if (n % i == 0) return false;
        }

        return true;
    }
    
    int minOperations(vector<int>& nums) {

        int ops = 0 ;

        int n = nums.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            int num = nums[i] ;

            if ( i % 2 == 0 ) {

                // prime
                if ( num == 1 ) {
                    
                    ops++ ;
                    continue ;

                }
                
                while ( isPrime(num) == false ) {

                    num++ ;
                    ops++ ;
                    
                }
                
            }

            else {

                // not prime
                if ( num == 1 ) continue ;

                while ( isPrime(num) == true ) {

                    num++ ;
                    ops++ ;
                    
                }
                
            }
        }

        return ops ;
        
    }
};