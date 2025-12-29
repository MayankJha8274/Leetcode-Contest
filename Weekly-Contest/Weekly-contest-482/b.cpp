class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {

        using ll = long long ;

        // option 1
        ll option1 = 1ll*cost1*need1 + 1ll*cost2*need2 ;

        // option 2
        ll mini = min( need1 , need2 ) ;

        ll option2 = 1ll*mini*costBoth ;
        need1 -= mini ;
        need2 -= mini ;

        if ( need1 != 0 ) {

            int more = min( cost1 , costBoth ) ;
            option2 += ( 1ll*more*need1 ) ;

        }

        if ( need2 != 0 ) {

            int more2 = min( cost2 , costBoth ) ;
            option2 += ( 1ll*more2*need2 ) ;
            
        }

        return min( option1 , option2 ) ;
        
    }
};