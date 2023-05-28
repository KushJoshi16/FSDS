#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

/*

We define a harmonious array as an array where the difference between its maximum value
and its minimum value is exactly 1.

Given an integer array nums, return the length of its longest harmonious subsequence
among all its possible subsequences.

A subsequence of an array is a sequence that can be derived from the array by deleting some or no elements without changing the order of the remaining elements.

Example 1:
Input: nums = [1,3,2,2,5,2,3,7]
Output: 5

Explanation: The longest harmonious subsequence is [3,2,2,2,3].
*/


int solve(vector<int>& nums) {
    map<int,int> mp;

    for(int i: nums){
        mp[i]++;
    }
    
    int ans = 0;
    map<int,int> :: iterator i = mp.begin();
    
    for(map<int,int> :: iterator itr = ++i;itr!=mp.end();itr++){
        i = itr;
        if((itr->first - (--i)->first)==1)
        ans = max(ans,((itr->second + (i)->second)));
    }
    
    return ans;
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input3.txt","r",stdin);
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

        int ans = solve(ar);
        cout<<ans<<endl;
    }

    return 0;
}