class Solution {

    int solve( int i , int j , vector<vector<int>>& grid ,  vector<vector<vector<int>>>& dp , int k ) {
         
        int n = grid.size() ;
        int m = grid[0].size() ;

        // base case
        if ( k < 0 ) return -1e9 ;

        if ( i >= n || j >= m ) return -1e9 ;

        if ( i == n-1 && j == m-1 ) {

            if ( min(grid[i][j] , 1) <= k ) return grid[i][j] ;

            else return -1e9 ;

        }

        if ( dp[i][j][k] != -1 ) return dp[i][j][k] ;

        int down = grid[i][j] + solve( i+1 , j , grid , dp , k - min( grid[i][j] , 1)) ;

        int right = grid[i][j] + solve( i , j+1 , grid , dp , k - min( grid[i][j] , 1)) ;

        return dp[i][j][k] = max( down , right ) ;
    }
public:
    int maxPathScore(vector<vector<int>>& grid, int k) {

        int n = grid.size() ;
        int m = grid[0].size() ;

        vector<vector<vector<int>>> dp( n , vector<vector<int>> ( m , vector<int> ( k+1 , -1 ))) ;

        int ans = solve( 0 , 0 , grid , dp , k ) ;

        if ( ans < 0 ) return -1 ;

        return ans ;

        // T.C = O( N X M X K )
        // S.C = O(N) + O( N X M X K )
        
    }
};