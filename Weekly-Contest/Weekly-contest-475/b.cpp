class Solution {
public:
    int minimumDistance(vector<int>& nums) {

        unordered_map<int, vector<int>> p ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            p[nums[i]].push_back(i) ;
            
        }

        int ans = INT_MAX ;

        for ( auto it : p ) {

            vector<int> idx = it.second ;

            if ( idx.size() < 3 ) continue ;

            else {

                for ( int i = 0 ; i < idx.size()-2 ; i++ ) {

                    int i1 = idx[i] ;
                    int i2 = idx[i+1] ;
                    int i3 = idx[i+2] ;

                    int d = abs(i1-i2) + abs(i2-i3) + abs(i3-i1) ;
                    ans = min( ans , d ) ;
                    
                }
            }
        }

        if ( ans == INT_MAX ) return -1 ;

        return ans ;

        // T.C = O( N ) 
        // S.C = O( N )
        
    }
};