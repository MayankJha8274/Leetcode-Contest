class Solution {
public:
    int minOperations(vector<int>& nums) {

        // we can only sort an array if it is sorted rotated array 
        
        int n = nums.size() ;

        int pos0 = -1 ;
        int inc = 0 ;
        int dec = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] == 0 ) pos0 = i ;

            if ( nums[i] > nums[(i+1)%n] ) inc++ ;

            if ( nums[i] < nums[(i+1)%n] ) dec++ ;

        }

        if ( inc > 1 && dec > 1 ) return -1 ;

        int steps = INT_MAX ;

        // case 1 : decreasing sorted rotated array
        // if array is decreasing sorted array then here reverse is must we cant sort array without reverse so we have to move 0 at end index then we perform reverse to make it sorted
        if ( dec <= 1 ) {

            // sub case 1 : shift then reverse
            int path1 = ( ( pos0 + 1 ) % n + 1 ) ;

            // sub case 2 : reverse then shift
            // here reverse krke incresing bana lia aab first index p 0 hoga
            int path2 = n - pos0 ;

            steps = min( path1 , path2 ) ;

        }

        // case 2 : increasing sorted rotated array
        if ( inc <= 1 ) {

            // sub case 1 : left shift only
            // first index p 0 lana h
            int path1 = pos0 ;

            // sub case 2 : reverse then move 0 to end of array then again reverse
            // last index p 0 lana h then reverse
            int path2 = 1 + ( n - pos0 ) % n + 1 ;

            steps = min( steps , min( path1 , path2 ) ) ;

        }

        return steps ;
        
    }
};