class Solution {
public:
    // welcome Harleen my bestie .
    // Thanks for giving all those efforts . forever gratefull to have u .

    // step1 -> convert to string ----> generate all permutation and store in array
    // step2 -> traverse on array calculate sum and match
    // T.C = total digit at max = 10 = 10! = 3 X 10^6 
    // 3 X 10^6 X 10 = 3 X 10^6

    int factorial( int n ) {

        if ( n == 0 ) return 1 ;

        int ans = 1 ;

        for ( int i = 1 ; i <= n ; i++ ) ans *= i ;

        return ans ;

    }

    bool isDigitorialPermutation(int n) {

        vector<string> allper ;

        string str = to_string(n) ;

        sort( str.begin() , str.end() ) ;

        allper.push_back( str ) ;

        while ( next_permutation( str.begin() , str.end() ) )
        allper.push_back( str ) ;

        for ( auto it : allper ) {

            if ( it[0] - '0' == 0 ) continue ;

            int curr = stoi( it ) ;

            int final = 0 ;

            for ( int i = 0 ; i < it.size() ; i++ ) {

                int val = factorial( it[i] - '0' ) ;
                final += val ;

            }

            if ( final == curr ) return true ;

        }

        return false ;

    }
};

// 4! = 4x3x2 = 24 , 5! = 120 , 1! = 1 ---> 120+24+1 = 145