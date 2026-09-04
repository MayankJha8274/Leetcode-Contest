class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {

        const int m = 1e9 + 7 ;

        int n = nums.size() ;

        long long ops = 0 , res = k ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( res < nums[i] ) {

                int needed = nums[i] - res ;
                int curr_ops = ceil(double(needed)/k) ;
                res += ( curr_ops * k ) ;
                ops += curr_ops ;

            }

            res -= nums[i] ;

        }

        // sum of first n natural no. = n*n+1/2 
        // if ( (ops+1) % 2 == 0 ) {

        //     long long a = ( (ops+1)/2 ) % m ;
        //     long long b = ops % m ;
        //     return (a*b) % m ;

        // }
        
        // else {

        //     long long a = ( ops/2 ) % m ;
        //     long long b = (ops+1) % m ;
        //     return (a*b) % m ;

        // }

        return (int)(((__int128(ops)*(ops+1)) / 2) % m ) ;

    }
};