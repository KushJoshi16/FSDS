#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <iterator>

using namespace std;

/*

You have a long flowerbed in which some of the plots are planted, and some are not.
However, flowers cannot be planted in adjacent plots.
Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.

Example 1:
Input: flowerbed = [1,0,0,0,1], n = 1
Output: true
*/


bool solve(vector<int>& flowerbed, int n) {
    int zc = 0;
    int lb = 0;
    for(int i :flowerbed){
        if(i==1){
            lb = 1;
            n -= (zc/2);
            if(n<=0)
            return true;
            zc = 0;
        }
        else if(lb == 1){
            lb = 0;
        }
        else{
            zc++;
        }
    }
    n-= ((zc+1)/2);
    return (n <= 0);
}

int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input4.txt","r",stdin);
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

        bool ans = solve(ar,target);
        cout<<ans<<endl;        
    }

    return 0;
}