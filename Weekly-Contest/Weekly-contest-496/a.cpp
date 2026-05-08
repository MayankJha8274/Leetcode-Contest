class Solution {
public:
    int mirrorFrequency(string s) {

        unordered_map<char,int> mpp ;

        for ( auto it : s ) mpp[it]++ ;

        int sum = 0 ;

        unordered_map<char,int> diff_mpp ;

        for ( auto it : mpp ) {

            char org = it.first ;

            char mirr ;

            if ( org >= '0' && org <= '9' ) {

                mirr = '9' - ( org - '0' ) ;
                
            }

            else mirr = 'z' - ( org - 'a' ) ;

           // int diff = abs( mirr - org ) ;

           // if ( mpp.find(diff) != mpp.end() ) continue ;

           // else {

            if ( org > mirr && mpp.find(mirr) != mpp.end() ) continue ;

              //  mpp[diff]++ ;

            int f1 = mpp[org] ;
            int f2 = (mpp.find(mirr) != mpp.end()) ? mpp[mirr] : 0 ;

                sum += abs( f1 - f2 ) ;
                
           // }
        }

        return sum ;
        
    }
};