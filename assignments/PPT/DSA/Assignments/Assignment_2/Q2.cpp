#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <iterator>

using namespace std;

/*

Alice has n candies, where the ith candy is of type candyType[i]. Alice noticed that she started to gain weight, so she visited a doctor. 

The doctor advised Alice to only eat n / 2 of the candies she has (n is always even). Alice likes her candies very much, and she wants to eat the maximum number of different types of candies while still following the doctor's advice. 

Given the integer array candyType of length n, return the maximum number of different types of candies she can eat if she only eats n / 2 of them.

Example 1:
Input: candyType = [1,1,2,2,3,3]
Output: 3

Explanation: Alice can only eat 6 / 2 = 3 candies. Since there are only 3 types, she can eat one of each type.

*/


int solve(vector<int>& candyType) {
    set<int> st;
    int n = candyType.size();
    for(int i: candyType ){
        st.insert(i);
    }
    int ans = (n/2);
    if(st.size()<ans)
        ans = st.size();
    return ans;
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

        int ans = solve(ar);
        cout<<ans<<endl;        
    }

    return 0;
}