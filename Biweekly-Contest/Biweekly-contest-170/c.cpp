class Solution {
public:
    vector<int> lexSmallestNegatedPerm(int n, long long target) {

        using ll = long long ;

        ll sum = 1ll * n * ( n + 1 ) / 2 ;

        ll pos = 0 ;
        ll neg = 0 ;

        pos = ( sum + target ) / 2 ;

        neg = sum - pos ;

        // not exists any pair
        if ( target > sum || target < -sum ) return {} ;

        if ( ( sum + target) % 2 == 1 ) return {} ;

        int left = 0 ;
        int right = n-1 ;

        vector<int> ans( n ) ;

        for ( int i = n ; i > 0 ; i-- ) {

            if ( neg >= i ) {

                neg -= i ;
                ans[left] = -i ;
                left++ ;

            }

            else {

                ans[right] = i ;
                right-- ;

            }
        }

        return ans ;

        // T.C. : O(N)
        // S.C. : O(1)
        
    }
};