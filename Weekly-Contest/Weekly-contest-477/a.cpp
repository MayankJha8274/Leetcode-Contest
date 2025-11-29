class Solution {
public:
    long long sumAndMultiply(int n) {

        string s = to_string(n) ;
        string k = "" ;

        for ( int i = 0 ; i < s.size() ; i++ ) {

            if ( s[i] != '0' ) k += s[i] ;
            
        }

        if ( k.empty() ) return 0 ;

        long long sum = 0 ;

        for ( auto it : k ) sum += ( it - '0' ) ;

        long long num = stoll(k) ;

        return (long long)sum * num ;

       // return 0 ;

        // T.C = O( D )
        // S.C = O( D )
        
    }
};