class Solution {
public:
    int maxDistinct(string s) {

        int n = s.size() ;

        unordered_map<char,int> mpp ;

        for ( auto it : s ) mpp[it]++ ;

        return mpp.size() ;

        
        
    }
}