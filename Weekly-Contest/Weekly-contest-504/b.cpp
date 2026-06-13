class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size() ;

        vector<int> extra( n , 0 );

        for (int i = 0; i < n; i++) {

            for (int j = 0; j < n; j++) {

                if (i == j) continue;

                if (items[j][0] % items[i][0] == 0) {
                    extra[i]++;
                    
                }
            }
        }

        vector<int> dp(budget + 1, 0);

        for (int i = 0; i < n; i++) {

            int cost = items[i][1];
            int add = extra[i];

            vector<int> dp1 = dp;

            for (int j = budget; j >= cost; j--) {

                dp1[j] = max( dp1[j] , dp[j-cost] + add + 1 ) ;
                   
            }

            for (int j = cost; j <= budget; j++) {

                dp1[j] = max( dp1[j] , dp1[j-cost] + 1 ) ;
                   
            }

            dp = dp1;
            
        }

        return *max_element(dp.begin(), dp.end());
        
    }
};