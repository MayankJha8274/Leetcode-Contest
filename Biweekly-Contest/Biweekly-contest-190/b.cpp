#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int valid( vector<int>& arr ) {

        int n = arr.size() ;

        vector<int> prefix( n , 0 ) , suffix( n , 0 ) ;

        int score = 0 ;

        prefix[0] = arr[0] ;
        suffix[n-1] = arr[n-1] ;

        for ( int i = 1 ; i < n ; i++ ) prefix[i] = __gcd( prefix[i-1] , arr[i] ) ;

        for ( int i = n-2 ; i >= 0 ; i-- ) suffix[i] = __gcd( suffix[i+1] , arr[i] ) ;

        for ( int i = 0 ; i < n-1 ; i++ ) {

            if ( prefix[i] == suffix[i+1] ) score++ ;

        }

        return score ;

    }

    int maxValidSplits(vector<int>& nums) {

        int n = nums.size() ;
       // cout << "hii" ;

        int withoutRemoval = valid( nums ) ;
        
      //  cout << "hii" ;

        int score = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            vector<int> arr ;

            for ( int j = 0 ; j < n ; j++ ) {

                if ( j == i ) continue ;

                arr.push_back( nums[j] ) ;

            }

            score = max( score , valid(arr) ) ;

        }

        return max( score , withoutRemoval ) ;
        
    }
};

// int main() {
// 	// your code goes here
	
// 	int n ;
// 	cin >> n ;
	
// 	vector<int> arr(n) ;
	
// 	for ( int i = 0 ; i < n ; i++ ) cin >> arr[i] ;
	
// 	Solution obj ;
	
// 	cout << obj.maxValidSplits(arr) << endl ;
	
// 	return 0 ;

// }