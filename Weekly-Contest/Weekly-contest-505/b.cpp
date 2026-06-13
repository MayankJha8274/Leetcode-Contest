// class Solution {
// public:
//     void solve( int n , int k , vector<string>& test , int i , string &curr ) {

//         if ( i >= n ) {

//             test.push_back( curr ) ;
//             return ;
            
//         }

//         // 0
//         curr.push_back( '0' ) ;
//         solve( n , k , test , i+1 , curr ) ;
//         curr.pop_back() ;

//         // 1
//         curr.push_back( '1' ) ;
//         solve( n , k , test , i+1 , curr ) ;
//         curr.pop_back() ;
        
//     }
    
//     vector<string> generateValidStrings(int n, int k) {

//         vector<string> test ;

//         string curr = "" ;

//         solve( n , k , test , 0 , curr ) ;

//         int n1 = test.size() ;

//         vector<string> ans ;

//         for ( int i = 0 ; i < n1 ; i++ ) {

//             int sum = 0 ;
//             bool flag = false ;

//             for ( int j = 0 ; j < test[i].size() ; j++ ) {

//                 if ( test[i][j] == '1' ) sum += j ;

//                 if ( j > 0 && test[i][j-1] == '1' && test[i][j] == '1' ) flag = true;
                
//             }

//             if ( flag == false && sum <= k ) ans.push_back( test[i] ) ;
            
//         }

//         return ans ;
        
//     }
// };

class Solution {
public:
    void solve( int n , int k , vector<string>& ans , int idx , string &curr , int cost ) {

        // base case
        if ( cost > k ) return ;

        if ( idx == n ) {

            ans.push_back(curr) ;
            return ;

        }

        // 0 pick karo
        curr.push_back('0') ;
        solve( n , k , ans , idx+1 , curr , cost ) ;
        curr.pop_back() ;

        // 1 pick karo
        // but carefully 2 consective 1 nhi krna pick
        if ( idx == 0 || curr[idx-1] == '0' ) {

            curr.push_back('1') ;
            solve( n , k , ans , idx+1 , curr , cost+idx ) ;
            curr.pop_back() ;

        }
        
    }
    
    vector<string> generateValidStrings(int n, int k) {

        vector<string> ans ;

        string curr = "" ;

        solve( n , k , ans , 0 , curr , 0 ) ;

        return ans ;
        
    }
};