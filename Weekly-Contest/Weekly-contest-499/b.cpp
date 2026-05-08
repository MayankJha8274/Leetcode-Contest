class Solution {
public:
    bool check( char ch ) {

        if ( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
            return true ;

        return false ;
        
    }
    
    string sortVowels(string s) {

        int n = s.size() ;

        map<char,int> freq ;
        map<char,int> firstPos ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( check(s[i]) ) {

                freq[s[i]]++ ;
                if ( !firstPos.count(s[i]) ) firstPos[s[i]] = i ;
                
            }
            
        }

        vector<pair<char,int>> mpp(freq.begin(), freq.end());
        
        sort(mpp.begin(), mpp.end(), [&](auto& a, auto& b) { 
            if (a.second != b.second) return a.second > b.second;  
            return firstPos[a.first] < firstPos[b.first];  
        });

        int i = 0 ;

        for ( auto it : mpp ) {

            char word = it.first ;
            int cnt = it.second ;

            // if ( check(s[i]) == false ) {

            //     i++ ;
            //     continue ;
                
            // }

            // else {

                while ( cnt ) {

                    if ( check(s[i]) ) {

                        s[i] = word ;
                        i++ ;
                        cnt-- ;
                        
                    }

                    else i++ ;
                    
                }
            //}

            
        }

        return s ;
        
    }
};