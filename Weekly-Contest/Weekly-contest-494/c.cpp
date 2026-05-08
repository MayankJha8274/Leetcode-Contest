class Solution {
public:
    // man/meeet in the middle approach
    // step1 -> divide array in half part , left , right
    // step2 -> find all subsets xors of both halfs
    // step3 -> left ^ right = target --> left = target ^ right
    // step4 -> return left , right subset size

    void subset( vector<int>& nums , vector<pair<int,int>>& ans , int i , 
    int n , int curr , int size ) {

        // base case
        if ( i == n ) {

            ans.push_back( { curr  , size } ) ;
            return ;

        }

        // take
        subset( nums , ans , i+1 , n , curr ^ nums[i] , size + 1 ) ;

        // not-take
        subset( nums , ans , i+1 , n , curr , size ) ;

    }

    int minRemovals(vector<int>& nums, int target) {

        int n = nums.size() ;

        vector<int> left , right ;

        for ( int i = 0 ; i < n/2 ; i++ ) left.push_back( nums[i] ) ;

        for ( int i = n/2 ; i < n ; i++ ) right.push_back( nums[i] ) ;

        vector<pair<int,int>> left_xor , right_xor ;
        
        // left xor formation
        subset( left , left_xor , 0 , left.size() , 0 , 0 ) ;

        // rightt xor formation
        subset( right , right_xor , 0 , right.size() , 0 , 0 ) ;

        // final boss step
        // mpp[left_xor] = size of left_xor
        // needed = right_xor ^ target
        // if ( mpp.find(needed) != mpp.end() ) add both sizes

        unordered_map<int,int> mpp ;

        int maxi = INT_MIN ;

        for ( auto it : left_xor ) mpp[it.first] = max(it.second , mpp[it.first]) ;

        for ( auto it : right_xor ) {

            int val = it.first ;
            int sz = it.second ;

            int needed = val ^ target ;

            if ( mpp.find(needed) != mpp.end() ) maxi = max( maxi , (int)sz + mpp[needed] ) ;

        }

        if ( maxi == INT_MIN ) return -1 ;

        return n-maxi ;
        
    }
};