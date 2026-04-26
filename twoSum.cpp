#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        //sort(numbers.begin(),numbers.end());
        vector<int> ans;
        int j = numbers.size()-1;
        int i = 0;

        while(i <= j){
            
            if((numbers[i]+numbers[j]) == target){
                ans.push_back(i+1);ans.push_back(j+1);
                break;
            }else if((numbers[i]+numbers[j]) > target){ 
                j--;
            }else{
                i++;
            }

        }
        return ans;
    }
};