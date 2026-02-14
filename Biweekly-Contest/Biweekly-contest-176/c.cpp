class Solution {
public:
    typedef long long ll ;

    ll solve(vector<int>& nums, vector<int>& colors , int i , int j , 
             vector<vector<ll>>& dp) {

        int n = nums.size() ;

        if ( i >= n ) return 0 ;

        if ( dp[i][j] != -1 ) return dp[i][j] ;

        ll skip = solve( nums , colors , i+1 , 0 , dp ) ;

        ll take = 0 ;
        if ( ( i > 0 && colors[i] != colors[i-1] ) || j == 0 )
        take = nums[i] + solve( nums , colors , i+1 , 1 , dp ) ;

        return dp[i][j] = max( skip , take ) ;
        
    }
    
    long long rob(vector<int>& nums, vector<int>& colors) {

        int n = nums.size() ;

        vector<vector<ll>> dp ( n , vector<ll> ( 2 , -1 ) ) ;

        return solve ( nums , colors , 0 , 0 , dp ) ;
        
    }
};©leetcode