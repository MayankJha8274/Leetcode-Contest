class Solution {
public:
    int scoreDifference(vector<int>& nums) {

        // intitally player1 = active , player2 = inactive
        // if ( nums[i] % 2 == 1 ) ----> swap( active , inactive )
        // if ( i % 6 == 5 )  ----> swap( active , inactive )

        int n = nums.size() ;
        int score = 0 ;

        int player1 = 0 ;
        int player2 = 0 ;

        bool isPlayer1Active = true ;

        for ( int i = 0 ; i < n ; i++ ) {

            if ( nums[i] % 2 == 1 ) isPlayer1Active = !isPlayer1Active ;

            if ( i % 6 == 5 ) isPlayer1Active = !isPlayer1Active ;

            if ( !isPlayer1Active ) player2 += nums[i] ;

            else if ( isPlayer1Active ) player1 += nums[i] ;

        }

        return player1 - player2 ;

    }
};