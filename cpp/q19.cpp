#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]){
	string str = "10 23 7 1";
	
	// int a=0, b=0, c=0, d=0;
	// sscanf(str.c_str(), "%d %d %d %d", &a, &b, &c, &d);


	stringstream ss(str);

	int temp;
	while(ss >> temp){
		fprintf(stderr, "%d ", temp);
	}
	cout << endl;
	// fprintf(stderr, "%d %d %d %d\n", a, b, c, d);

	return 0;
}