#include <bits/stdc++.h>

using namespace std;


int main(int argc, char const *argv[]){
	string str1("9 19 1 -2 0 10002");
	
	stringstream ss(str1);

	vector<int> v;
	int num = 0;

	while(ss >> num){
		v.push_back(num);
	}


	for(auto e : v){
		printf("%d\n", e);
	}


	string str2("hello my name is udit");
	stringstream ss2(str2);

	vector<string> v2;
	string word;

	while(ss2 >> word){
		v2.push_back(word);
	}

	for(auto e : v2){
		printf("%s\n", e.c_str());
	}

	return 0;
}