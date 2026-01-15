class Solution {
public:
    int residuePrefixes(string s) {

        int cnt = 0 ;

        int n = s.size() ;

        unordered_map<char,int> mpp ;

        for ( int i = 0 ; i < n ; i++ ) {

            mpp[s[i]]++ ;

            if ( mpp.size() == (i + 1) % 3 ) cnt++ ;
            
        }

        if ( cnt == 0 ) return -1 ;

        return cnt ;
        
    }
};