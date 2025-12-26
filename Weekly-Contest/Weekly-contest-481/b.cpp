class Solution {
public:
    long long minCost(string s, vector<int>& cost) {

        // vector<long long> mpp( 26 , 0 ) ;
        // vector<long long> ans ;

        // for ( int i = 0 ; i < cost.size() ; i++ ) {

        //     int pos = s[i] - 'a' ;
        //     mpp[pos] += cost[i] ;
            
        // }

        // for ( auto it : mpp ) {

        //     if ( it != 0 ) ans.push_back( it ) ;
            
        // }

        // sort( ans.begin() , ans.end() ) ;

        // if ( ans.size() == 1 ) return 0 ;

        // long long final = 0 ;
        // int n = ans.size() ;

        // for ( int i = 0 ; i < n-1 ; i++ ) final += ans[i] ;

        // return final ;
        
        using ll = long long ;

        unordered_map<char , ll > mpp ;

        ll total = 0 ;
        ll maxi = 0 ;

        for ( int i = 0 ; i < cost.size() ; i++ ) {

            mpp[s[i]] += cost[i] ;
            total += cost[i] ;

            maxi = max( maxi , mpp[s[i]] ) ;

        }

        if ( mpp.size() == 1 ) return 0 ;

        return total - maxi ;
        
    }
};