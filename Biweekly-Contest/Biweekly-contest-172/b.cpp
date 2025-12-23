class Solution {
public:
    int maximumSum(vector<int>& nums) {

        using ll = long long ;

        ll sum1 = 0 ;
        ll sum2 = 0 ;
        ll sum3 = 0 ;
        ll sum4 = 0 ;

        vector<int> case0 ; // mod 0
        vector<int> case1 ; // mod 1
        vector<int> case2 ; // mod 2

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            if ( nums[i] % 3 == 0 ) case0.push_back(nums[i]) ;

            else if ( nums[i] % 3 == 1 ) case1.push_back(nums[i]) ;

            else case2.push_back(nums[i]) ;
            
        }

        sort( case0.rbegin() , case0.rend() ) ;
        sort( case1.rbegin() , case1.rend() ) ;
        sort( case2.rbegin() , case2.rend() ) ;

        // 0 , 0 , 0
        if ( case0.size() >= 3 ) sum1 = (ll)case0[0] + case0[1] + case0[2] ;

        // 1 , 1 , 1
        if ( case1.size() >= 3 ) sum2 = (ll)case1[0] + case1[1] + case1[2] ;

        // 2 , 2 , 2
        if ( case2.size() >= 3 ) sum3 = (ll)case2[0] + case2[1] + case2[2] ;

        // 0 , 1 , 2
        if ( case0.size() >= 1 && case1.size() >= 1 && case2.size() >= 1 ) 
            sum4 = (ll)case0[0] + case1[0] + case2[0] ;

        return max({sum1 , sum2 , sum3 , sum4}) ;
        
    }
};