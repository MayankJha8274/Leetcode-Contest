class Solution {
public:
    int elevatorRequests(int n, vector<int>& requests) {

        int time = 0 ;
        int f = 0 ;

        for ( int i = 0 ; i < requests.size() ; i++ ) {

            time += abs( requests[i] - f ) ;
            f = requests[i] ;
            
        }

        return time ;
        
    }
};