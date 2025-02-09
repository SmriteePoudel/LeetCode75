//Can Place Flowers
//You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots.
//Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.


#include <vector>
using namespace std;

class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int size = flowerbed.size();
        int count = 0;

        for (int i = 0; i < size; ++i) {
            // Check if current plot is empty
            if (flowerbed[i] == 0) {
                // Check if the left and right plots are empty or out of bounds
                bool emptyLeft = (i == 0) || (flowerbed[i - 1] == 0);
                bool emptyRight = (i == size - 1) || (flowerbed[i + 1] == 0);

                if (emptyLeft && emptyRight) {
                    flowerbed[i] = 1;  // Plant the flower
                    count++;          // Increment the count of planted flowers

                    if (count >= n) {
                        return true;  // Early exit if we've planted enough flowers
                    }
                }
            }
        }

        return count >= n;
    }
};
