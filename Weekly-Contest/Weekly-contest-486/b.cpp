class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {

        vector<int> arr ;

        int n = nums.size() ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] >= 0 ) arr.push_back(nums[i]) ;
            
        }

        int m = arr.size() ;

        if ( m == 0 ) return nums ;

        k = k % m ;

        reverse( arr.begin() , arr.begin() + k ) ;
        reverse( arr.begin() + k , arr.end() ) ;
        reverse( arr.begin() , arr.end() ) ;

        int i = 0 ;
        int j = 0 ;

        while ( i < n && j < arr.size() ) {

            if ( nums[i] < 0 ) i++ ;

            else {

                nums[i] = arr[j] ;
                i++ ;
                j++ ;
                
            }
        }

        return nums ;
        
    }
};