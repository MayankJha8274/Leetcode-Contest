class Solution {
public:
    int totalWaviness(int num1, int num2) {

        int cnt = 0 ;

        for ( int i = num1 ; i <= num2 ; i++ ) {

            string num = to_string(i) ;

            int j = 1 ;
            int n = num.size() ;

            if ( n < 3 ) continue ;

            while ( j < n-1 ) {

                if ( ( num[j] > num[j-1] && num[j] > num[j+1] ) ||
                   ( num[j] < num[j-1] && num[j] < num[j+1] ) ) cnt++;

                j++;
                
            }
        }

        return cnt ;

        // T.C. : O( (num2 - num1) * log(num2) )
        // S.C. : O(log(num2))
        
    }
};