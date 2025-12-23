class Solution {
public:
    int minOperations(vector<int>& nums) {

        int ops = 0 ;
        int n = nums.size() ;

        unordered_map<int,int> mpp ;

        for ( int x : nums ) mpp[x]++ ;

        if ( mpp.size() == n ) return 0 ;

        for ( int i = 0 ; i < n ; i = i+3 ) {

            int remove = min( 3 , n - i ) ;

            for ( int j = i ; j < i + remove ; j++ ) {

                mpp[nums[j]]-- ;

                if ( mpp[nums[j]] == 0 ) mpp.erase( nums[j] ) ;

            }

            ops++ ;

            if ( mpp.size() == ( n - ( i + remove ) ) ) return ops ;

        }

        return ops ;
        
    }
};