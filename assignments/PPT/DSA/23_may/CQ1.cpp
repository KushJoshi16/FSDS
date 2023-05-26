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

// min and max element

int main(){
    int n;
    cout<<"Enter n";
    cin>>n;
    vector<int> ar(n);
    generate(begin(ar), end(ar), rangegenerator(0)); // random array code
    random_shuffle(begin(ar), end(ar)); // random array code
    int mn, MX;
    mn = MX = ar[0];

    for(int i = 1;i<n;i++){
        mn = min(mn,ar[i]);
        MX = max(MX,ar[i]);
    }

    for(int i : ar){
        cout<<i<<",";
    }
    cout<<endl;

    cout<<mn<<" "<<MX<<endl;
    return 0;
    }