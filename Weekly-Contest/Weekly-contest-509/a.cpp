// class Solution {
// public:
//     int maxDigitRange(vector<int>& nums) {

//         unordered_map<int,int> freq ;
//         unordered_map<int,int> mpp ;

//         for ( auto it : nums ) freq[it]++ ;

//         int maxi = INT_MIN ;

//         for ( auto it : nums ) {

//             int num = it ;
//             int maxx = 0 ;
//             int minn = 9 ;

//             while ( num ) {

//                 int dig = num % 10 ;
//                 maxx = max( maxx , dig ) ;
//                 minn = min( minn , dig ) ;
//                 num /= 10 ;

//             }

//             int range = maxx - minn ;
//             maxi = max( maxi , range ) ;
//             mpp[it] = range ;

//         }

//         int ans = 0 ;

//         for ( auto it : mpp ) {

//             int num = it.first ;
//             int rang = it.second ;

//             if ( rang != maxi ) continue ;

//             int dash = 1 ;

//             if ( freq.find(num) != freq.end() ) dash = freq[num] ;

//             ans += ( dash * num ) ;

//         }

//         return ans ;
        
//     }
// };

class Solution {
public:
    int maxR( int num ) {

        int maxi = -1 ;
        int mini = 9 ;

        while ( num ) {

            int dig = num % 10 ;
            maxi = max( maxi , dig ) ;
            mini = min( mini , dig ) ;
            num /= 10 ;

        }

        return maxi - mini ;

    }

    int maxDigitRange(vector<int>& nums) {

        int rangeMax = -1 ;

        for ( auto it : nums ) rangeMax = max( rangeMax , maxR(it) ) ;

        int sum = 0 ;

        for ( auto it : nums ) {

            int range = maxR(it) ;

            if ( range == rangeMax ) sum += it ;

        }
        
        return sum ;
        
    }
};