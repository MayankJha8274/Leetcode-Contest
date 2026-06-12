class Solution {
public:
    long long solve( int n , int idx , int pick , vector<vector<long long>>& dp , 
    vector<int>& nums, string& s ) {

        // base case
        if ( idx == n ) return 0 ;

        if ( dp[idx][pick] != -1 ) return dp[idx][pick] ;

        long long ans = 0 ;

        // 0 comes
        if ( (s[idx] - '0') == 0 ) ans = solve( n , idx+1 , 0 , dp , nums , s ) ;

        // 1 comes
        else {

            long long moveLeft = 0 ;

            if ( idx > 0 ) {

                moveLeft = ( ( pick == 0 ) ? nums[idx-1] : 0 ) + 
                solve( n , idx+1 , 0 , dp , nums , s ) ;

            }

            else {

                moveLeft = 0 ;

            }

            long long stay = nums[idx] + solve( n , idx+1 , 1 , dp , nums , s ) ;

            ans = max( moveLeft , stay ) ;

        }

        return dp[idx][pick] = ans ;

    }

    long long maxTotal(vector<int>& nums, string s) {

        int n = s.size() ;

        vector<vector<long long>> dp( n , vector<long long> ( 2 , -1 ) ) ;

        // n , idx , not_taken , dp , nums , s
        // 0 --> prev_idx = not_taken / we can pick
        // 1 --> prev_idx = taken / we can't pick
        return solve( n , 0 , 0 , dp , nums , s ) ;
        
    }
};