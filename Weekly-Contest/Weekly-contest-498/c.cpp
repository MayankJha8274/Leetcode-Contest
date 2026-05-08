class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {

        vector<vector<int>> time ( n , vector<int> ( m , -1 ) ) ;
        vector<vector<int>> ans ( n , vector<int> ( m , 0 ) ) ;

        queue<tuple<int,int,int,int>> q ;

        for ( auto it : sources ) {

            int row = it[0] ;
            int col = it[1] ;
            int val = it[2] ;

            ans[row][col] = val ;
            time[row][col] = 0 ;
            q.push( { row , col , val , 0 } ) ;
            
        }

        while ( !q.empty() ) {

            int lvl = q.size() ;

            int row_arr[4] = { -1 , 0 , 1 , 0 } ;
            int col_arr[4] = { 0 , 1 , 0 , -1 } ;
        
            while ( lvl-- ) {

                auto it = q.front() ; q.pop() ;

                int row = get<0>(it) ;
                int col = get<1>(it) ;
                int val = ans[row][col] ;
                int t = get<3>(it) ;

                int curr_time = t+1 ;

                for ( int i = 0 ; i < 4 ; i++ ) {

                    int nrow = row_arr[i] + row ;
                    int mcol = col_arr[i] + col ;

                    if ( nrow >= 0 && nrow < n && mcol >= 0 && mcol < m && 
                       time[nrow][mcol] == -1 ) {

                            time[nrow][mcol] = curr_time ;
                            ans[nrow][mcol] = val ;
                            q.push( { nrow , mcol , val , time[nrow][mcol] } ) ;
                        
                       }

                    else if ( nrow >= 0 && nrow < n && mcol >= 0 && mcol < m && 
                       time[nrow][mcol] == curr_time ) {

                            ans[nrow][mcol] = max( val , ans[nrow][mcol] ) ;
                        
                       }
                }

                
            }
        }

        return ans ;
        
        
    }
};