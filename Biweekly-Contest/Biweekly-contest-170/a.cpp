class Solution {
public:
    int minimumFlips(int n) {

        vector<int> ans ;

        bool started = false ;

        for ( int i = 31 ; i >= 0 ; i-- ) {

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

        // T.C. : O(logN)
        // S.C. : O(logN)
        
    }
};