#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

/*

An array is monotonic if it is either monotone increasing or monotone decreasing.

An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is
monotone decreasing if for all i <= j, nums[i] >= nums[j].

Given an integer array nums, return true if the given array is monotonic, or false otherwise.

Example 1:
Input: nums = [1,2,2,3]
Output: true

*/



bool solve(vector<int>& nums) {
    int prev = nums[0];
    int direction = 0;
    for(int i: nums){
        if(direction<0){
            if(i>prev)
            return false;
        }
        else if(direction>0){
            if(i<prev)
            return false;
        }
        else 
            direction = i-prev;

        prev = i;
    }

    return true;
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
        vector<int> ar(n);

        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }

        bool ans = solve(ar);

        cout<<ans<<endl;
    }

    return 0;
}