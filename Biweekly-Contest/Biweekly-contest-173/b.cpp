class Solution {
public:
    int minLength(vector<int>& nums, int k) {

        unordered_map<int,int> mpp ;
        int n = nums.size() ;

        int sum = 0 ;

        int i = 0 ;
        int j = 0 ;

        int mini_len = INT_MAX ;

        while ( j < n ) {

            mpp[nums[j]]++ ;

            if ( mpp[nums[j]] == 1 ) sum += nums[j] ;

            while ( sum >= k ) {

                mini_len = min( mini_len , j-i+1 ) ;

                mpp[nums[i]]-- ;
                if ( mpp[nums[i]] == 0 ) sum -= nums[i] ;
                i++ ;

            }

            j++ ;

        }

        return mini_len == INT_MAX ? -1 : mini_len ;

    }
};