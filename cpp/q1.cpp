/*

Code to practice
		1
	1  		1
  1		2		1
1   3		3		1

r_i_j = r_i-1_j-1 + r_i-1_j 

*/


#include <bits/stdc++.h>


using namespace std;


int main(int argv, char** argc){
	std::vector<int> prev{1};

	int total_rows = 9;

	for(int r=1; r<total_rows; ++r){
		int num_ele = r+1;
		std::vector<int> cur{1};

		for(int sp=0; sp<(total_rows-r); ++sp)
			fprintf(stderr, " ");


		for(int j=0; j<prev.size(); ++j)
			fprintf(stderr, "%d ", prev[j]);

		fprintf(stderr, "\n");

		for(int i=1; i<num_ele-1; ++i){
			int cur_ele = prev[i-1] + prev[i];
			cur.push_back(cur_ele); 
		}

		cur.push_back(1);



		prev = cur;
	}


	return 0;
}