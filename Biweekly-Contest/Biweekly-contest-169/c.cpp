class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size() ;

        vector<int> pre(n,1) , suff(n,1) ;

        for ( int i = 1 ; i < n ; i++ ) {

            if ( nums[i] >= nums[i-1] ) pre[i] = pre[i-1] + 1 ;

        }

        for ( int i = n-2 ; i >= 0 ; i-- ) {

            if ( nums[i] <= nums[i+1] ) suff[i] = suff[i+1] + 1 ;

        }

        int maxi = 1 ;

        for ( int i = 0 ; i < n ; i++ ) {

            maxi = max( maxi , pre[i]+1 ) ;
            maxi = max( maxi , suff[i]+1 ) ;

            if ( i > 0 && i < n-1 && nums[i-1] <= nums[i+1] ) 
            maxi = max( maxi , pre[i-1] + 1 + suff[i+1] ) ;

        }

        return min( n , maxi ) ;

        // T.C. : O(N)
        // S.C. : O(N)
        
    }
};