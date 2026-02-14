class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {

        vector<int>mpp ( 26 , 0 ) ;

        // for ( int i = 0 ; i < mpp.size() ; i++ ) {

        //     mpp[i] = w[i] ;
            
        // }

        string ans = "" ;

        for ( auto it : words ) {

            int sum = 0 ;

            for ( int i = 0 ; i < it.size() ; i++ ) {

                sum += weights[it[i]-'a'] ;
                
            }

            sum = sum % 26 ;

            int idx = 25 - sum ;

            ans += ( idx + 'a' ) ;
            
        }

        return ans ;
        
    }
};©leetcode