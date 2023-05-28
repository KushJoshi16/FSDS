#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

/*
You are given an integer array nums and an integer k.

In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

The score of nums is the difference between the maximum and minimum elements in nums.

Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

Example 1:
Input: nums = [1], k = 0
Output: 0

Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.

*/



int solve(vector<int>& nums, int k) {
    int m,mx;
    int ans;
    m = mx = nums[0];
    for(int i: nums){
        m = min(m,i);
        mx = max(mx,i);
    }
    ans = max(mx-m - 2*k,0);

    return ans;

}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input8.txt","r",stdin);
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