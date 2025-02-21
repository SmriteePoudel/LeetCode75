//Number of Recent Calls

class RecentCounter {
    private:
        queue<int> requests;
        
    public:
        RecentCounter() {
            // Initialize empty queue
        }
        
        int ping(int t) {
            // Add current request
            requests.push(t);
            
            // Remove requests older than t - 3000
            while (!requests.empty() && requests.front() < t - 3000) {
                requests.pop();
            }
            
            // Return count of remaining requests
            return requests.size();
        }
    };