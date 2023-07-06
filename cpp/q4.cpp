#include <bits/stdc++.h>

using namespace std;


void print(const vector<int> &v){
	fprintf(stderr, "Size: %lu\n", v.size());

	// for(auto e:v){
	// 	fprintf(stderr, "%d ", e);
	// }

	for(auto it = v.begin(); it != v.end(); ++it){
		fprintf(stderr, "%d ", *it);
	}
	fprintf(stderr, "\n");
}


int main(int argc, char** argv){
	vector<int> v{2, -1, 4, 7, 100, 5};
	// fprintf(stderr, "%d\n", *(v.begin()+3));

	auto pos = find(v.begin(), v.end(), 100);
	fprintf(stderr, "loc: %ld and value: %d", pos-v.begin(),*pos);

	sort(v.begin(), v.end());

	print(v);
	v.clear();
	// v.erase(v.begin(), v.end());
	print(v);


}