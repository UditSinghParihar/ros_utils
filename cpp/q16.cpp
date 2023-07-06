/*
5 2 4 10 1

*/

#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	std::vector<int> v{5, 2, 4, 10, 1};

	for(auto e : v){
		fprintf(stderr, "%d ", e);
	}
	cout << endl;

	bool swapped = true;
	int j = 0;
	while(swapped == true){
		swapped = false;
		for(int i=0; i<v.size()-j-1; ++i){
			if(v[i]>v[i+1]){
				swap(v[i], v[i+1]);
				swapped = true;
			}
		}
		++j;
	}

	for(auto e : v){
		fprintf(stderr, "%d ", e);
	}

	cout << endl;

	return 0;
}