class Solution {
public:
    int minCost(vector<int>& nums1, vector<int>& nums2) {

        unordered_map<int,int> mpp ;

        for ( auto it : nums1 ) mpp[it]++ ;

        for ( auto it : nums2 ) mpp[it]++ ;

        for ( auto it : mpp ) {

            if ( it.second % 2 == 1 ) return -1 ;
            
        }

        int cost = 0 ;

        unordered_map<int,int> mpp1 ;
        unordered_map<int,int> mpp2 ;

        for ( auto it : nums1 ) mpp1[it]++ ;

        for ( auto it : nums2 ) mpp2[it]++ ;

        for ( auto it : mpp ) {

            auto element = it.first ;
            int cnt1 = mpp1[element] ;
            int cnt2 = mpp2[element] ;

            cost += abs( cnt1 - cnt2 ) ;

        }

        return cost/4 ;
        
    }
};