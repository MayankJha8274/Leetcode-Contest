/*
class Solution {
public:

     long long sumAndMultiply( string &s , int start , int end ) {

        string k = "" ;

        for ( int i = start ; i <= end ; i++ ) {

            if ( s[i] != '0' ) k += s[i] ;
            
        }

        if ( k.empty() ) return 0 ;

        long long sum = 0 ;

        long long num = 0 ;

         for ( auto it : k ) num = ( num * 10 + ( it - '0')) % ( 1000000000 + 7 ) ;
         
         for ( auto it : k ) sum += ( it - '0' ) ;

        return ((long long)sum * num) % (1000000000 + 7) ;

       // return 0 ;
        
    }
    
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        vector<int> ans ;

        for ( int i = 0 ; i < queries.size() ; i++ ) {

            auto val = queries[i] ;

            int start = val[0] ;
            int end = val[1] ;

            long long fin = sumAndMultiply( s , start , end ) % ( 1000000000 + 7 ) ;

            ans.push_back( fin ) ;
            
        }

        return ans ;

        // TLE APPROACH
        
    }
};
*/

// OPTIMISATION

class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {

        int n = s.size() ;

        vector<int> sum( n+1 , 0 ) ;
        vector<long long> power( n+1 , 1 ) ;

        long long mod = 1e9 + 7 ;

        for ( int i = 0 ; i < n ; i++ ) {

            sum[i+1] = sum[i] + ( s[i] - '0' ) ;

        }

        for ( int i = 1 ; i <= n ; i++ ) {

            power[i] = ( power[i-1] * 10 ) % mod ;

        }

        vector<long long> x( n+1 , 0 ) ;
        vector<int> zero( n+1 , 0 ) ;

        for ( int i = 0 ; i < n ; i++ ) {

            int digit = s[i] - '0' ;

            if ( digit != 0 ) {

                x[i+1] = (( x[i] * 10 ) + digit ) % mod ;
                zero[i+1] = zero[i] + 1 ;

            }

            else {

                x[i+1] = x[i] ;
                zero[i+1] = zero[i] ;

            }
        }

        vector<int> final ;

        for ( int i = 0 ; i < queries.size() ; i++ ) {

            int l = queries[i][0] ;
            int r = queries[i][1] ;

            long long suming = sum[r+1] - sum[l] ;

            int zc = zero[r+1] - zero[l] ;

            long long x_full = x[r+1] ;

            long long x_left = x[l] ;

            long long x_sub = ( x_full - ( x_left * power[zc] ) % mod + mod ) % mod ;

            long long ans = ( x_sub * ( suming ) % mod ) % mod ;

            final.push_back( ans ) ;

        }

        return final ;

        // OPTIMISED APPROACH
        
        
    }
};