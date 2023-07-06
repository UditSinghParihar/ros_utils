#include <bits/stdc++.h>

using namespace std;


int main(int argc, char *argv[]){
	vector<int> v{11, -1, 2, 100, 9, 3, 14};
	sort(v.begin(), v.end());


	for(auto e:v){
		printf("%d ", e);
	}
	cout << endl;

	int value = 9;


	auto itr = find(v.begin(), v.end(), value);
	printf("Found: %d %d\n", *itr, *(itr+1));

	return 0;

}