#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <iterator>

using namespace std;

/*

💡 Given an integer array nums, return true if any value appears at least twice in the array, and return false if every element is distinct.

**Example 1:**
Input: nums = [1,2,3,1]

Output: true


*/


void moveZeroes(vector<int>& nums) {
    int step = 0;
    for(int i = 0;i<nums.size();i++){
        if(nums[i]!=0){
            nums[step] = nums[i];
            step++;
        }
    }
    while(step<nums.size()){
        nums[step]=0;
        step++;
        }
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input7.txt","r",stdin);
    #endif

    int t = 1;
    cin>>t;
    while(t--){
        int n;

        cin>>n;

        vector<int> arr(n);

        for(int i = 0;i<n;i++){
            cin>>arr[i];
        }

        moveZeroes(arr);

        for(int i: arr){
                cout<<i<<" ";
            }
            cout<<endl;

    }

    return 0;
}