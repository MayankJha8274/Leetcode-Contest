class Solution {
private:
    bool solve( int num ) {

        bitset<32> b( num ) ;

        string s = b.to_string() ;
        int pos = s.find('1') ;
        s = s.substr( pos ) ;

        reverse( s.begin() , s.end() ) ;

        for ( int i = 0 ; i < s.size() / 2 ; i++ ) {

            if ( s[i] != s[s.size()-1-i] ) return false ;

        }

        return true ;

    }
public:
    vector<int> minOperations(vector<int>& nums) {
        
        vector<int> ans ;

        for ( auto it : nums ) {

            for ( int i = 0 ; i < 5000 ; i++ ) {

                if ( solve( it - i ) || solve( it + i ) ) {

                    ans.push_back(i) ;
                    break ;

                }
            }
        }

        return ans ;

        // T.C , S.C = O( N )

    }
};