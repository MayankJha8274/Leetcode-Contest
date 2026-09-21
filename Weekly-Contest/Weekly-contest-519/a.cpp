class Solution {
public:
    vector<vector<int>> cyclicShift(int n, vector<vector<int>>& grid, vector<int>& rowShift, vector<int>& colShift) {

        vector<vector<int>> mat( n , vector<int> (n)) ;

        for ( int i = 0 ; i < n ; i++ ) {

            for ( int j = 0 ; j < n ; j++ ) {

                int k = rowShift[i]%n ;

                int col = (j - k + n) % n ;
                mat[i][col] = grid[i][j] ;

            }
        }

        vector<vector<int>> mat1( n , vector<int> (n)) ;

        for ( int i = 0 ; i < n ; i++ ) {

            for ( int j = 0 ; j < n ; j++ ) {

                int k = colShift[j]%n ;

                int row = (i - k + n) % n ;
                mat1[row][j] = mat[i][j] ;

            }
        }

        return mat1 ;
        
    }
};