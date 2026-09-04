class Solution {
public:
    vector<vector<int>> aggregateTimeSeries(vector<vector<int>>& s1, vector<vector<int>>& s2) {

        int n1 = s1.size() ;
        int n2 = s2.size() ;

        vector<vector<int>> ans ;

        int i = 0 ;
        int j = 0 ;

        while ( i < n1 && j < n2 ) {

            int t1 = s1[i][0] ;
            int v1 = s1[i][1] ;
            int t2 = s2[j][0] ;
            int v2 = s2[j][1] ;

            if ( t1 < t2 ) {

                ans.push_back({t1 , v1+v2}) ;
                i++ ;
                
            }

            else if ( t2 < t1 ) {

                ans.push_back({ t2 , v1+v2 }) ;
                j++ ;
                
            }

            else {

                ans.push_back({ t1 , v1+v2 }) ;
                i++ ;
                j++ ;
                
            }
        }

        while ( i < n1 ) {
            
            ans.push_back({s1[i][0] , s1[i][1]}) ;
            i++ ;

        }

        while ( j < n2 ) {

            ans.push_back({ s2[j][0] , s2[j][1]}) ;
            j++ ;
            
        }

        return ans ;
        
    }
};