class Solution {
public:
    int minBishopMoves(vector<int>& source, vector<int>& target) {

        int sr = source[0] ;
        int sc = source[1] ;

        int tr = target[0] ;
        int tc = target[1] ;

        // case 1 : if source color is not matching the target color then there is no way we can reach the target
        if ( ( sr + sc ) % 2 != ( tr + tc ) % 2 ) return -1 ;

        // case 2 : if source == target 0 moves needed
        if ( sr == tr && sc == tc ) return 0 ;

        // case 3 : agar bishop same diagonal pr hai then 1 hii move chaiye to reach the target
        if ( abs( sr - tr ) == abs( sc - tc ) ) return 1 ;

        // case 4 : agar bishop same color p hai lekin not on same diagonal then 2 moves requires
        return 2 ;

    }
};