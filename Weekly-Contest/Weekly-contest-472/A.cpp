class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {

        unordered_map<int,int> mpp ;

        for ( auto it : nums ) mpp[it]++ ;

        for ( int i = k ; i <= 10000 ; i = i+k ) {

            if ( mpp.find(i) == mpp.end() ) return i ;
            
        }

        return -1 ;

        // T.C = O( N )
        // S.C = O( N )
        
    }

};
