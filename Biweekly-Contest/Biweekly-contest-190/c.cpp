#include <bits/stdc++.h>
using namespace std ;

class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        
        vector<string> ans ;
        
        for ( int x : nums ) {
            
            string temp  = "" ;
            
            for ( int i = 25 ; i >= 0 ; i-- ) {
                
                while ( x >= 1 << i ) {
                    
                    x -= 1 << i ;
                    temp += ( 'a' + i ) ;
                    
                }
            }
            
            ans.push_back( temp ) ;
            
        }
        
        return ans ;
        
    }
};

// int main() {
    
//     int n ;
//     cin >> n ;
    
//     vector<int> arr(n) ;
//     for ( int i = 0 ; i < n ; i++ ) cin >> arr[i] ;
    
//     Solution obj;
    
//     vector<string> result = obj.largestString(arr);

//     for (string s : result) cout << s << " ";

//     return 0;
    
// }