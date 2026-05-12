class Solution {
public:

    bool isLetter( char ch ) {

        return ( ch >= 'a' && ch <= 'z' ) ;

    }

    vector<int> countWordOccurrences(vector<string>& chunks, vector<string>& queries) {

        string s= "" ;

        for ( auto it : chunks ) s += it ;

        int n = s.size() ;

        int i = 0 ;

        unordered_map<string,int> mpp ;

        while ( i < n ) {

            string word = "" ;

            while ( i < n ) {

            // word
            if ( isLetter(s[i]) ) {

                word += s[i] ;
                i++ ;

            }

            // valid hypen
            else if ( s[i] == '-' ) {

                // checking validity of seprator
                bool left = !word.empty() ;

                bool right = ( i + 1 < n && isLetter(s[i+1]) ) ;

                if ( left && right ) {

                    word += s[i] ;
                    i++ ;

                }

                else break ;

            }

            // spaces
            else break ;

            }

            mpp [word]++ ;
            
            if ( i < n ) i++ ;

        }

        vector<int> ans ;

        for ( auto it : queries ) ans.push_back( mpp[it] ) ;

        return ans ; 
        
    }
};