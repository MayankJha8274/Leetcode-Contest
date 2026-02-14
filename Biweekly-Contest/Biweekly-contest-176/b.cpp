class Solution {
public:
    int prefixConnected(vector<string>& words, int k) {

        vector<string> ans ;

        for ( int i = 0 ; i < words.size() ; i++ ) {

            // string str = "" ;

            // for ( int j = 0 ; j < words[i].size() ; j++ ) {

            //     for ( int z = 0 ; z < k ; z++ ) {

            //         str += words[i][j] ;
                    
            //     } 
            // }

            if ( words[i].size() < k ) continue ;

            string str = "" ;

            for ( int j = 0 ; j < k ; j++ ) {

                str += words[i][j] ;
                
            }

            ans.push_back(str) ;
            
        }

        unordered_map<string , int> mpp ;

        for ( auto it : ans ) mpp[it]++ ;

        int cnt = 0 ;

        for ( auto it : mpp ) {

            if ( it.second >= 2 ) cnt++ ;
            
        }

        return cnt ;
        
    }
};©leetcode