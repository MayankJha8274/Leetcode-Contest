class Solution {
public:
    long long shadowPairs(vector<int>& nums) {

        long long ans = 0 ;
        int n = nums.size() ;
        vector<int> st ;
        unordered_map<int,int> mpp ;

        // for ( int i = 0 ; i < n ; i++ ) {

        //     while ( !st.empty() && st.back() > nums[i] ) st.pop_back() ;

        //     int x = lower_bound( st.begin() , st.end() , nums[i] ) - st.begin() ;

        //     ans += x ;

        //     st.push_back(nums[i]) ;

        // }

        for ( auto it : nums ) {

            while ( !st.empty() && st.back() > it ) {
                
                mpp[st.back()]-- ;
                st.pop_back() ;

            }

            int x = st.size() - mpp[it] ;
            
            ans += x ;

            mpp[it]++ ;
            st.push_back(it) ;

        }

        return ans ;
        
    }
};