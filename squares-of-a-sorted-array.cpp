#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
       
       vector<int>res(nums.size());
       int left = 0; int right = nums.size()-1; int k = nums.size()-1;

       while(left <= right){

        if(abs(nums[left]) > abs(nums[right])){
            res[k--] = nums[left]*nums[left];
            left++;
        }else{
            res[k--] = nums[right]*nums[right];
            right--;
        }
       }
        return res;
    }
};