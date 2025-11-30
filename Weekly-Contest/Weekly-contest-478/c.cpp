class Solution {
public:

    int solve( int num ) {

        int ans = 0 ;

        while( num ) {

            int dig = num % 10 ;

            if ( !( ans == 0 && dig == 0 ) ) 
            ans = ans * 10 + dig ;
            
            num /= 10 ;
            
        }

        return ans ;
        
    }
    int minMirrorPairDistance(vector<int>& nums) {

        unordered_map<int,int> mpp ;

       // for ( int i = 0 ; i < nums.size() ; i++ ) mpp[nums[i]] = i ;
        
        int mini = 1e9 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            int call = solve( nums[i] ) ;

            if ( mpp.find( nums[i] ) != mpp.end() ) {

                mini = min( mini , abs( i - mpp[nums[i]] ) ) ;
                
            }

            else mpp[call] = i ;
            
        }

        if ( mini == 1e9 ) return -1 ;

        return mini ;
        
    }
}