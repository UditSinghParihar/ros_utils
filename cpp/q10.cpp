#include <bits/stdc++.h>

using namespace std;


int main(int argc, char** argv){
	vector<int> A{1, 2, 3};

    int ans = 1;
    int sz = A.size();
    
    for(int i=0; i<sz; ++i){
        ans += A[i]*(pow(10, sz-1-i));
    }	

    fprintf(stderr, "ans %d\n", ans);

}