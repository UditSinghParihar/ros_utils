/*
12 18 15 21 19 30 4 17
*/

#include <bits/stdc++.h>

using namespace std;

void print(const vector<int> &v){
	for(auto e : v){
		fprintf(stdout, "%d  ", e);
	}
	cout << endl;
}

void quicksort(vector<int> &v, int st, int end){
	int pivot = end;

	if(st < 0 || end >= v.size()){
		return ;
	}

	if(st >= end){
		return ;
	}

	// Placing pivot element at its right location

	int pivot_id = st;

	for(int i=st; i<end; ++i){
		if(v[i] < v[pivot]){
			swap(v[i], v[pivot_id]);
			++pivot_id;
		}
	}

	swap(v[pivot], v[pivot_id]);


	// sorting left and right side of the pivot

	quicksort(v, st, pivot_id-1);
	quicksort(v, pivot_id+1, end);

	return ;
}


int main(int argc, char const *argv[]){
	std::vector<int> v{12, 18, 15, 21, 19, 30, 4, 17};

	print(v);
	
	quicksort(v, 0, v.size()-1);

	print(v);

	return 0;
}