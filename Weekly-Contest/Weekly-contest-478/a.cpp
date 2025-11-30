/*class Solution {
public:
    int countElements(vector<int>& nums, int k) {

        int ans = 0 ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            priority_queue<int> pq( nums.begin() , nums.end() ) ;

            int cnt = 0 ;

            while ( pq.top() > nums[i] ) {

                pq.top() ;
                pq.pop() ;
                cnt++ ;
                
            }

            if ( cnt >= k ) ans++ ;

            pq = priority_queue<int>() ;
            
        }

        return ans ;
        
    }
};*/

class Solution {
public:
    int countElements(vector<int>& nums, int k) {

        sort( nums.begin() , nums.end() ) ;

        int n = nums.size() ;
        int ans = 0 ;

        for ( auto it : nums ) {

            int idx = upper_bound( nums.begin() , nums.end() , it ) - nums.begin() ;
            int dis = n - idx ;

            if ( dis >= k ) ans++ ;
            
        }

        return ans ;
        
    }
}