class Solution {
public:
    vector<int> bfs( int start , vector<vector<int>>& adj , int n ) {

        vector<int> dis( n , -1 ) ;
        queue<int> q ;

        q.push(start) ;
        dis[start] = 0 ;

        while ( !q.empty() ) {

            auto it = q.front() ; q.pop() ;

            for ( auto v : adj[it] ) {

                if ( dis[v] == -1 ) {

                    dis[v] = dis[it] + 1 ;
                    q.push(v) ;
                    
                }
            }
        }

        return dis ;
        
    }

    
    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {

        vector<vector<int>> adj(n) ;

        for ( auto it : edges ) {

            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;
            
        }

        vector<int> dx = bfs( x , adj , n ) ;
        vector<int> dy = bfs( y , adj , n ) ;
        vector<int> dz = bfs( z , adj , n ) ;

        int cnt = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            vector<int> temp = { dx[i] , dy[i] , dz[i] } ;

            sort( temp.begin() , temp.end() ) ;

            int a = temp[0] ;
            int b = temp[1] ;
            int c = temp[2] ;

            if ( 1LL * a * a + 1LL * b * b == 1LL * c * c ) cnt++ ;
            
        }

        return cnt ;
        
    }
};