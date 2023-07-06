#include <bits/stdc++.h>

using namespace std;




template <typename T> 
T add(T a, T b){
	T sum = a+b;
	cout << "Sum: " << sum << endl;

	return sum;
}

template<typename T>
vector<T> sum_fibonacci(int n_digits){
	vector<T> v{1, 1};

	for(int i=2; i<n_digits; ++i){
		v.push_back(v[i-1] + v[i-2]);
	}

	return v;
}

int main(int argc, char *argv[]){
	float a = 1.1, b = 9.8;
	int c = 2, d = 9;

	// auto ans1 = add(a, b);
	// auto ans2 = add(c, d);

	auto v = sum_fibonacci<float>(5);
	for(auto e:v){
		cout << e << endl;
	}


	return 0;
}