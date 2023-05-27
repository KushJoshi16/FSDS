#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int RandomNumber () { return (rand()%100); } 

vector<int> randomSortedVector(int n){
    vector<int> ar(n,0);
    srand(time(0));

    generate(ar.begin(), ar.end(), RandomNumber);
    
    sort(ar.begin(),ar.end());

    return ar;
}
/*
    call the a.out file as any of these to get an array of size 12:
    ./a.out 12          [Write mode]
    ./a.out 12 w        [Write mode]
    ./a.out 12 a        [Append mode]
*/

int main(int argc, char* argv[]){
    string m = "w";

    if(argc==3){
    string mode = string(argv[2]);
        if(mode == "a")
            m = "a";
            }

    #ifndef ONLINE_JUDGE
        freopen("input.txt", m.c_str() ,stdout);
    #endif

    int n = 10;
    if(argc>=2)
    n = atoi(argv[1]);

    vector<int> v = randomSortedVector(n);
    cout<<n<<endl;
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}