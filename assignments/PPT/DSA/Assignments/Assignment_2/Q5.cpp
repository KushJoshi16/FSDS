#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

/*

Given an integer array nums, find three numbers whose product is maximum and return the maximum product.

Example 1:
Input: nums = [1,2,3]
Output: 6

*/


// aproach 1: tc -> O(n logn)
int aproach1(vector<int>& nums) {
    sort(nums.begin(),nums.end());
    int n = nums.size()-1;
    return max(nums[n]*nums[n-1]*nums[n-2],nums[0]*nums[1]*nums[n]);
}



// aproach 2: tc -> O(n)
int aproach2(vector<int>& nums) {
    int m[2] = {INT_MAX,INT_MAX};
    int mx[3] = {INT_MIN,INT_MIN,INT_MIN};
    for(int i : nums){
        if(i<=m[1]){
            int j = 0;
            while(j>=0 && i <= m[j]){
                m[j+1] = m[j];
                j--;
            }
            m[j+1] = i;
        }
        if(i>=mx[2]){
            int j = 1;
            while(j>=0 && i >= mx[j]){
                mx[j+1] = mx[j];
                j--;
            }
            mx[j+1] = i;
        }
    }
    return max(m[0]*m[1]*mx[0],mx[0]*mx[1]*mx[2]);
}


int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input5.txt","r",stdin);
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

        int ans = aproach1(ar);
        cout<<"Aproach 1:"<<ans<<endl;

        ans = aproach2(ar);
        cout<<"Aproach 2:"<<ans<<endl;        
    }

    return 0;
}