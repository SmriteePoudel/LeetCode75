//Merge Sorted Array
class Solution {
    public:
        void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
            // Start from the end of both arrays
            int i = m - 1;     // Last element in nums1
            int j = n - 1;     // Last element in nums2
            int k = m + n - 1; // Last position in merged array (nums1)
            
            // While there are elements in both arrays
            while (i >= 0 && j >= 0) {
                // Place the larger element at the end of nums1
                if (nums1[i] > nums2[j]) {
                    nums1[k--] = nums1[i--];
                } else {
                    nums1[k--] = nums2[j--];
                }
            }
            
            // If there are remaining elements in nums2
            // (No need to handle remaining elements in nums1 as they're already in place)
            while (j >= 0) {
                nums1[k--] = nums2[j--];
            }
        }
    };