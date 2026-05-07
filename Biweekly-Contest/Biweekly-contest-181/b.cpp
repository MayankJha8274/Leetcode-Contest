class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {

        typedef long long ll ;
        
        ll left = 0 ;
        ll right = 0 ;

        int n = nums.size() ;

        int idx = 0 ;

        // 2,4,5,2 --> 
        // left = 2+4

        while ( idx < n-1 && nums[idx] < nums[idx+1] ) {

            left += nums[idx] ;
            idx++ ;

        }

        left += nums[idx] ;

        while ( idx < n ) right += nums[idx++] ;

        if ( left > right ) return 0 ;

        else if ( right > left ) return 1 ;

        return -1 ;
        
    }
};