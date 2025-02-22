//Asteroid Collision

class Solution {
    public:
        vector<int> asteroidCollision(vector<int>& asteroids) {
            vector<int> stack;
            
            for (int asteroid : asteroids) {
                bool survives = true;
                
                // Keep checking collisions while we have asteroids moving right
                // and current asteroid is moving left
                while (!stack.empty() && asteroid < 0 && stack.back() > 0) {
                    // If current asteroid is larger, destroy the last asteroid in stack
                    if (abs(asteroid) > stack.back()) {
                        stack.pop_back();
                        continue;
                    }
                    // If equal size, both destroy each other
                    else if (abs(asteroid) == stack.back()) {
                        stack.pop_back();
                        survives = false;
                        break;
                    }
                    // If current asteroid is smaller, it gets destroyed
                    else {
                        survives = false;
                        break;
                    }
                }
                
                if (survives) {
                    stack.push_back(asteroid);
                }
            }
            
            return stack;
        }
    };