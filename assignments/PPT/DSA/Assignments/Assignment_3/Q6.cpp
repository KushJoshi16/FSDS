#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*
Given a non-empty array of integers nums, every element appears twice except
for one. Find that single one.

You must implement a solution with a linear runtime complexity and use only
constant extra space.

Example 1:
Input: nums = [2,2,1]
Output: 1
*/


int solve(vector<int>& nums) {
    int ans = 0;
    for(int i: nums){
        ans ^= i;
    }
    return ans;
}


int main(){
    // Remove the following three lines when running in terminal with input or some interface
        
    #ifndef ONLINE_JUDGE
        freopen("input6.txt","r",stdin);
    #endif

    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        vector<int> ar(n);
        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }

        int ans = solve(ar);

        cout<<ans<<endl;
    }

    return 0;
}