#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv){
	vector<int> A{5, 10, 2, 1};

	for(int i=0; i<A.size(); ++i){
		fprintf(stderr, "%ld %ld %ld\n", (A.size()-i)%A.size(), A.size()-i, A.size());
	}


	return 0;
}