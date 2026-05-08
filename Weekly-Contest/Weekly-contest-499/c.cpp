class Solution {
public:
    long long minOperations(vector<int>& nums) {

        typedef long long ll ;

        int n = nums.size() ;

        ll ans = 0 ;

        for ( int i = 1 ; i < n ; i++ ) {

            int dif = nums[i-1] - nums[i] ;

            if ( dif < 0 ) continue ;

            ans += dif ;

        }
        
        return ans ;

    }
};