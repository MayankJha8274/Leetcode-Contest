class Solution {
public:
    vector<int> countOppositeParity(vector<int>& nums) {

        int n = nums.size() ;

        vector<int> ans(n,0) ;

        for ( int i = 0 ; i < n ; i++ ) {

            int parity = nums[i] % 2 ;

            int cnt = 0 ;
            
            for ( int j = i+1 ; j < n ; j++ ) {

                int p = nums[j] % 2 ;

                if ( parity != p ) cnt++ ;
                
            }

            ans[i] = cnt ;
            
        }

        return ans ;
        
    }
};