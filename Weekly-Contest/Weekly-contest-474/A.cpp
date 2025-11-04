class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {

        int maxi = *max_element( nums.begin() , nums.end() ) ;
        int mini = *min_element( nums.begin() , nums.end() ) ;

        vector<int> ans(101) ;

        for ( int i = 0 ; i < nums.size() ; i++ ) ans[nums[i]]++ ;

        vector<int> final ;

        for ( int i = mini ; i <= maxi ; i++ ) {

            if ( ans[i] == 0 ) final.push_back(i) ;
            
        }
        
        return final ;

        // T.C = O(N)
        // S.C = O(N)
        
    }
};