class Solution {
public:
    vector<int> limitOccurrences(vector<int>& nums, int k) {

        int n = nums.size() ;

        // map<int,int> mpp ;

        // for ( auto it : nums ) mpp[it]++ ;

        // vector<int> ans ;

        // for ( auto it : mpp ) {

        //     int times = min( k , it.second ) ;

        //     while( times-- ) ans.push_back( it.first ) ;

        // }

        vector<int> ans ;

        int cnt = 1 ;

        ans.push_back( nums[0] ) ;

        for ( int i = 1 ; i < n ; i++ ) {

            if ( nums[i] == nums[i-1] && cnt < k ) {

                ans.push_back( nums[i] ) ;
                cnt++ ;

            }

            else if ( nums[i] == nums[i-1] && cnt >= k ) continue ;

            else {
                
                ans.push_back( nums[i] ) ;
                cnt = 1 ;

            }

        }

        return ans ;
        
    }
};