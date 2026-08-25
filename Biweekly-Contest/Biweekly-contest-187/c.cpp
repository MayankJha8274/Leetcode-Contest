class Solution {
public:
    int minAdjacentSwaps(vector<int>& nums, int a, int b) {

        int n = nums.size() ;

        int countMiddleSegment = 0 , countLastSegment = 0 ;

        long long ops = 0 ;

        int m = 1e9+7 ;

        for ( int i = 0 ; i < n ; i++ ) {

            // first segment
            if ( nums[i] < a ) {

                // add middle+last segement elements present before this first segement
                ops += ( countMiddleSegment + countLastSegment )%m ;

            }

            // middle segment
            else if ( nums[i] >= a && nums[i] <= b ) {

                // add last segment elements present before this middle segment
                ops += ( countLastSegment )%m ;
                countMiddleSegment++ ;

            }

            else countLastSegment++ ;

        }

        return ops%m ;

        //  minimum adjacent swaps to sort = number of inversions.
        
    }
};