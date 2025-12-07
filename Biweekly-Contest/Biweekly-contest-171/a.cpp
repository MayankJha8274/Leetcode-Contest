class Solution {
private:
//We only test divisors up to √n because any larger divisor would have a smaller paired divisor already checked.
/*
🧠 Intuition Behind √n Optimization

Let’s say n = 36.

Divisor pairs:

Smaller	Larger
1	36
2	18
3	12
4	9
6	6

All divisor pairs cross at 6, which is √36.

If there is a divisor > 6,
its pair < 6 will already be detected.

So checking beyond √n is useless.

This reduces complexity from:

O(n) → checking all numbers
to

O(√n) → much faster
*/
    bool isPrime( string s ) {

        int num = stoll(s) ;

        if ( num <= 1 ) return false ;

        for ( int i = 2 ; i * i <= num ; i++ ) {

            if ( num % i == 0 ) return false ;

        }

        return true ;

    }

public:
    bool completePrime(int num) {

        string s = to_string(num) ;

        for ( int i = 0 ; i < s.size() ; i++ ) {
            
            // substr(a, b) ----> start at index a(start index) ,  b number of characters (length)
            bool prefix = isPrime(s.substr( 0 , i + 1 )) ;
            bool suffix = isPrime(s.substr( s.size() - i - 1 , i + 1 )) ;

            if ( prefix == false || suffix == false ) return false ;

        }

            // Time = n * 2 * O(√num)
            // = O(9 * 2 * 31623)
            // = O(1)   ← constant w.r.t. constraints


        return true ;
        
    }
};