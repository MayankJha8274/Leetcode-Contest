class Solution {
public:
    long long minMoves(vector<int>& balance) {

        typedef long long ll ;

        int culprit_idx = -1 ;
        ll sum = 0 ;

        int n = balance.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            sum += balance[i] ;

            if ( balance[i] < 0 ) culprit_idx = i ;

        }

        if ( sum < 0 ) return -1 ;

        if ( culprit_idx == -1 ) return 0 ;

        ll moves = 0 ;
        int distance = 1 ;

        while ( balance[culprit_idx] < 0 ) {
            
            // circular array mai left and right index find krne ka tarika
            int left = ( culprit_idx - distance + n ) % n ;
            int right = ( culprit_idx + distance ) % n ;

            ll needed = balance[left] + balance[right] ;

            ll taken = min( needed , -(ll)balance[culprit_idx ]);

            balance[culprit_idx] += taken ;

            moves += ( distance * taken) ;
            distance++ ;

        }

        return moves ;
        
    }
};