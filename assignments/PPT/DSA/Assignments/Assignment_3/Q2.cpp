#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*

Given an array nums of n integers, return an array of all the unique quadruplets
[nums[a], nums[b], nums[c], nums[d]] such that:
           ● 0 <= a, b, c, d < n
           ● a, b, c, and d are distinct.
           ● nums[a] + nums[b] + nums[c] + nums[d] == target

You may return the answer in any order.

Example 1:
Input: nums = [1,0,-1,0,-2,2], target = 0
Output: [[-2,-1,1,2],[-2,0,0,2],[-1,0,0,1]]

*/


vector<vector<int> > Twosum(vector<int>& nums, int l , int h , long long target){
        vector<vector<int> > rv;
        while(l<h){
            if(target == nums[l] + nums[h]){
                int lv = nums[l];
                int hv = nums[h];
                int arr[] = { lv,hv };
                vector<int> v(arr,arr+2);
                rv.push_back(v);

                while(l<h && nums[l]==lv)l++;
                while(l<h && nums[h]==hv)h--;
            }
            else if(target < nums[l] + nums[h]){
                h--;
            }
            else {
                l++;
            }
        }
        return rv;
    }
    vector<vector<int> > solve(vector<int>& nums, int target) {
        vector<vector<int> > rv;
        int h = nums.size(), prev, prevj;
        long long t;
        sort(nums.begin(),nums.end());

        for(int i = 0;i<h;){
            prev = nums[i];
            for(int j = i+1;j<h;){
                prevj = nums[j];
                t = target - ((long long)nums[i] + nums[j]) ;
                vector<vector<int> > av = Twosum( nums, j + 1, h - 1 , t);
                if(av.size()){
                    for(auto v : av)
                    {   
                        int arr[] = { nums[i], nums[j], v[0], v[1] };
                        vector<int> fav(arr,arr+4);
                        rv.push_back(fav);
                    }
                }
                while(j<h && nums[j]==prevj) j++;
            }

            while(i<h && nums[i]==prev) i++;
        }
        return rv;
    }


int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input2.txt","r",stdin);
    #endif

    int t = 1;
    int tcn = 0;
    cin>>t;
    while(t--){
        tcn++;
        int n,target;
        cin>>n;
        vector<int> ar(n);
        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }
        cin>>target;

        vector<vector<int> > ans = solve(ar, target);
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