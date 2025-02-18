//Finding highest altitude
//There is a biker going on a road trip. The road trip consists of n + 1 points at different altitudes. The biker starts his trip on point 0 with altitude equal 0.

//You are given an integer array gain of length n where gain[i] is the net gain in altitude between points i​​​​​​ and i + 1 for all (0 <= i < n). Return the highest altitude of a point.

class Solution {
    public:
        int largestAltitude(vector<int>& gain) {
            int currentAltitude = 0;  // Starting altitude is 0
            int maxAltitude = 0;      // To track the highest altitude reached
            
            // Iterate through the gain array
            for(int i = 0; i < gain.size(); i++) {
                currentAltitude += gain[i];  // Add the gain/loss to current altitude
                maxAltitude = max(maxAltitude, currentAltitude);  // Update max if needed
            }
            
            return maxAltitude;
        }
    };