class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {

        // 20 -> 1 , 10 -> 1 , 30 -> 2 
        // 1 -> 2 , 2 -> 1

        unordered_map<int,int> mpp1 ;
        unordered_map<int,int> mpp2 ;

        for ( auto it : nums ) mpp1[it]++ ;

        for ( auto it : mpp1 ) mpp2[it.second]++ ;

        for ( auto it : nums ) {

            int freq1 = mpp1[it] ;

            if ( mpp2[freq1] == 1 ) return it ;

        }

        return -1 ;
        
    }
};