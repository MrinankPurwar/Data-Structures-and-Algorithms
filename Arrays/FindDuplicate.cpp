Given an array of integers nums containing n + 1 integers where each integer is in the range [1, n] inclusive.
There is only one repeated number in nums, return this repeated number.
You must solve the problem without modifying the array nums and uses only constant extra space.

Example :
Input: nums = [1,3,4,2,2]
Output: 2

CODE:
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        for(int i=0; i<nums.size(); i++){
            if(nums[i] == nums[i+1])
                return nums[i];
        }
        return -1;    
    }
};

NOTE: This is only a function, please write main() with the matching formatting