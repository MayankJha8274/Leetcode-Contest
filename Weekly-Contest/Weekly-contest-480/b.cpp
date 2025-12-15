class Solution {
private:
    int check( string s ) {

        int cnt = 0 ;

        for ( int i = 0 ; i < s.size() ; i++ ) {

            char ch = s[i] ;

            if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )  cnt++ ;
            
        }

        return cnt ;
        
    }
public:
    string reverseWords(string s) {

        vector<string> word ;

        string temp = "" ;

        for ( auto it : s ) {

            if ( it == ' ' ) {

                word.push_back(temp) ;
                temp.clear() ;
            
            }

             else {

                 temp += it ;
                 
             }
        }

        word.push_back( temp ) ;

        int cnt = check(word[0]) ;

        for ( int i = 1 ; i < word.size() ; i++ ) {

            if ( check(word[i]) == cnt ) reverse( word[i].begin() , word[i].end() ) ;
            
        }

        string ans = "" ;

        for ( int i = 0 ; i < word.size() ; i++ ) {

            if ( i > 0 ) ans += " " ;

            ans += word[i] ;
            
        }

        return ans ;
        
    }
};