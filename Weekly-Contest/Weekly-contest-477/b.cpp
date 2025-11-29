class Solution {
public:
    int maxBalancedSubarray(vector<int>& nums) {

        map<pair<int,int> , int> mpp ;

        int bal = 0 ;
        int xoring = 0 ;
        int ans = 0 ;

        mpp[{0,0}] = -1 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            xoring ^= nums[i] ;

            if ( nums[i] % 2 == 0 ) bal++ ;

            else bal-- ;

            pair<int,int> key = { xoring , bal } ;

            if ( mpp.find(key) != mpp.end() ) ans = max( ans , i - mpp[key] ) ;

            else mpp[key] = i ;
            
        }

        return ans ;

        // T.C = O( N )
        // S.C = O( N )
        
    }
};