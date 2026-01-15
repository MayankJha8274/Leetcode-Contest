class Solution {
public:
    int centeredSubarrays(vector<int>& nums) {

        int n = nums.size() ;
        int cnt = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            unordered_map<int,int> mpp ;
            long long sum = 0 ;

            for ( int j = i ; j < n ; j++ ) {

                mpp[nums[j]]++ ;
                sum += nums[j] ;

                if ( mpp.find(sum) != mpp.end() ) cnt++ ;

            }
        }

        return cnt ;
        
    }
};