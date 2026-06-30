class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {

        // typedef long long ll ;

        // ll ans = 0 ;

        // sort( nums.rbegin() , nums.rend() ) ;

        // int n = nums.size() ;

        // int i = 0 ;

        //     while ( i < n && k != 0 ) {

        //         if ( mul > 0 ) ans += ( 1LL * nums[i] * mul ) ;

        //         else ans += nums[i] ;
                
        //         mul-- ;
        //         k-- ;

        //         i++ ;
                
        //     }

        // return ans ;

        int n = nums.size() ;

        long long ans = 0 ;

        sort( nums.rbegin() , nums.rend() ) ;

        for ( int i = 0 ; i < k ; i++ ) {

            ans += max( 1LL*nums[i] , 1LL*mul*nums[i] ) ;
            mul-- ;

        }

        return ans ;
        
    }
};