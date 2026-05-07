class Solution {
public:
    int countDigitOccurrences(vector<int>& nums, int digit) {

        int cnt = 0 ;

        int n = nums.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            int num = nums[i] ;

            while ( num ) {

                int dig = num % 10 ;

                if ( dig == digit ) cnt++ ;

                num /= 10 ;
                
            }
        }

        return cnt ;
        
    }
};