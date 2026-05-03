#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class solution{
    public:
        int countTrplets(vector<int>&arr, int sum){

            sort(arr.begin(),arr.end());
            int count = 0;
            int n = arr.size();

            for(int i = 0 ; i < n-2 ; i++){

                int left = i+1;
                int right = n-1;

                while(left < right){

                    int local_sum = arr[i]+arr[left]+arr[right];

                    if(local_sum < sum){
                        count+=(right-left);
                        left++;
                    }else{
                        right--;
                    }
                }
            }
            return count;
        }
};
