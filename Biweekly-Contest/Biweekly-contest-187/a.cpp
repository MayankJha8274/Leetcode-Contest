class Solution {
public:
    string rearrangeString(string s, char x, char y) {

        string ans = "" ;

        int cnt = 0 ;

        for ( int i = 0 ; i < s.size() ; i++ ) {

            char ch = s[i] ;

            if ( ch == x ) {

                cnt++ ;
                continue ;
                
            }

            ans += ch ;
            
        }

        while ( cnt-- ) ans += x ;

        return ans ;
        
    }
};