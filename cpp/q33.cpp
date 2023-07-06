#include <bits/stdc++.h>

using namespace std;


struct compare{
	bool operator()(int a, int b){
		return a > b;
	}
};

int main(int argc, char const *argv[]){
	vector<int> v{4, 100, -1, 40, 2, 0};


	auto comparator = [](int a, int b){return a > b;};

	// sort(v.begin(), v.end(), compare());

	// v.erase(find(v.begin(), v.end(), 100));


	for(auto e : v){
		printf("Val: %d\n", e);
	}


	priority_queue<int, vector<int>, greater<int>> pq;

	for(auto e:v){
		pq.push(e);		
	}

	while(pq.size() != 0){
		auto e = pq.top();
		pq.pop();

		printf("val: %d\n", e);

	}



	return 0;
}