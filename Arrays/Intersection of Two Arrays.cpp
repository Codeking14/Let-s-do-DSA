// Leetcode Problem #350. Intersection of Two Arrays II

/* Given two integer arrays nums1 and nums2, return an array of their intersection. Each element in the result must appear as many times as it shows in both arrays and you may return the result in any order. */

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector <int> ans;
      
      // Sort both the arrays
        sort (nums1.begin(), nums1.end());
        sort (nums2.begin(), nums2.end());
      
        for (int i=0, j=0 ; i<nums1.size() && j<nums2.size(); )
        {
            if (nums1[i] == nums2[j])
            {
                ans.push_back(nums1[i]);
                i++;
                j++;
            }
            else if (nums1[i] < nums2[j])
            {
                i++;
            }
            else
                j++;
        }
        return ans;
    }
};
