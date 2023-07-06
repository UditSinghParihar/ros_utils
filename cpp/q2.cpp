#include <bits/stdc++.h>

using namespace std;


void print(const vector<int> &v){
	for(auto e : v)
		fprintf(stderr, "%d ", e);
	fprintf(stderr, "\n");
}

int main(int argv, char** argc){
	vector<int> v{2,3,5};
	print(v);

	v.erase(v.begin(), v.end());
	v.push_back(100);

	

	print(v);


	return 0;
}