class Solution {
private:
    /*string decimalToBinary( int num ) {

        bitset<32> b( num ) ;
        
        string s = b.to_string() ;
        int pos = s.find('1') ;
        s = s.substr( pos ) ;

        reverse( s.begin() , s.end() ) ;

        return s ;

    }*/

    string decimalToBinary( int num ) {

        string s = "" ;

        while ( num > 0 ) {

            s += char( ( num % 2 ) + '0' ) ;
            num /= 2 ;

        }

      //  reverse( s.begin() , s.end() ) ; ----> string s is already in reverse form there is no need to reverse again

        return s ;

    }

    int binaryToDecimal( string num ) {

        int power = 0 ;
        int number = 0 ;

        for ( int i = num.size() - 1 ; i >= 0 ; i-- ) {

            number += ( pow( 2 , power ) * ( num[i] - '0' ) ) ;
            power++ ;

        }

        return number ;

    }

public:
    vector<int> sortByReflection(vector<int>& nums) {

        vector<pair<int,int>> mpp ;

        for ( int i = 0 ; i < nums.size() ; i++ ) {

            string binaryRev = decimalToBinary( nums[i] ) ;
            int decimal = binaryToDecimal( binaryRev ) ;

            mpp.push_back( { decimal , nums[i] } ) ;

        }

        sort( mpp.begin() , mpp.end() ) ;

        vector<int> ans ;

        for ( auto it : mpp ) ans.push_back( it.second ) ;

        return ans ;
        
    }
}; 