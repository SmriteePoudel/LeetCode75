//Design a Number Container System
//Design a number container system that can do the following:

//Insert or Replace a number at the given index in the system.
//Return the smallest index for the given number in the system.
//Implement the NumberContainers class:

//NumberContainers() Initializes the number container system.
//void change(int index, int number) Fills the container at index with the number. If there is already a number at that index, replace it.
//int find(int number) Returns the smallest index for the given number, or -1 if there is no index that is filled by number in the system.


#include <unordered_map>
#include <set>

class NumberContainers {
private:
    // Maps index to number
    std::unordered_map<int, int> indexToNum;
    // Maps number to set of indices (ordered automatically)
    std::unordered_map<int, std::set<int>> numToIndices;
    
public:
    NumberContainers() {
        // Initialize empty containers
    }
    
    void change(int index, int number) {
        // If index already has a number, remove it from the old number's set
        if (indexToNum.count(index)) {
            int oldNum = indexToNum[index];
            numToIndices[oldNum].erase(index);
            // If no more indices contain this number, remove the entry
            if (numToIndices[oldNum].empty()) {
                numToIndices.erase(oldNum);
            }
        }
        
        // Update the mappings
        indexToNum[index] = number;
        numToIndices[number].insert(index);
    }
    
    int find(int number) {
        // If number exists in our system, return its smallest index
        if (numToIndices.count(number) && !numToIndices[number].empty()) {
            return *numToIndices[number].begin();
        }
        return -1;
    }
};