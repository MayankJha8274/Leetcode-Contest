// class Solution {
// public:
//     long long minArraySum(vector<int>& nums) {

//         unordered_set<int> st( nums.begin() , nums.end() ) ;

//         int n = nums.size() ;

//         long long sum = 0 ;

//         for ( int i = 0 ; i < n ; i++ ) {

//             int num = nums[i] ;

//             for ( int j = 1 ; j * j <= num ; j++ ) {

//                 if ( num % j == 0 ) {

//                     if ( st.count(j) ) nums[i] = min( nums[i] , j ) ;

//                     // other divisor 
//                     int other = num / j ;

//                     if ( st.count( other ) ) nums[i] = min( nums[i] , other ) ;

//                 }

//             }

//             sum += nums[i] ;
            
//         }

//         return sum ;
        
//     }
// };

class Solution {
public:
    long long minArraySum(vector<int>& nums) {

        int n = nums.size() ;

        int maxi = *max_element( nums.begin() , nums.end() ) ;

        long long sum = 0 ;

        vector<int> seive( maxi + 1 , 0 ) ;

        for ( int i = 0 ; i < n ; i++ ) seive[nums[i]]++ ;

        // applying seive of eratosthenes
        for ( int i = 1 ; i <= maxi ; i++ ) {

            if ( seive[i] == 0 ) continue ;

            for ( int j = i ; j <= maxi ; j += i ) {

                sum += seive[j] * 1LL * i ;
                seive[j] = 0 ;

            } 
        }

        return sum ;

        // T.C = O(m⋅logm+n)
        
    }
};