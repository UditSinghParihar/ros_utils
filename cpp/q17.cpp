/*
5 2 4 -1 10 1

*/

#include <bits/stdc++.h>

using namespace std;


void print(const vector<int> &v){
	for(auto e : v){
		fprintf(stdout, "%d  ", e);
	}
	cout << endl;
}


vector<int> mergesort(vector<int> v, int st, int end){
	int mid = (end+st)/2;
	// fprintf(stdout, "st: %d mid %d end %d\n", st, mid, end);


	if(st == end){
		return vector<int> {v[st]};
	}


	auto v1 = mergesort(v, st, mid);
	auto v2 = mergesort(v, mid+1, end);


	// Merging step

	vector<int> ans;

	int i=0, j=0;
	while(i<v1.size() && j<v2.size()){
		if(v1[i] < v2[j]){
			ans.push_back(v1[i]);
			++i;
		}
		else{
			ans.push_back(v2[j]);
			++j;
		}
	}



	if(i == v1.size()){
		while(j<v2.size()){
			ans.push_back(v2[j]);
			++j;
		}
	}
	else if(j == v2.size()){
		while(i<v1.size()){
			ans.push_back(v1[i]);
			++i;
		}
	}

	return ans;
}


int main(int argc, char const *argv[]){
	std::vector<int> v{5, 2, 4, -1, 10, 1};

	print(v);

	int st = 0, end = v.size()-1;
	
	auto sort_v = mergesort(v, st, end);

	print(sort_v);

	return 0;
}