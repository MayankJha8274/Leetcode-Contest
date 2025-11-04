class Solution {
public:
    long long maxProduct(vector<int>& nums) {

        long long ans = 1 ;

        int n = nums.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] < 0 ) nums[i] = abs(nums[i]) ;
            
        }

        sort( nums.rbegin() , nums.rend() ) ;

        ans = 1LL*nums[0] * nums[1] ;

        if ( ans < 0 )  ans *= -100000 ;
 
        else ans *= 100000 ;

        return ans ;

        // T.C = O(NLOGN)
        // S.C = O(1)
        
    }
};