/*
628. Maximum Product of Three Numbers
Easy

1155

374

Add to List

Share
Given an integer array, find three numbers whose product is maximum and output the maximum product.

Example 1:

Input: [1,2,3]
Output: 6
 

Example 2:

Input: [1,2,3,4]
Output: 24
 

Note:

The length of the given array will be in range [3,104] and all elements are in the range [-1000, 1000].
Multiplication of any three numbers in the input won't exceed the range of 32-bit signed integer.
 

Accepted
118,437
Submissions
251,557
*/
class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        return max(nums[0]*nums[1]*nums[2],nums[0]*nums[nums.size()-2]*nums[nums.size()-1]);
    }
};
//-4 -3 -2 -1 60