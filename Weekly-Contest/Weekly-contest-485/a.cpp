class Solution {
public:
    int vowelConsonantScore(string s) {

        int score = 0 ;
        int vo = 0 ;
        int co = 0 ;

        for ( int i = 0 ; i < s.size() ; i++ ) {

            char ch = s[i] ;

            if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
            vo++ ;

            else if ( ch == ' ' || ch == '1' || ch == '2' || ch == '0' || ch == '3'
                    || ch == '4' || ch == '5' || ch == '6' || ch == '7' || ch == '8' 
                    || ch == '9' ) continue ;

            else co++ ;
            
        }

        if ( co > 0 ) score = vo/co ;

        return score ;
        
    }
};