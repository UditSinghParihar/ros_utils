#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	map<int, int> mp;
	mp[5] = 500;
	mp[2] = 200;
	mp[-1] = -100;

	mp.insert(pair<int, int>(9, 900));
	mp.insert(make_pair(-7, -700));

	for(auto it = mp.begin(); it != mp.end(); ++it){
		fprintf(stderr, "%d and %d\n", it->first, it->second);
	}

	fprintf(stderr, "%ld\n", mp.size());

	auto it = mp.find(-1);
	if(it != mp.end()){
		fprintf(stderr, "%d %d\n", it->first, it->second);
	}

	return 0;
}