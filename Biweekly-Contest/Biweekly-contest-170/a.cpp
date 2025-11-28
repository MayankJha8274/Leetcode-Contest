// all three methods we listed are to convert an integer n into its binary representation without leading zeros.

/*
class Solution {
public:
    int minimumFlips(int n) {

        bitset<32> b(n); // b = now contains 32 bit binary representation of n( with leading 0)

        string ans = b.to_string();
        int pos = ans.find('1');
        ans = ans.substr(pos); // b = now contains binary representation of n( without leading 0 starting from 1)

        string rev = ans ;
        reverse( rev.begin() , rev.end() ) ;

        int i = 0 ;
        int j = 0 ;
        int size = ans.size() ;

        int cnt = 0 ;

        while ( i < size && j < size ) {

            int final = rev[i] ^ ans[j] ;

            if ( final == 1 ) cnt++ ;

            i++;
            j++;
            
        }

        return cnt ;

        // T.C , S.C = O(32) = O(1)
        
    }
};

*/

/*
class Solution {
public:
    int minimumFlips(int n) {

        string ans = "" ;

        while ( n > 0 ) {

            ans += ( n % 2 ) ;
            n /= 2 ;

        }

        string rev = ans ;

        reverse( rev.begin() , rev.end() ) ;

        int i = 0 ;
        int j = 0 ;
        int size = ans.size() ;

        int cnt = 0 ;

        while ( i < size && j < size ) {

            int final = rev[i] ^ ans[j] ;

            if ( final == 1 ) cnt++ ;

            i++;
            j++;
            
        }

        return cnt ;

        // T.C , S.C = O(32) = O(1)
        
    }
};
*/

class Solution {
public:
    int minimumFlips(int n) {

        vector<int> ans ;

        bool started = false ;

        for ( int i = 31 ; i >= 0 ; i-- ) {
            
            // right shift by i  = divides by 2 raised to power i 
            int bit = ( n >> i ) & 1 ;

            if ( bit == 1 ) started = true ;

            if ( started ) ans.push_back(bit) ;
            
        }

        vector<int> rev = ans ;
        reverse( rev.begin() , rev.end() ) ;

        int i = 0 ;
        int j = 0 ;
        int size = ans.size() ;

        int cnt = 0 ;

        while ( i < size && j < size ) {

            int final = rev[i] ^ ans[j] ;

            if ( final == 1 ) cnt++ ;

            i++;
            j++;
            
        }

        return cnt ;
        
        // T.C , S.C = O(1) 

    }
};