class Solution {
public:
    // step 1 -> create freq array of size 26 to track character freq and last occurance
    // step 2 -> if j-i <= k merges the character
    string mergeCharacters(string s, int k) {

        int n = s.size() ;
        int del_cnt = 0 ;
        string ans = "" ;

        vector<int> freq( 26 , -1 ) ;

        for ( int i = 0 ; i < n ; i++ ) {

            int curr_idx = i - del_cnt ;
            int character = s[i] - 'a' ;

            // first occurance of character
            if ( freq[s[i]-'a'] == -1 ) {
                
                freq[s[i]-'a'] = curr_idx ;
                ans += s[i] ;

            }

            // not first occurance
            else {

                // j-i <= k
                if ( curr_idx - freq[s[i]-'a'] <= k ) del_cnt++ ;

                // if j-i > k 
                else {

                    ans += s[i] ;
                    freq[s[i]-'a'] = curr_idx ;

                }

             }

        }

        return ans ;
        
    }
};