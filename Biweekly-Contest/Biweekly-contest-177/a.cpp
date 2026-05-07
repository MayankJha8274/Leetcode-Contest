class Solution {
public:
    vector<int> minDistinctFreqPair(vector<int>& nums) {

        map<int,int> mpp ;

        for ( auto it : nums ) mpp[it]++ ;

        sort( nums.begin() , nums.end() ) ;

        int first = nums[0] ;
        int first_freq = mpp[nums[0]] ;

        int other = -1 ;

        for ( auto it : nums ) {

            if ( it == first ) continue ;

            else if ( it != first && mpp[it] != first_freq ) {

                other = it ;
                break ;
                
            }
        }

        if ( other == -1 ) return { -1 , -1 } ;

        return { first , other } ;
        
    }
};