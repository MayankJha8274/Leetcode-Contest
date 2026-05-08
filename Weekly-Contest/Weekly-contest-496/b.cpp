class Solution {
public:
    vector<int> findGoodIntegers(int n) {

        int num = cbrt(n) + 1 ;

        typedef long long ll ;

        unordered_map<ll,int> mpp ;

        for ( int i = 1 ; i <= num ; i++ ) {

            for ( int j = i ; j <= num ; j++ ) {

                ll x = 1ll * i * i * i + 1ll * j * j * j ;

                if ( x > n ) break ;

                mpp[x]++ ;
                
            }
        }

        vector<int> ans ;

        for ( auto it : mpp ) {

            if ( it.second >= 2 && it.first <= n ) ans.push_back( it.first ) ;
            
        }

        sort( ans.begin() , ans.end() ) ;

        return ans ;
        
    }
};