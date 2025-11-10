class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {

        int cnt = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            unordered_map<int,int> mpp ;

            for ( int j = i ; j < nums.size() ; j++ ) {

                mpp[nums[j]]++ ;

                if ( mpp[target] > (j-i+1)/2 ) cnt++ ;
                
            }
        }

        return cnt ;

        // T.C. : O(N^2)
        // S.C. : O(N)
        
    }
};