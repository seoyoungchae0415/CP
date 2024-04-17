#include <iostream>
#include <algorithm>

class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        vector<bool> returnarray;
        int max = -1;

        for(int i : candies) {
            //ae = std::max(i, ae);
            
            if(max < i) {
                max = i;
            }
            
        }

        for(int i : candies) {
            if(i + extraCandies >= max)
                returnarray.push_back(true);
            else
                returnarray.push_back(false);
        }

        return returnarray;
    }
};
