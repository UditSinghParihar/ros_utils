#include <bits/stdc++.h>

using namespace std;




int main(int argc, char const *argv[]){
	map<int, int> mp;
	mp.insert(make_pair(0, 50));
	mp.insert(make_pair(1, 2));
	mp.insert(make_pair(2, -100));

	// Sort the map by second element of pair
	vector<pair<int, int> > vec(mp.begin(), mp.end());
	sort(vec.begin(), vec.end(), [](pair<int, int> a, pair<int, int> b){
		return a.second < b.second;
	});

	// Swap consevuative elements of vector
	for(int i = 0; i < vec.size() - 1; i += 2){
		swap(vec[i], vec[i + 1]);
	}

	for(auto i: vec){
		cout << i.first << " " << i.second << endl;
	}

	map<int, int> mp2(vec.begin(), vec.end());

	for(auto i: mp2){
		cout << i.first << " " << i.second << endl;
	}


	// print 10 raise to power 3
	
	
	return 0;
}