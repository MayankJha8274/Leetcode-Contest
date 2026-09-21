class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {

        int n = nums.size() ;

        unordered_map<int,vector<int>> mpp ;

        int cnt = 0 ;

        for ( int i = 0 ; i < n ; i++ ) mpp[nums[i]].push_back(i) ;

        for ( auto& it : mpp ) {

            vector<int>& pos = it.second ;

            if ( pos.size() < 3 ) continue ;

            bool flag = true ;

            int prevDis = pos[1]-pos[0] ;

            for ( int i = 1 ; i < pos.size() ; i++ ) {

                int currDis = pos[i]-pos[i-1] ;

                if ( prevDis != currDis ) {

                    flag = false ;
                    break ;

                }
            }

            if ( flag ) cnt++ ;

        }

        return cnt ;
        
    }
};