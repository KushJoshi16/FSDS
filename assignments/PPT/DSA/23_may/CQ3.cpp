#include <stdio.h>
#include <iostream>
#include <vector>

using namespace std;

struct rangegenerator { // random array code
    rangegenerator(int init) : start(init) { }

    int operator()() {
        return start++;
    }

    int start;
};
//..........

// sub array with max product
//sub array is contigous


int sol(vector<int> ar, int n){
    
}
int main(){
    int n;
    cout<<"Enter n";
    cin>>n;
    vector<int> ar(n);
    // for(int i = 0;i<n;i++){
    //     cin>>ar[i];
    // }
    generate(begin(ar), end(ar), rangegenerator(0)); // random array code
    random_shuffle(begin(ar), end(ar)); // random array code
    

    for(int i: ar){
        cout<<i<<",";
    }
    cout<<endl;


    cout<<sol(ar,n)<<endl;


    return 0;
    }

    // 7 1 5 3 6 4
    //profit = 5