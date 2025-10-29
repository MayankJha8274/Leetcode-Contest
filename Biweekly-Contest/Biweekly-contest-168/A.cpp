/*class Solution {
public:
    string lexSmallest(string s) {

        vector<string> ans ;

        for ( int i = 0 ; i < s.length() ; i++ ) {

            string temp = s;
            reverse( temp.begin() , temp.begin() + i ) ;
            ans.push_back(temp) ;

            temp = s;
            reverse( temp.end() - i - 1 , temp.end() ) ;
            ans.push_back(temp) ;

        }

        sort( ans.begin() , ans.end() ) ;

        return ans[0] ;
        
    }
};
*/

//optimal
class Solution {
public:
    string lexSmallest(string s) {

        string ans = s ;

        for ( int i = 0 ; i < s.length() ; i++ ) {

            string temp = s;
            reverse( temp.begin() , temp.begin() + i ) ;
            ans = min( ans , temp ) ;

            temp = s;
            reverse( temp.end() - i - 1 , temp.end() ) ;
            ans = min( ans , temp ) ;

        }

        return ans ;
        
    }
};