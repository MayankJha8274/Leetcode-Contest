class Solution {
public:
    int minAllOneMultiple(int k) {

        // int times = k ;
        // int number_of_digits = 0 ;
        // int old_reminder = 0 ;

        // while ( times-- ) {

        //     int new_reminder = ( old_reminder * 10 + 1 ) % k ;

        //     number_of_digits++ ;

        //     if ( new_reminder == 0 ) return number_of_digits ;

        //     old_reminder = new_reminder ;

        // }

        // return -1 ;

        int remainder = 0 ;

        for ( int length = 1 ; length <= k ; length++ ) {
            
            // remainder will never exceed k-1 , hence prevent integer overflow
            // total possible integer range = [ 0 , 1 ..... k-1 ]
            remainder = ( remainder * 10 + 1 ) % k ;

            if ( remainder == 0 ) return length ;

        }

        return -1 ;

        // T.C = O(K)
        // S.C = O(1)
        
    }
};