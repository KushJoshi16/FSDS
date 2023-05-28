#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

/*

Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise,
return -1.

You must write an algorithm with O(log n) runtime complexity.

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4

Explanation: 9 exists in nums and its index is 4

*/



int solve(vector<int>& nums, int target) {
    int l,h,m;
    l =0;
    h = nums.size()-1;
    
    while(l<=h){
        m = l + (h-l)/2;
        if(nums[m]==target){
            return m;
        }
        else if(nums[m]<target){
            l = m+1;
        }
        else if(nums[m]>target){
            h = m-1;
        }
    }
    return -1;
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input6.txt","r",stdin);
    #endif

    int t = 1;
    cin>>t;
    while(t--){
        int n,target;
        cin>>n;
        vector<int> ar(n);

        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }
        cin>>target;

        int ans = solve(ar,target);

        cout<<ans<<endl;
    }

    return 0;
}