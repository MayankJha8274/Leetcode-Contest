class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {

        int n = nums.size() ;

        sort( nums.rbegin() , nums.rend() ) ;

        long long ans = nums[0] + nums[1] - nums[n-1] ;

        return ans ;

        // T.C = O( N log N )
        // S.C = O( 1 )
        
    }
};