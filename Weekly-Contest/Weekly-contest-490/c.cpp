class Solution {
public:
    string maximumXor(string s, string t) {

        // step 1 -> cnt 0,1 in t
        // step 2 -> if s[i] == 1 ok hai else 1 dalo vaha by checking freq of 1 in t

        string ans = "" ;

        int n = t.size() ;

        int zero_cnt = 0 ;
        int one_cnt = 0 ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( t[i] == '1' ) one_cnt++ ;

            else zero_cnt++ ;

        }
        
        for ( int i = 0 ; i < n ; i++ ) {

            if ( s[i] == '1' ) {

                if ( zero_cnt ) {
                    
                    ans += '1' ;
                    zero_cnt-- ;

                }

                else {

                    ans += '0' ;
                    one_cnt-- ;

                }
            }

            else {

                if ( one_cnt ) {

                    ans += '1' ;
                    one_cnt-- ;

                }

                else {

                    ans += '0' ;
                    zero_cnt-- ;

                }
            }
        }

        return ans ;
        
    }
};