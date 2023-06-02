#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*
You are given an inclusive range [lower, upper] and a sorted unique integer array
nums, where all elements are within the inclusive range.

A number x is considered missing if x is in the range [lower, upper] and x is not in
nums.

Return the shortest sorted list of ranges that exactly covers all the missing
numbers. That is, no element of nums is included in any of the ranges, and each
missing number is covered by one of the ranges.

Example 1:
Input: nums = [0,1,3,50,75], lower = 0, upper = 99
Output: [[2,2],[4,49],[51,74],[76,99]]

Explanation: The ranges are:
[2,2]
[4,49]
[51,74]
[76,99]

*/



vector<vector<int> > solve(vector<int>& nums, int lower, int upper) {
        int n = nums.size();
        vector<vector<int> > rv;
        if (n == 0) {
            int ar[] = {lower, upper};
            rv.push_back(vector<int>(ar,ar+2));
            return rv;
        }
        if (lower < nums[0]) {
            int ar[] = {lower, nums[0] - 1};
            rv.push_back(vector<int>(ar,ar+2));
        }
        for (int i = 0; i < n - 1; i++) {
            if (nums[i + 1] - nums[i] <= 1) {
                continue;
            }
            int ar[] = {nums[i] + 1, nums[i + 1] - 1};
            rv.push_back(vector<int>(ar,ar+2));
        }
        if (upper > nums[n - 1]) {
            int ar[] = {nums[n - 1] + 1, upper};
            rv.push_back(vector<int>(ar,ar+2));
        }

        return rv;
    }


int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input7.txt","r",stdin);
    #endif

    int t,n,tcn = 0;
    cin>>t;
    while(t--){
        tcn++;
        cin>>n;
        vector<int> ar(n);
        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }
        int l = 0, h = 99;

        vector<vector<int> > ans = solve(ar,l,h);
        for(auto v: ans){
            for(int i : v){
                cout<<i<<" ";
            }
            cout<<endl;
        }
        cout<< "test case "<<tcn<<"done!"<<endl;
    }

    return 0;
}