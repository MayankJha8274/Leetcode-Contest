class Solution {
public:
    typedef long long ll ;

    int gcde( int a , int b ) {

        while ( a && b ) {

            if ( a > b ) a = a % b ;

            else b = b % a ;

        }

        return a == 0 ? b : a ;

    }

    long long gcdSum(vector<int>& nums) {

        ll mi = 0 ;

        int n = nums.size() ;
        vector<int> prefixGcd(n,0) ;
        
        for ( int i = 0 ; i < n ; i++ ) {

            mi = max( mi , (ll)nums[i] ) ;
            prefixGcd[i] = gcde( nums[i] , mi ) ;
            
        }

        sort( prefixGcd.begin() , prefixGcd.end() ) ;

        int i = 0 ;
        int j = n-1 ;

        ll sum = 0 ;

        while ( i < j ) {

            sum += gcde( prefixGcd[i] , prefixGcd[j] ) ;
            i++ ;
            j-- ;
            
        }

        return sum ;
        
    }
};