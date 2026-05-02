#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        sort(nums.begin(),nums.end());
        int final_sum = 0;
        int difference = INT_MAX;
        int n = nums.size();


        for(int i = 0 ; i  < n-2 ; i++){
            
            int left = i+1;
            int right = n-1;
            
            
            while(left < right){
                int s = nums[i]+nums[left]+nums[right];
                int local_dif = abs(s-target);
                
                if(local_dif < difference){
                    difference = local_dif;
                    final_sum = s;
                }
                
                if(s == target){
                    return final_sum;
                }else if(s < target){
                    left++;
                }else{
                    right--;
                }
            }
        }
        return final_sum;
    }
};