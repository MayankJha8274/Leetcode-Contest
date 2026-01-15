class Solution {
public:
    string fn( string& s ) {

        int pos = s[0] - 'a' ;

        string newbe = "" ;

        for ( int i = 0 ; i < s.size() ; i++ ) {

            newbe += ( s[i] - pos + 26 ) % 26 ;

        }

        return newbe ;

    }
    
    long long countPairs(vector<string>& words) {

        long long cnt = 0 ;
        unordered_map<string,int> mpp ;

        for ( auto it : words ) {

            string s = fn( it ) ;
            mpp[s]++ ;

        }

        for ( auto it : mpp ) {

            cnt += 1ll * it.second * ( 1ll * it.second - 1 ) / 2 ;

        }

        return cnt ;

        // T.C = O( N ) * 26 
        // S.C = O( 1 )
        
    }
};