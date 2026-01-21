class Solution {
public:
    int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {
      
       int n = costs.size() ;

       vector<pair<int,int>> vec ;

       for ( int i = 0 ; i < n ; i++ ) {

          vec.push_back( { costs[i] , capacity[i] } ) ;

       }

       // sort by cost
       sort( vec.begin() , vec.end() ) ;

       // prefix of max capacity till index i
       vector<int> prefix( n , 0 ) ;

       prefix[0] = vec[0].second ;

       for ( int i = 1 ; i < n ; i++ ) {

           prefix[i] = max( prefix[i-1] , vec[i].second ) ;

       }

       int ans = 0 ;

       // if we are only able to select one machine
       for ( int i = 0 ; i < n ; i++ ) {

           if ( vec[i].first < budget ) ans = max( ans , vec[i].second ) ;
           
       }

       // doing binary search from current index to previous all value
       for ( int i = 1 ; i < n ; i++ ) {

           int remaining = budget - vec[i].first - 1 ;
           if ( remaining < 0 ) continue ;

           int start = 0 ;
           int end = i - 1 ;

           int idx = -1 ;

           while ( start <= end ) {
             
              int mid = start + ( end - start ) / 2 ;

              if ( vec[mid].first <= remaining ) {

                  idx = mid ;
                  start = mid + 1 ;

              }

              else end = mid - 1 ;
               
           }

           if ( idx != -1 ) ans = max( ans , vec[i].second + prefix[idx] ) ;

       }

       return ans ;

    }
};



// approach 2 - by dp
// class Solution {
// public:
//     int solve( vector<vector<vector<int>>>& dp , vector<int>& costs, 
//               vector<int>& capacity, 
//               int budget , int three , int i ) {

//         if ( i == costs.size() || three == 0 ) return 0 ;

//         if ( dp[i][three][budget] != -1 ) return dp[i][three][budget] ;

//         int pick = 0 ;

//         if ( budget > costs[i] )
//         pick = capacity[i] + solve( dp , costs , capacity , budget - costs[i] ,
//                                    three-1 , i + 1 ) ;

//         int not_pick = solve( dp , costs , capacity , budget , three , i+1 ) ;

//         return dp[i][three][budget] = max( pick , not_pick ) ;
        
//     }
    
//     int maxCapacity(vector<int>& costs, vector<int>& capacity, int budget) {

//         int n = costs.size() ;

//         vector<vector<vector<int>>> dp (n , vector<vector<int>>( 3 , vector<int>
//                                                                ( budget+1 , -1))) ;

//         int three = 2 ;

//         int maxi = 0 ;

//         return solve( dp , costs , capacity , budget , three , 0 ) ;
        
//     }
// };