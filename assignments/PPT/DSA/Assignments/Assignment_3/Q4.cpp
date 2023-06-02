#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*
Given a sorted array of distinct integers and a target value, return the index if the
target is found. If not, return the index where it would be if it were inserted in
order.

You must write an algorithm with O(log n) runtime complexity.

Example 1:
Input: nums = [1,3,5,6], target = 5
Output: 2
*/


int solve(vector<int>& nums, int target) {
    int m,l = 0,h= nums.size()-1;

    m = l + (h-l)/2;

    while(l<=h){
        if(nums[m]==target)
            return m;
        else if(nums[m]<target)
            l = m+1;
        else
            h = m-1;

        m = l + (h-l)/2;  
    }

    return m;
}


int main(){
    // Remove the following three lines when running in terminal with input or some interface
        
    #ifndef ONLINE_JUDGE
        freopen("input4.txt","r",stdin);
    #endif

    int t,target;
    cin>>t;
    while(t--){
        
        int n;
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