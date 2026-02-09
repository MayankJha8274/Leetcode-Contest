class Solution {
public:
    int dominantIndices(vector<int>& nums) {

        int n = nums.size() ;

        int final = 0 ;

        for ( int i = 0 ; i < n-1 ; i++ ) {

            double cnt = 0 ;
            double avg = 0 ;

            for ( int j = i+1 ; j < n ; j++ ) {

                avg += nums[j] ;
                cnt++ ;
                
            }

            double val = double(avg) / cnt ;

            if ( nums[i] > val ) final++ ;
            
        }

        return final ;
        
    }
};