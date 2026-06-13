class Solution {
public:
    int passwordStrength(string password) {

        // unordered_map<char,int> mpp ;

        // for ( auto it : password ) mpp[it]++ ;

        // int ans = 0 ;

        // for ( auto ch : mpp ) {

        //     auto it = ch.first ;

        //     if ( it >= 'a' && it <= 'z' ) ans += 1 ;

        //     else if ( it >= 'A' && it <= 'Z' ) ans += 2 ;

        //     else if ( it >= '0' && it <= '9' ) ans += 3 ;

        //     else ans += 5 ;
            
        // }

        // return ans ;

        unordered_set<char> st( password.begin() , password.end() ) ;

        int ans = 0 ;

        for ( auto it : st ) {

            if ( it >= 'a' && it <= 'z' ) ans += 1 ;

            else if ( it >= 'A' && it <= 'Z' ) ans += 2 ;

            else if ( it >= '0' && it <= '9' ) ans += 3 ;

            else ans += 5 ;

        }

        return ans ;
        
    }
};