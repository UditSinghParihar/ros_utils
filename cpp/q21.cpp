#include <bits/stdc++.h>

using namespace std;


class Matrix{
public:
	int rows;
	int cols;
	vector<vector<int>> data;

public:
	Matrix(const vector<vector<int>> &mat){	
		this->rows = mat.size();
		this->cols = mat[0].size();

		for(auto row : mat){
			data.push_back(row);
		}
	}

	friend ostream& operator<<(ostream& out, const Matrix &mat){
		for(int i=0; i<mat.rows; ++i){
			for(int j=0; j<mat.cols; ++j){
				out << mat.data[i][j] << " ";
			}
			out << endl;
		}
		out << "---\n";

		return out;
	}

	Matrix operator*(const Matrix& m2){
		int row1 = rows, col1 = cols, row2 = cols, col2 = m2.cols;

		Matrix ans(vector<vector<int>> (row1, vector<int> (col2)));

		for(int i=0; i<row1; ++i){
			
			for(int j=0; j<col2; ++j){
				int sum_e = 0;
				
				for(int k=0; k<col1; ++k){
					sum_e += data[i][k] * m2.data[k][j];		
				}
				ans.data[i][j] = sum_e;
			}
		}

		return ans;
	}

	void transpose(void){
		vector<vector<int>> temp(cols, vector<int> (rows));

		for(int i=0; i<rows; ++i){
			for(int j=0; j<cols; ++j){
				temp[j][i] = data[i][j];
			}
		}

		data = temp;
		swap(rows, cols);
	}
};


int main(int argc, char **argv){
	// int rows = 3, cols = 3;
	// vector<vector<int>> v1{{2, 3, 4}, {1, 0, 2}, {1, 3, -1}};
	
	// Matrix m1(v1);

	// vector<vector<int>> v2(3, vector<int> (1));
	// v2[0][0] = -1;
	// v2[1][0] = 0;
	// v2[2][0] = 1;

	// Matrix m2(v2);


	// auto ans = m1 * m2;

	// cout << m1;
	// cout << m2;
	// // cout << ans;

	// m2.transpose();
	// cout << m2;

	// Matrix *ptr1 = new Matrix(vector<vector<int>> {{2, 3, 4}, {1, 0, 2}, {1, 3, -1}});
	// Matrix *ptr2 = new Matrix(vector<vector<int>> {{-1}, {0}, {1}});

	// cout << *ptr1 << *ptr2;
	// auto ans = (*ptr1) * (*ptr2);
	// cout << ans;

	// delete ptr1;
	// delete ptr2;

	// cout << *ptr1 << *ptr2;


	// shared_ptr<Matrix> ptr(new Matrix(vector<vector<int>> {{2, 3, 4}, {1, 0, 2}, {1, 3, -1}}));
	// cout << *ptr << endl;


	// Matrix *ptr0;

	// {
	// Matrix *ptr1 = new Matrix(vector<vector<int>> {{2, 3, 4}, {1, 0, 2}, {1, 3, -1}});

	// ptr0 = ptr1;

	// cout << *ptr0;
	// delete ptr1;
	// }


	// cout << *ptr0;


	shared_ptr<Matrix> sptr0;

	{
		// shared_ptr<Matrix> sptr1(new Matrix(vector<vector<int>> {{2, 3, 4}, {1, 0, 2}, {1, 3, -1}}));
		shared_ptr<Matrix> sptr1 = make_shared<Matrix>(Matrix(vector<vector<int>> {{2, 3, 4}, {1, 0, 2}, {1, 3, -1}}));

		sptr0 = sptr1;

		cout << *sptr0;
	}

	cout << *sptr0;

}