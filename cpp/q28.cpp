#include <bits/stdc++.h>

using namespace std;


int fib(int num, map<int, int> &mp){
	if(mp[num] != 0){
		return mp[num];
	}

	int ans = fib(num-1, mp) + fib(num-2, mp);

	mp[num] = ans;

	return ans;
}


int main(int argc, char *argv[]){
	int n = 8;
	map<int, int> mp;
	mp[0] = 1;
	mp[1] = 1;

	int ans = fib(n, mp);

	printf("Answer :%d\n", ans);

	for(auto itr:mp){
		printf("%d ", itr.second);
	}
	cout << endl;

	for(auto itr=mp.begin(); itr!=mp.end(); ++itr){
		printf("val: %d\n", itr->first);
	}


	printf("Abs: %d\n", abs(2-3));

	return 0;
}