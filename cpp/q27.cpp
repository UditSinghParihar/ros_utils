#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[]){
	vector<int> v{10, 2, 9, -2, 100, 5};
	
	vector<int> indices(v.size());
	for(int i=0; i<v.size(); ++i){
		indices[i] = i;
	}

	// sort(indices.begin(), indices.end(), [&v](int i, int j){
	// 	return v[i] < v[j];
	// });

	// sort(v.begin(), v.end());

	// sort v using qsort
	qsort(v.data(), v.size(), sizeof(int), [](const void *a, const void *b){
		return *(int*)a - *(int*)b;
	});

	for(int i=0; i<v.size(); ++i){
		printf("Num: %d and index: %d\n", v[i], indices[i]);
	}


	// auto u = v;
	// sort(u.begin(), u.end());
	// vector<int> indices;

	// for(auto e:u){
	// 	auto itr = find(v.begin(), v.end(), e);
	// 	indices.push_back(itr-v.begin());
	// }
	// cout << endl;

	// for(int i=0; i<v.size(); ++i){
	// 	printf("Num: %d and index: %d\n", v[i], i);
	// }

	// cout << "\n---\n";

	// for(int i=0; i<u.size(); ++i){
	// 	printf("Num: %d and index: %d\n", u[i], indices[i]);
	// }

	return 0;
}