class Solution {
public:
    int findMaxVal(int n, vector<vector<int>>& restrictions, vector<int>& diff) {

        vector<int> arr( n , INT_MAX ) ;
        
        // condition 1 -> satisfy
        arr[0] = 0 ;

        // condition 2 -> already satisfy

        // condition 4 -> satisfy
        for( auto it : restrictions ) {

            arr[it[0]] = it[1] ;

        }

        // condition 3 -> satisfy
        for ( int i = 0 ; i < n-1 ; i++ ) {

            arr[i+1] = min( arr[i+1] , arr[i] + diff[i] ) ;

        }

        for ( int i = n-2 ; i >= 0 ; i-- ) {

            arr[i] = min( arr[i] , arr[i+1] + diff[i] ) ;
            
        }

        return *max_element( arr.begin() , arr.end() ) ;

        // T.C = S.C = O(N)
        
    }
};