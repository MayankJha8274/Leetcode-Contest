class Solution {
public:
    vector<int> bestTower(vector<vector<int>>& towers, vector<int>& center, int radius) {

        int c1 = center[0] ;
        int c2 = center[1] ;

        int one = -1 ;
        int two = -1 ;

        sort( towers.begin() , towers.end() ) ;

        int maxpo = -1 ;

        for ( auto it : towers ) {

            int x = it[0] ;
            int y = it[1] ;
            int po = it[2] ;

            int dis = abs( x - c1 ) + abs( y - c2 ) ;

            if ( dis <= radius && maxpo < po ) {

                maxpo = po ;
                one = x ;
                two = y ;
                
            }
        }

        return { one , two } ;
        
    }
};