#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct rangegenerator { // random array code
    rangegenerator(int init) : start(init) { }

    int operator()() {
        return start++;
    }

    int start;
};

int randomfunc(int j)
{
    return rand() % j;
}

vector<int> randomVector(int n, int st = 0){
    vector<int> ar(n,0);

    generate(begin(ar), end(ar), rangegenerator(st)); // random array code
    random_shuffle(begin(ar), end(ar),randomfunc); // random array code

    return ar;
}



/*
    call the a.out file as any of these to get an array of size n starting from s:
    ./a.out w n         [Write mode]
    ./a.out w n s       [Write mode]
    ./a.out a n         [Append mode]
    ./a.out a n s       [Append mode]
*/

int main(int argc, char* argv[]){
    string m = "w";

    if(argc>=2){
    string mode = string(argv[1]);
        if(mode == "a")
            m = "a";
            }

    #ifndef ONLINE_JUDGE
        freopen("input.txt", m.c_str() ,stdout);
    #endif

    int n = 10;
    int s = 0;
    if(argc>=3)
        n = atoi(argv[2]);

    if(argc>=4){
        s = atoi(argv[3]);
        // swap(s,n);
    }
    
    vector<int> v = randomVector(n,s);



    cout<<n<<endl;
    for(int i: v){
        cout<<i<<" ";
    }
    cout<<endl;

    return 0;
}