class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {

        vector<int> ans ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            ans.push_back( abs(nums[i]) ) ;
            
        }

        long long first = 0 ;
        long long sec = 0 ;
        long long final = 0 ;

        int n = ans.size() ;

       // int mid = ( n+1 ) / 2 ;

        sort( ans.rbegin() , ans.rend() ) ;

        for ( int i = 0 ; i < ceil((double)n/2) ; i++ ) {

            first += ( ans[i] * ans[i] ) ;
            
        }

        for ( int i = ceil((double)n/2) ; i < n ; i++ ) {

            sec += ( ans[i] * ans[i] ) ;
            
        }

        final = first - sec ;

        return final ;

        // T.C = O( NLOGN )
        // S.C = O( N )
        
    }
};