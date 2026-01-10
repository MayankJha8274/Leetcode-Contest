class Solution {
public:
    string reversePrefix(string s, int k) {

        // reverse( s.begin() , s.begin() + k ) ;

        for ( int i = 0 ; i < k/2 ; i++ ) {

            swap ( s[i] , s[k-i-1] ) ;

        }

        return s;
        
    }
};