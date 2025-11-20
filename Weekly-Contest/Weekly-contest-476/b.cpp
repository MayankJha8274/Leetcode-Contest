class Solution {
public:
    int minLengthAfterRemovals(string s) {

      /*  stack<char> st ;

        for ( auto it : s ) {

            if ( !st.empty() && st.top() == 'a' && it == 'b'  ) st.pop() ;

            else if ( !st.empty() && st.top() == 'b' && it == 'a' ) st.pop() ;

            else st.push(it) ;
            
        }

       return st.size() ; */

       int cnt_a = 0 ;
       int cnt_b = 0 ;

       for ( auto it : s ) {

          if ( it == 'a' ) cnt_a++;

          else cnt_b++;

       }

       return abs( cnt_a - cnt_b ) ;

         // T.C = O( N )
         // S.C = O( 1 )
        
    }
};