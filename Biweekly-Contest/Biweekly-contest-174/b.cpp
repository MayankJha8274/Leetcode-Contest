class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& target) {

        unordered_map<int,int> mpp ;

        int cnt = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            if ( nums[i] != target[i] && mpp.find(nums[i]) == mpp.end()) {

                cnt++ ;
                mpp[nums[i]]++ ;
                
            }
        }

        return cnt ;
        
    }
};