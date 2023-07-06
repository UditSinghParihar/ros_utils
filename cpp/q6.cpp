/*
[
1, 2, 3
5, 6, 7
9, 10, 11
]

v[i, j] = v[j, i]

*/


#include <bits/stdc++.h>

using namespace std;

void print(const vector<vector<int>> &v){
	for(auto r:v){
		for(auto c:r){
			fprintf(stderr, "%d ", c);
		}
		fprintf(stderr, "\n");
	}

}

int main(int argc, char const *argv[]){
	int rows=3, cols=3;
	vector<vector<int>> v(rows, vector<int>(cols));

	int counter = 1;
	for(int i=0; i<rows; ++i){
		for(int j=0; j<cols; ++j){
			v[i][j] = counter;
			++counter; 
		}
	}

	print(v);


	for(int i=0; i<rows; ++i){
		for(int j=i; j<cols; ++j){
			int temp = v[i][j];
			v[i][j] = v[j][i];
			v[j][i] = temp;
		}
	}

	print(v);

	
	return 0;
}