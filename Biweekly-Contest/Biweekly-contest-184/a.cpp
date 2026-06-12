class Solution {
public:
    bool consecutiveSetBits(int n) {

        // vector<int> ans ;

        // while ( n ) {

        //     int rem = n % 2 ;
        //     ans.push_back( rem ) ;
        //     n = n / 2 ;
            
        // }

        // int cnt = 0 ;

        // for ( int i = 1 ; i < ans.size() ; i++ ) {

        //     if ( ans[i] == 1 && ans[i-1] == 1 ) cnt++ ;
            
        // }

        // return cnt == 1 ;

        bitset<32> b( n ) ;

        int cnt = 0 ;

        for ( int i = 1 ; i < b.size() ; i++ ) {

            if ( b[i] == 1 && b[i-1] == 1 ) cnt++ ;

        }

        return cnt == 1 ;
        
    }
};