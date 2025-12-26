class Solution {
private:
    int rev(int n) {

        int ans = 0 ;

        while(n) {

            int num = n % 10 ;
            ans = ans * 10 + num ;
            n = n/10 ;
            
        }

        return ans ;
        
    }
public:
    int mirrorDistance(int n) {

        int number = rev(n) ;

        return abs( number - n ) ;
        
    }
};