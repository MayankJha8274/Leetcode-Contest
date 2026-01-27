class Solution {
public:
    vector<int> bfs( int n , vector<vector<int>>& adj , int node ) {

        vector<int> dis(n , INT_MAX) ;
        dis[node] = 0 ;

        queue<int> q ;
        q.push(node) ;

        while ( !q.empty() ) {

            auto it = q.front() ; q.pop() ;

            for ( auto v : adj[it] ) {

                if ( dis[v] > dis[it] + 1 ) {

                    dis[v] = dis[it] + 1 ;
                    q.push(v) ;

                }
            }
        }

        return dis ;

        // T.C = O( N + E )
        // S.C = O( N + E ) --> bcz of adj list construction

    }

    vector<int> dijsktra( int n , vector<vector<int>>& adj , int node ) {
      
        vector<int> dis(n , INT_MAX) ;
        dis[node] = 0 ;

        priority_queue< pair<int,int> , vector<pair<int,int>> , greater<pair<int,int>> > pq ;

        pq.push({ 0 , node }) ;

        while ( !pq.empty() ) {

            auto it = pq.top() ; pq.pop() ;

            int distance = it.first ;
            int curr = it.second ;

            for ( auto v : adj[curr] ) {

                if ( dis[v] > dis[curr] + 1 ) {

                    dis[v] = dis[curr] + 1 ;
                    pq.push({ dis[v] , v }) ;

                }
            }
        }

        return dis ;

        // T.C = O((V + E) log n) = O(ElogV)​
        // S.C = O(V + E)

    }

    // When all edge weights are equal (1), BFS is optimal and faster than Dijkstra.

    // we can implement dijstra using set also but priority queue wala method is fast

    int specialNodes(int n, vector<vector<int>>& edges, int x, int y, int z) {
        
        vector<vector<int>> adj(n) ;

        for ( auto it : edges ) {

            adj[it[0]].push_back(it[1]) ;
            adj[it[1]].push_back(it[0]) ;

        }

        vector<int> dx = dijsktra( n , adj , x ) ;
        vector<int> dy = dijsktra( n , adj , y ) ;
        vector<int> dz = dijsktra( n , adj , z ) ;

        int cnt = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            vector<int> ans = { dx[i] , dy[i] , dz[i] } ;
            sort( ans.begin() , ans.end() ) ;

            if ( 1LL * ans[0] * ans[0] + 1LL * ans[1] * ans[1] == 1LL * ans[2] * ans[2] ) cnt++ ;

        }

        return cnt ;

    }
};