#include <bits/stdc++.h>

using namespace std;


int main(int argv, char** argc){
    // vector<vector<char>> v({"1","1","1","1","0"}, {"1","1","0","1","0"}, {"1","1","0","0","0"}, {"0","0","0","0","0"});

    // Random initialization of vector of vector of char
    vector<vector<char>> v(4, vector<char>(5));
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            v[i][j] = rand() % 2 + '0';
        }
    }  

    // Print the vector of vector of char
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 5; j++){
            cout << v[i][j] << " ";
        }
        cout << endl;
    }

    return 0;

    
}