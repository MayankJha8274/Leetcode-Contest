class Solution {
public:
    bool validDigit(int n, int x) {

        string str = to_string(n) ;

        for ( int i = 0 ; i < str.size() ; i++ ) {

            if ( i == 0 && str[i]-'0' == x ) return false ;

            if ( str[i]-'0' == x ) return true ;
            
        }

        return false ;
        
    }
};