class Solution {
public:
    long long maximumScore(vector<int>& nums) {

        int n = nums.size() ;

        using ll = long long ;

        vector< ll > prefix(n) ;

        prefix[0] = nums[0] ;

        for ( int i = 1 ; i < n ; i++ ) prefix[i] = prefix[i-1] + nums[i] ;

        vector<int> suffix(n) ;

        suffix[n-1] = nums[n-1] ;

        for ( int i = n - 2 ; i >= 0 ; i-- ) suffix[i] = min( nums[i] , suffix[i+1] ) ;

        ll maxi = LLONG_MIN ;

        for ( int i = 0 ; i < n-1 ; i++ ) {

            maxi = max( maxi , 1ll*(prefix[i] - suffix[i+1]) ) ;

        }

        return maxi ;

        // T.C = O(N)
        // S.C = O(2N)
        
    }
};