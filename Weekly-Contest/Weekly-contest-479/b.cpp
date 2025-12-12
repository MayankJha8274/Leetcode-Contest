class Solution {
private:
    vector<int> seive( int n ) {

       /* if ( num <= 1 ) return false ;

        for ( int i = 2 ; i * i <= num ; i++ ) {

            if ( num % i == 0 ) return false ;

        }

        return true ; */
       
       vector<int> store( n+1 , 1 ) ;

       store[0] = store[1] = 0 ;
       
       for ( int i = 2 ; i*i <= n ; i++ ) {

         if ( store[i] == 1 ) {

            for ( int j = i * i ; j <= n ; j += i ) {

                store[j] = 0 ;

            }
         }
       }

       return store ;

    }
public:
    int largestPrime(int n) {

        vector<int> ans = seive( n ) ;

        vector<int> store ;

       for ( int i = 0 ; i <= n ; i++ ) {

          if ( ans[i] == 1 ) store.push_back( i ) ;

       }

        int sum = 0 ;
        int final = 0 ;

        for ( int i = 0 ; i < store.size() ; i++ ) {

            sum += store[i] ;

            if ( sum > n ) break ;

            if ( ans[sum] == 1 ) final = sum ;

        }

        return final ;
        
    }
};