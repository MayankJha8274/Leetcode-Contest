class Solution {
public:
    
    int maxDepth(vector<int>& parent, vector<int>& depth) {

        int n = parent.size() ;

        vector<vector<int>> children(n);
        
        for (int i = 1; i < n; i++) children[parent[i]].push_back(i);

        depth[0] = 1;
        int h = 1;
        
        queue<int> q;
        q.push(0);
        
        while (!q.empty()) {
            
            int u = q.front(); q.pop();
            
            for (int v : children[u]) {
                
                depth[v] = depth[u] + 1;
                h = max(h, depth[v]);
                q.push(v);
                
            }
        }

        return h ;
        
    }
    
    long long weightedSum(vector<int>& parent, vector<int>& nums) {

        //  nums[i] * (h - d + 1)
        int n = parent.size() ;
        
        vector<int> depth(n,0) ;
        
        long long H = maxDepth(parent , depth) ;

        long long ans = 0 ;

        for ( int i = 0 ; i < n ; i++ ) ans += ( nums[i] * ( H - depth[i] + 1 ) ) ;

        return ans ;
        
        
    }
};