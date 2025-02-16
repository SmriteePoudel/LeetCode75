//You are given an integer array height of length n. There are n vertical lines drawn such that the two endpoints of the ith line are (i, 0) and (i, height[i]).
//Find two lines that together with the x-axis form a container, such that the container contains the most water.
//Return the maximum amount of water a container can store.


#include <vector>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxWater = 0;
        int left = 0;
        int right = height.size() - 1;
        
        while (left < right) {
            // Calculate width between two lines
            int width = right - left;
            
            // Height of container is limited by the shorter line
            int containerHeight = min(height[left], height[right]);
            
            // Calculate area
            int currentArea = width * containerHeight;
            
            // Update maximum area if current area is larger
            maxWater = max(maxWater, currentArea);
            
            // Move the pointer pointing to shorter line
            // Since keeping it won't give us a larger area
            if (height[left] < height[right]) {
                left++;
            } else {
                right--;
            }
        }
        
        return maxWater;
    }
};