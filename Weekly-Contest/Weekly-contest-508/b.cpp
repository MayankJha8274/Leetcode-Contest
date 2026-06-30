class Solution {
public:
    vector<vector<int>> filterOccupiedIntervals(vector<vector<int>>& occupiedIntervals, int freeStart, int freeEnd) {
        vector<vector<int>> ans;
        int n = occupiedIntervals.size();
        sort(occupiedIntervals.begin() , occupiedIntervals.end());

        vector<vector<int>> occupied;
        int currStart = occupiedIntervals[0][0];
        int currEnd = occupiedIntervals[0][1];

        for(int i = 1 ; i<n ; i++){
            if (occupiedIntervals[i][0] <= currEnd + 1) {
                currEnd = max(currEnd, occupiedIntervals[i][1]);
            }
            else {
                occupied.push_back({currStart, currEnd});
                currStart = occupiedIntervals[i][0];
                currEnd = occupiedIntervals[i][1];
            }
        }
        occupied.push_back({currStart, currEnd});


        for (int i = 0 ; i<occupied.size() ; i++) {

            int left = occupied[i][0];
            int right = occupied[i][1];

            if (right < freeStart || left > freeEnd) {
                ans.push_back({left, right});
            }
            else {
                if (left < freeStart) {
                    ans.push_back({left, freeStart - 1});
                }

                if (right > freeEnd) {
                    ans.push_back({freeEnd + 1, right});
                }
            }
        }
        return ans;
    }
};