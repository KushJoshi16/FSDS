#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <iterator>

using namespace std;

/*
💡 You are given a large integer represented as an integer array digits, where each
digits[i] is the ith digit of the integer. The digits are ordered from most significant
to least significant in left-to-right order. The large integer does not contain any
leading 0's.

Increment the large integer by one and return the resulting array of digits.

**Example 1:**
Input: digits = [1,2,3]
Output: [1,2,4]

**Explanation:** The array represents the integer 123.
Incrementing by one gives 123 + 1 = 124.
Thus, the result should be [1,2,4].
*/


vector<int> solve(vector<int>& digits) {
    int ind = digits.size()-1;
    while(ind>=0 && digits[ind]==9){
        digits[ind] = 0;
        ind--;
    }

    if(ind == -1){
        digits.insert(digits.begin(),1);
    }
    else digits[ind] += 1;

    return digits;
}



int main(){
    // Remove the following three lines when running in terminal with input or some interface
        
    #ifndef ONLINE_JUDGE
        freopen("input5.txt","r",stdin);
    #endif

    int t,n;
    cin>>t;
    while(t--){
        
        cin>>n;
        vector<int> ar(n);
        for(int i = 0;i<n;i++){
            cin>>ar[i];
        }

        vector<int> ans = solve(ar);

        for(int i : ar){
            cout<<i<<" ";
        }
        cout<<endl;
    }

    return 0;
}