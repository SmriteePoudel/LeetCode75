//Dota2 Senate 

#include <string>
#include <queue>
using namespace std;

class Solution {
public:
    string predictPartyVictory(string senate) {
        int n = senate.length();
        queue<int> radiant, dire;
        
        // Separate senators into two queues based on their party
        // Store their positions in the original sequence
        for(int i = 0; i < n; i++) {
            if(senate[i] == 'R')
                radiant.push(i);
            else
                dire.push(i);
        }
        
        // Simulate the voting process
        while(!radiant.empty() && !dire.empty()) {
            int r_index = radiant.front();
            int d_index = dire.front();
            radiant.pop();
            dire.pop();
            
            // The senator with smaller index bans the other one
            // The winning senator gets to vote again in the next round
            // by being pushed to the back of their queue with index + n
            if(r_index < d_index)
                radiant.push(r_index + n);
            else
                dire.push(d_index + n);
        }
        
        // Return the party that still has senators with voting rights
        return radiant.empty() ? "Dire" : "Radiant";
    }
};