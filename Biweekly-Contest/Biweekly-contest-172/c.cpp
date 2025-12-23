class Solution {
public:
    long long maximumScore(vector<int>& nums, string s) {

        priority_queue<int> maxHeap;
        
        long long ans = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            if ( s[i] == '0' ) maxHeap.push( nums[i] ) ;

            else {

                maxHeap.push( nums[i] ) ;
                ans += maxHeap.top() ;
                maxHeap.pop() ;

            }

        }

        return ans ; 

        // T.C = O(NLOGN)
        // S.C = O(N)
        
    }
};