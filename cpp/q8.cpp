#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){
	unordered_map<int, int> mp;
	mp.insert(make_pair(0, 50));
	mp.insert(make_pair(1, 2));
	mp.insert(make_pair(2, -100));


	for(auto i: mp){
		if(i.second == -100)
			cout << i.first << " " << i.second << endl;
	}
	
	return 0;
}