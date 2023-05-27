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


vector<int> findErrorNums(vector<int>& nums) {
    vector<int> rv;
    int first = 0;
    int second = 0;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        nums[(nums[i]-1)%n] += n;
    }
    
    for(int i =0;i<n;i++){
        if(nums[i]<=n){
            second = i+1;
        }
        else if(nums[i]>2*n){
            first = i+1;
        }
    }
    rv.push_back(first);
    rv.push_back(second);
    return rv;
}


int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input8.txt","r",stdin);
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

        vector<int> ans = findErrorNums(arr);


        cout<<ans[0]<<", "<<ans[1]<<endl;

    }

    return 0;
}