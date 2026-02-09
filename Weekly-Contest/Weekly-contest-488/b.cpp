class Solution {
public:
    vector<long long> mergeAdjacent(vector<int>& nums) {

        vector<long long> ans ;

        stack<long long> st ;

        for ( auto it : nums ) {

            long long curr = it ;

            while ( !st.empty() && st.top() == curr ) {

                curr = st.top() + curr ;
                st.pop() ;
               // st.push(sum) ;
                
            }

            st.push(curr) ;
            
        }

        while ( !st.empty() ) {

            long long value = st.top() ; st.pop() ;
            ans.push_back(value) ;
            
        }

        reverse( ans.begin() , ans.end() ) ;

        return ans ;
        
    }
};