class Solution {
public:
    long long minOperations(vector<int>& nums1, vector<int>& nums2) {
        
        int n = nums1.size() ;
        int last = nums2[n] ;

        long long ans = 0 ; 
        int best = 1e9 ;

        for ( int i = 0 ; i < n ; i++ ) {

            ans += abs( nums1[i] - nums2[i] ) ;

            if ( last >= min( nums1[i] , nums2[i] ) && last <= max( nums1[i] , nums2[i] ) ) best = 1 ;

            else best = min( best , 1 + min( abs( nums1[i] - last ) , abs( nums2[i] - last ))) ;

        }
         
         return ans + best ;

         // T.C = O( n ) 
         // S.C = O( 1 )
  
    }
};