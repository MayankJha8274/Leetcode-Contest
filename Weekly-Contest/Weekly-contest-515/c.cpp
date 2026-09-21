class Solution {
public:
    int maximumGap(string skill, string station) {

        int n = skill.size() ;
        int m = station.size() ;

        vector<int> left( n , 0 ) ;
        vector<int> right( n , 0 ) ;

        int i = 0 ;
        int j = 0 ;

        // building prefix
        while ( i < n && j < m ) {

            while ( skill[i] != station[j] ) j++ ;

            left[i] = j ;

            i++ ; j++ ;

        }

        i = n-1 ;
        j = m-1 ;

        // building suffix
        while ( i >= 0 && j >= 0 ) {

            while ( skill[i] != station[j] ) j-- ;

            right[i] = j ;

            i-- ; j-- ;

        }

        int ans = 0 ;

        for ( int i = 0 ; i < n-1 ; i++ ) ans = max( ans , right[i+1] - left[i] ) ;

        return ans ;
        
    }
};