class Solution {
public:
    vector<double> internalAngles(vector<int>& sides) {

        double a = sides[0] ;
        double b = sides[1] ;
        double c = sides[2] ;

        // triangle validity
        if ( a + b <= c || b + c <= a || c + a <= b ) return { } ;

        // law of cosine ( cos inverse = acos )
        double A = acos(( b*b + c*c - a*a ) / ( 2*b*c )) * 180.0 / M_PI ;
        double B = acos(( a*a + c*c - b*b ) / ( 2*a*c )) * 180.0 / M_PI ;
        double C = acos(( b*b + a*a - c*c ) / ( 2*b*a )) * 180.0 / M_PI ;

        vector<double> ans = {A,B,C} ;

        sort( ans.begin() , ans.end() ) ;

        return ans ;
        
        
    }
};