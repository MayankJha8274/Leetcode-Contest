class Solution {
public:
    bool uniformArray(vector<int>& nums) {

       // type long long ll ;

        int n = nums.size() ;

        int even = 0 ;
        int odd = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] % 2 == 0 ) even++ ;

            else odd++ ;
            
        }

        if ( even == n || odd == n ) return true ;

        int min_odd = INT_MAX ;
        int min_even = INT_MAX ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] % 2 == 0 ) {

                min_even = min( min_even , nums[i] ) ;
                
            }

            else min_odd = min( min_odd , nums[i] ) ;
            
        }

        if ( min_even > min_odd ) return true ;

        return false ;
        
        
    }
};