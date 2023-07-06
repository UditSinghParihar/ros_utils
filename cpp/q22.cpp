#include <bits/stdc++.h>

using namespace std;


ostream& operator<<(ostream& out, const vector<vector<int>> &v){
	int rows = v.size(), cols = v[0].size();

	for(auto row : v){
		for(auto col : row){
			out << col << " ";
		}
		out << "\n";
	}
	out << "---\n";

	return out;
}


int element_wise(const vector<vector<int>> &v1, int r1, int c1, const vector<vector<int>> &v2){
	int ans = 0;

	int height = v2.size(), width = v2[0].size();

	for(int i=r1, j=0; i<r1+height; ++i, ++j){
		for(int k=c1, l=0; k<c1+width; ++k, ++l){
			ans += v1[i][k]*v2[j][l];
		}
	}

	return ans;
}


int main(int argc, char const *argv[]){
	// vector<vector<int>> v1(4, vector<int> (4));
	// vector<vector<int>> v2(2, vector<int> (2));

	vector<vector<int>> v1{ {1, 0, 2, -1}, 
							{0, 1, 2, 1}, 
							{-1, 0, 0, 3}, 
							{1, 1, 0, -1}};
	
	vector<vector<int>> v2{ {1, 0}, 
							{1, 1}};

	// v1[0] = vector<int> {1, 0, 2, -1};
	// v1[1] = vector<int> {0, 1, 2, 1};
	// v1[2] = vector<int> {-1, 0, 0, 3};
	// v1[3] = vector<int> {1, 1, 0, -1};

	// v2[0] = vector<int> {1, 0};
	// v2[1] = vector<int> {1, 1};

	cout << v1 << v2;


	const int stride = 2;

	int rows = v1.size(), cols = v1[0].size();
	vector<vector<int>> ans(rows/2, vector<int> (cols/2));


	for(int i=0; i<=rows-stride; i+=stride){
		for(int j=0; j<=cols-stride; j+=stride){
			int ele = element_wise(v1, i, j, v2);
			ans[i/stride][j/stride]	= ele;
		}

	}

	cout << ans;

	return 0;
}