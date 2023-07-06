#include <bits/stdc++.h>

using namespace std;


void print(const vector<pair<int, int>> &v){
	for(auto e : v){
		fprintf(stderr, "%d -> %d\n", e.first, e.second);
	}
}


bool compare(const pair<int, int> &p1, const pair<int, int> &p2){
	return p1.second < p2.second;
}

int main(int argc, char** argv){
	vector<pair<int, int>> v;
	v.push_back(make_pair(2, -100));
	v.push_back(make_pair(1, 50));
	v.push_back(make_pair(3, 2));
	v.push_back(pair<int, int>(4, 1));

	print(v);
	sort(v.begin(), v.end(), compare);
	print(v);

	return 0;
}