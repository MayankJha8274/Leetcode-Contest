class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {

        typedef long long ll ;

        // approach 1

       /* priority_queue< pair<int,int> > maxHeap ;

        priority_queue<pair<int,int> , vector<pair<int,int>> , 
        greater<pair<int,int>>> minHeap ;

        ll cnt = 0 ;

        int n = nums.size() ;
        int i = 0 ;
        
        for ( int j = 0 ; j < n ; j++ ) {

            maxHeap.push( { nums[j] , j } ) ;
            minHeap.push( { nums[j] , j } ) ;

            while ( i <= j ) {

                ll maxi = maxHeap.top().first ;
                ll mini = minHeap.top().first ;
                

                if ( ( maxi - mini ) * ( j - i + 1 ) <= k ) break ;

                i++ ;

                while ( !maxHeap.empty() && i > maxHeap.top().second ) maxHeap.pop() ;

                while ( !minHeap.empty() && i > minHeap.top().second ) minHeap.pop() ;
                
            }

            cnt += (ll)( j - i + 1 ) ;
            
        }

        return cnt ; */

        // approach 2 

        ll cnt = 0 ;

        multiset<int> s ;

        int i = 0 ;
        int j = 0 ;

        int n = nums.size() ;

        while ( j < n ) {
            
            s.insert( nums[j] ) ;

            while ( abs( *s.rbegin() - *s.begin() ) * 1LL * ( j - i + 1 ) > k ) {

                s.erase( s.find(nums[i]) ) ;
                i++ ;

            }

            cnt += ( j - i + 1 ) ;
            j++ ;

        }

        return cnt ;
        
    }
};