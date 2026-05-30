class Solution {
public:
    int minimumSwaps(vector<int>& nums) {

        int n = nums.size() ;

        int cnt = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] == 0 ) cnt++ ;
            
        }

        int ans = 0 ;

        int j = n-1 ;

        while ( cnt && j >= 0 ) {

            if ( nums[j] == 0 ) {

                cnt-- ;
                j-- ;
                
            }

            else {

                cnt-- ;
                ans++ ;
                j-- ;
                
            }
        } 

        return ans ;
        
    }
};