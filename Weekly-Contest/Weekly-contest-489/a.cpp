class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {

        unordered_map<int,int> mpp ;

        for ( auto it : bulbs ) mpp[it]++ ;

        vector<int> ans ;

        for ( auto it : mpp ) {

            if ( it.second % 2 == 1 ) ans.push_back( it.first ) ;
            
        }

        sort( ans.begin() , ans.end() ) ;

        return ans ;
        
    }
};