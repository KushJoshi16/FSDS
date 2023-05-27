#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*

You are given two integer arrays nums1 and nums2, sorted in non-decreasing order, and two integers m and n, representing the number of elements in nums1 and nums2 respectively.

Merge nums1 and nums2 into a single array sorted in non-decreasing order.

The final sorted array should not be returned by the function, but instead be stored inside the array nums1. To accommodate this, nums1 has a length of m + n, where the first m elements denote the elements that should be merged, and the last n elements are set to 0 and should be ignored. nums2 has a length of n.

**Example 1:**
Input: nums1 = [1,2,3,0,0,0], m = 3, nums2 = [2,5,6], n = 3
Output: [1,2,2,3,5,6]

**Explanation:** The arrays we are merging are [1,2,3] and [2,5,6].
The result of the merge is [1,2,2,3,5,6] with the underlined elements coming from nums1.


*/


void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
    int k = m+n-1;
    int i = m-1;
    int j = n-1;
    while(i>=0 && j>=0){
        if(nums1[i]>nums2[j]){
            nums1[k--] = nums1[i--];
        }
        else{
            nums1[k--] = nums2[j--];
        }
    }
    while(j>=0){
            nums1[k--] = nums2[j--];
    }
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input5.txt","r",stdin);
    #endif

    int t = 1;
    cin>>t;
    while(t--){
        int n,m;

        cin>>n>>m;

        vector<int> ar1((n+m),0);
        vector<int> ar2(m);

        for(int i = 0;i<n;i++){
            cin>>ar1[i];
        }

        for(int i = 0;i<m;i++){
            cin>>ar2[i];
        }


        merge(ar1,n,ar2,m);
        

        for(int i: ar1){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}