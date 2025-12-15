class Solution {
public:
    int absDifference(vector<int>& nums, int k) {

        sort( nums.begin() , nums.end() ) ;

        long long sum = 0 ;
        long long sum2 = 0 ;

        for ( int i = 0 ; i < k ; i++ ) sum += nums[i] ;

        sort( nums.rbegin() , nums.rend() ) ;

        for ( int i = 0 ; i < k ; i++ ) sum2 += nums[i] ;

        return abs( sum - sum2 ) ;
        
    }
};