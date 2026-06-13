class Solution {
public:
    int digitFrequencyScore(int n) {

        // unordered_map<int,int> mpp ;

        // int j = n ;

        // while ( j ) {

        //     int dig = j % 10 ;
        //     mpp[dig]++ ;
        //     j /= 10 ;
            
        // }
        

        // long long sum = 0 ;

        // for ( auto it : mpp ) {

        //     sum += 1LL * it.first * it.second ;
            
        // }

        // return sum ;

        string dig = to_string(n) ;

        unordered_map<char,int> mpp ;

        for ( auto it : dig ) mpp[it]++ ;

        int sum = 0 ;

        for ( auto it : mpp ) {

            sum += ( it.second ) * ( it.first - '0' ) ;

        }

        return sum ;
        
    }
};