class Solution {
public:
    bool canMakeSubsequence(string s, string t) {

        int n = s.size() ;
        int m = t.size() ;

        if ( n > m ) return false ;

        int p = 0 ;

        // prefix + 1 character modification + suffix

        vector<int> prefix(n,-1) , suffix(n,-1) ;
        
        for ( int i = 0 ; i < n ; i++ ) {

            while ( p < m && s[i] != t[p] ) p++ ;

            if ( p == m ) break ;

            prefix[i] = p ;
            p++ ;

        }

        // if s is already a subsequence of t ( no replcament needed ) 
        if ( prefix[n-1] != -1 ) return true ;

        p = m-1 ;

        for ( int i = n-1 ; i >= 0 ; i-- ) {

            while ( p >= 0 && s[i] != t[p] ) p-- ;

            if ( p < 0 ) break ;

            suffix[i] = p ;
            p-- ;

        }

        for ( int i = 0 ; i < n ; i++ ) {

            if ( ( i == 0 || prefix[i-1] != -1 ) && ( i == n-1 || suffix[i+1] != -1 ) ) {

                int L = ( i == 0 ) ? -1 : prefix[i-1] ;
                int R = ( i == n-1 ) ? m : suffix[i+1] ;

                if ( L+1 < R ) return true ;

            }
        }

        return false ;

    }
};