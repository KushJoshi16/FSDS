#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*
Given an array of meeting time intervals where intervals[i] = [starti, endi],
determine if a person could attend all meetings.

Example 1:
Input: intervals = [[0,30],[5,10],[15,20]]
Output: false

*/

bool comp(const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        }
bool solve(vector<vector<int> > intervals){
    
    int prev = intervals[0][1];

    // sort(intervals.begin(),intervals.end());
    sort(intervals.begin(), intervals.end(), comp); 
    
    for(int i = 1;i<intervals.size();i++){
        if(intervals[i][0]< prev){
            return false;
        }
        prev = max(prev,intervals[i][1]);
    }
    return true;
}



int main(){
    // Remove the following three lines when running in terminal with input or some interface
    #ifndef ONLINE_JUDGE
        freopen("input8.txt","r",stdin);
    #endif

    int t,n,tcn = 0;
    cin>>t;
    while(t--){
        tcn++;
        cin>>n;
        vector<vector<int> > ar(n,vector<int>(2));
        for(int i = 0;i<n;i++){
            cin>>ar[i][0]>>ar[i][1];
        }

        bool ans = solve(ar);

        cout<<ans<<endl;
    }

    return 0;
}