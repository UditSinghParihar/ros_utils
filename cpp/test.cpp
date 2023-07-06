#include <bits/stdc++.h>

using namespace std;

string ltrim(const string &);
string rtrim(const string &);


/*
 * Complete the 'circles' function below.
 *
 * The function is expected to return a STRING_ARRAY.
 * The function accepts STRING_ARRAY circlePairs as parameter.
 */

using namespace std;


vector<int> parse(string cirPair){
    // 3 0 10 5 0 3
    vector<int> ans;
    
    std::istringstream is(cirPair);
    int n;
    while( is >> n ) {
        ans.push_back(n);
    }
    return ans;
}

float dist(int x1, int y1, int x2, int y2){
    float dist = pow(pow(x1-x2, 2) + pow(y1-y2, 2), 0.5);    
    return dist;
}

vector<string> circles(vector<string> circlePairs) {
    vector<string> string_ans;
    
    for(int i=0; i<circlePairs.size(); ++i){
        string cirPair = circlePairs[i];
        
        auto ans = parse(cirPair);
        int x1 = ans[0], y1 = ans[1], r1 = ans[2], x2 = ans[3], y2 = ans[4], r2 = ans[5];
        int max_r = max(r1, r2);
        int min_r = min(r1, r2);

        // Touching
        if(dist(x1, y1, x2, y2) == float(r1+r2)){
            string_ans.push_back("Touching");  
        }
        
        // Concentric
        else if((x1 == x2) && (y1 == y2)){
            string_ans.push_back("Concentric");  
        }
        

        // Disjoint-Inside
        else if(dist(x1, y1, x2, y2) < max_r && (max_r - dist(x1, y1, x2, y2) - min_r) > 0){
            string_ans.push_back("Disjoint-Insdie");
        }
        
        // Intersecting
        else if(dist(x1, y1, x2, y2) < (r1+r2)){
            // fprintf(stdout, "%", dist(x1, y1, x2, y2));
            string_ans.push_back("Intersecting");  
        }
        
        // Disjoint-Outside
        else if(dist(x1, y1, x2, y2) > (r1+r2)){
            string_ans.push_back("Disjoint-Outside");
        }
                
        // // Disjoint-Inside
        // else if(dist(x1, y1, x2, y2) < max_r && (max_r - dist(x1, y1, x2, y2) - min_r) > 0){
        //     string_ans.push_back("Disjoint-Insdie");
        // }
    }
    
    return string_ans;
}


int main()
{   
    vector<string> v{"12 0 21 14 0 23"};
    auto ans =  circles(v);

    for(auto i: ans){
        cout << i << endl;
    }

}