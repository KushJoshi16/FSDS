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

bool solAproach1(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    for(int i = 0;i<nums.size()-1;i++){
        if(nums[i]==nums[i+1])
            return 1;
    }
    return 0;
}
bool solAproach2(vector<int>& nums) {
    unordered_set<int> st(nums.begin(),nums.end());
    return st.size()<nums.size();
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input6.txt","r",stdin);
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


        bool ans = solAproach1(arr);
        cout<<"Aproach 1:\t";
        cout<<ans<<endl;

        ans = solAproach2(arr);
        cout<<"Aproach 2:\t";
        cout<<ans<<endl;
        cout<<endl;


    }

    return 0;
}