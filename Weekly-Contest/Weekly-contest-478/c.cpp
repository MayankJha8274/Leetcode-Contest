class Solution {

    int solve( int digit ) {

        int ans = 0 ;
        int first = 0 ;

        while ( digit ) {

            int dig = digit%10 ;
            
            if ( ans == 0 && dig == 0 ) {
                
                digit /= 10 ;
                continue ;

            }

            ans = ans * 10 + dig;

            digit /= 10 ;

        }

        return ans ;

    }
public:
    int minMirrorPairDistance(vector<int>& nums) {

        int idx = INT_MAX ;

        unordered_map<int,int> mpp ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            if ( mpp.find( nums[i] ) != mpp.end()  ) idx = min ( idx , i - mpp[nums[i]] ) ;

            mpp[solve(nums[i])] = i ;

        }

        if ( idx == INT_MAX ) return -1 ;

        return idx ;
        
    }
};
