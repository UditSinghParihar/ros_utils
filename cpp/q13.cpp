#include <bits/stdc++.h>

using namespace std;


vector<int> findOccurences(vector<int> &A) {
    map<int, int> mp;
    
    for(auto e : A){
        if(mp.find(e) != mp.end()){
            mp[e] += 1;    
        }
        else{
            mp[e] = 1;
        }
    }
    
    vector<int> sol;
    
    for(auto it : mp){
        sol.push_back(it.second);    
    }
    
    return sol;
}

int  main(int argc, char const *argv[]){
	vector<int> v{1, 2, 3};
	auto sol = findOccurences(v);

	for(auto e : sol)
		fprintf(stderr, "Ans %d\n", e);

	return 0;
}