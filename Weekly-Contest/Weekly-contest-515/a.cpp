class Solution {
public:
    int nearestDrone(vector<vector<int>>& drones, vector<int>& target) {

        int n = drones.size() ;

        int x1 = target[0] ;
        int y1 = target[1] ;
        int idx = -1 ;
        int mini = INT_MAX ;

        for ( int i = 0 ; i < n ; i++ ) {

            int x = drones[i][0] ;
            int y = drones[i][1] ;
            int range = drones[i][2] ;

            int dis = abs(x-x1) + abs(y-y1) ;

            if ( dis <= range && mini > dis ) {

                idx = i ;
                mini = dis ;

            } 

        }

        return idx ;
        
    }
};