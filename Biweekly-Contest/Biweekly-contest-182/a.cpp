class Solution {
public:
    vector<int> scoreValidator(vector<string>& events) {

        int n = events.size() ;

        int cnt = 0 ;
        int score = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            auto ch = events[i] ;

            if ( cnt == 10 ) break ;

            if ( ch == "0" || ch == "1" || ch == "2" || ch == "3" ||
               ch == "4" || ch == "6" ) score += stoi(ch) ;

            if ( ch == "WD" ) score++ ;

            if ( ch == "NB" ) score++ ;

            if ( ch == "W" ) cnt++ ;
            
        }

        return { score , cnt } ;
        
    }
};