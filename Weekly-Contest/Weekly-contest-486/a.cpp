class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {

        int cnt = 0 ;
        
        for ( int i = 1 ; i < nums.size() ; i++ ) {

            if ( nums[i] <= nums[i-1] ) {

                cnt = i ;
                
            }
            
        }

        return cnt ;
        
    }
};