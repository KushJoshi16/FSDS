#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*

💡 Given an integer array nums and an integer val, remove all occurrences of val in nums in-place. The order of the elements may be changed. Then return the number of elements in nums which are not equal to val.

Consider the number of elements in nums which are not equal to val be k, to get accepted, you need to do the following things:

- Change the array nums such that the first k elements of nums contain the elements which are not equal to val. The remaining elements of nums are not important as well as the size of nums.
- Return k.

**Example :**
Input: nums = [3,2,2,3], val = 3
Output: 2, nums = [2,2,_*,_*]

**Explanation:** Your function should return k = 2, with the first two elements of nums being 2. It does not matter what you leave beyond the returned k (hence they are underscores)

*/


int solve(vector<int>& nums, int val) {
    int i = 0;
    int count = 0;
    int n = nums.size();
    for(int i = 0;i<n;i++){
        if(nums[i]!=val){
            nums[count] = nums[i];
            count++;
        }
    }
    return count;
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input2.txt","r",stdin);
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


        int ans = solve(ar, target);
        
        if(ans==0)
            cout<<"The array is empty!";
        else
            for(int i = 0;i<ans;i++){
                cout<<ar[i]<<" ";
            }
        cout<<endl;
    }

    return 0;
}