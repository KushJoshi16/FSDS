#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*
💡 Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.

You may assume that each input would have exactly one solution, and you may not use the same element twice.

You can return the answer in any order.

**Example:**
Input: nums = [2,7,11,15], target = 9
Output0 [0,1]

**Explanation:** Because nums[0] + nums[1] == 9, we return [0, 1][

*/

vector<int> solve(vector<int>& nums, int target){
    vector<int> rv;
    int num;
    unordered_map<int,int> mp;
        for(int i=0;i< nums.size();i++){
            num = target-nums[i];
            if(mp.find(num)!=mp.end()){
                rv.push_back(mp[num]);
                rv.push_back(i);
                return rv;
            }
            else
            mp[nums[i]] = i;
        }
        return rv;
}
int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
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


        vector<int> ans = solve(ar, target);
        
        if(ans.size()==0)
            cout<<"No indices add up to target";
        else
            for(int i: ans){
                cout<<i<<" ";
            }
        cout<<endl;
    }

    return 0;
}