// PREFIX SUM + BS
class Solution {
public:
    long long totalScore(int hp, vector<int>& damage, vector<int>& requirement) {
        
        int n = damage.size() ;

        vector<int> prefix( n+1 , 0 ) ;

        prefix[0] = 0 ;

        for ( int i = 1 ; i <= n ; i++ ) {

            prefix[i] = prefix[i-1] + damage[i-1] ;

        }

        long long score = 0 ;

        for ( int i = 1 ; i <= n ; i++ ) {

           // needed = hp - ( d[i] + d[i+1] ..... + d[j] ) >= requirement[j]
           // needed = hp - ( prefix[j] - prefix[i-1] ) >= requirement[j]
           // needed = prefix[i-1] >= requirement[j] - hp + prefix[j]

           // prefix array is always sorted so we can apply BS on it

           long long needed = requirement[i-1] - hp + prefix[i] ;
            
           int idx = lower_bound( prefix.begin() , prefix.begin() + i , needed ) 
                     - prefix.begin() ;

           if ( idx >= i ) continue ;

           score += ( i - idx ) ;

        }

        return score ;

    }
};