class Solution {
public:
    int minMoves(vector<int>& nums) {

        int ans = 0 ;

        int maxi = *max_element( nums.begin() , nums.end() ) ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            ans += abs( maxi - nums[i] ) ;
            
        }

        return ans ;

        // T.C. : O(N)
        // S.C. : O(1)
        
    }
};