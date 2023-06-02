#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*

Given an integer array nums of length n and an integer target, find three integers
in nums such that the sum is closest to the target.
Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2

Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

*/
int checkClosest(vector<int>& nums,int ind,int ans,int& mdif,int target){
    int l = ind+1;
    int h = nums.size()-1;
    int sum,dif;
    while(l<h){
        sum = nums[ind]+nums[l]+nums[h];
        dif = (sum-target);
        if(mdif>abs(dif)){
            mdif = abs(dif);
            ans = sum;
        }
        else if(dif<0)
            l++;
        else
            h--;
    }
    return ans;
}
int solve(vector<int>& nums, int target) {
    int mdif = INT_MAX;
    int ans = INT_MAX;
    sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size();i++){
        ans = checkClosest(nums,i,ans,mdif,target);
    }

    return ans;
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input1.txt","r",stdin);
    #endif

    int t = 1;
    cin>>t;
    while(t--){
        int n,target,ans;
        cin>>n;
        vector<int> ar(n);
        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }
        cin>>target;

        ans = solve(ar, target);
        cout<<ans<<endl;
    }

    return 0;
}