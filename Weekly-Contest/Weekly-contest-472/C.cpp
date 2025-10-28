/*
// approach 1 = brute 
class Solution {

    void solve( string s , vector<string>& ans , int idx ) {

        int n = s.size() ;

        if ( idx == n ) {

            ans.push_back(s) ;
            return ;

        }

        for ( int i = idx ; i < n ; i++ ) {

            swap( s[idx] , s[i] ) ;

            solve( s , ans , idx+1 ) ;

            swap( s[idx] , s[i] ) ;

        }
    }

    vector<string> permute(string s) {

        vector<string> ans ;
        int index = 0 ;
        solve ( s , ans , index ) ;
        return ans ;

        // T.C O( N factorial )
    }

public:
    string lexGreaterPermutation(string s, string target) {

        vector<string> all = permute(s);

        sort(all.begin(), all.end());

        for (auto perm : all) {

            if (perm > target)
                return perm;

        }

        return "";
        
    }
};

*/

class Solution {
public:
    string lexGreaterPermutation(string s, string t) {

        multiset<char> st ;

        for ( auto it : s ) st.insert(it) ;

        vector<string> ans ;
        string prefix = "" ;

        for ( int i =0 ; i < s.size() ; i++ ) {

            char ch = t[i] ;

            auto gt = st.upper_bound(t[i]) ;

            if ( gt != st.end() ) {

                char val = *gt ;

                string temp = prefix ;
                temp.push_back( val ) ;
                st.erase( st.find(val) ) ;

                for ( auto it : st ) temp.push_back( it ) ;

                st.insert( val ) ;
                ans.push_back( temp ) ;

            }

                auto next = st.find(t[i]) ;

                if ( next == st.end() ) break ;

                prefix.push_back(*next) ;
                st.erase( next ) ;

        }

        if ( ans.size() == 0 ) return "" ;

        return *min_element( ans.begin() , ans.end() ) ;
        
    }
};



