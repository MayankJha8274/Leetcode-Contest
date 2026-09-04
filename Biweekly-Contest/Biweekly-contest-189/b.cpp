class Solution {
public:
    int minOperations(string s) {

        int n = s.size() ;
        int mini = INT_MAX ;

        for ( int rotation = 0 ; rotation < n ; rotation++ ) {

            int ops = rotation ;
            string st = s ;
            rotate(st.begin() + rotation, st.end());

            for ( int i = 0 ; i < n/2 ; i++ ) {

                char left = st[i] ;
                char right = st[n-i-1] ;

                int normal_operation = abs(right-left) ;
                int cyclic_operation = 26 - normal_operation ;

                ops += min( normal_operation , cyclic_operation ) ;

            }

            mini = min( ops , mini ) ;

        }

        return mini ;
        
    }
};