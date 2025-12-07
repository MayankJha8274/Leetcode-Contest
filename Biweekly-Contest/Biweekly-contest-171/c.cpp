class Solution {
public:
    long long maxPoints(vector<int>& t1, vector<int>& t2, int k) {
        
        vector<pair<int,int>> mpp ;

        for ( int i = 0 ; i < t1.size() ; i++ ) {

            mpp.push_back( { t2[i] - t1[i] , i } ) ;

        }

        sort( mpp.begin() , mpp.end() ) ;

        long long ans = 0 ;

        for ( int i = 0 ; i < k ; i++ ) {

            int idx = mpp[i].second ;
            ans += t1[idx] ;

        }

        for ( int i = k ; i < t1.size() ; i++ ) {

            int idx = mpp[i].second ;
            ans += max( t1[idx] , t2[idx] ) ;

        }

        return ans ;

        // T.C = O(NLOGN)
        // S.C = O(N)

    }
};