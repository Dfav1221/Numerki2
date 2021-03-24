#include <iostream>
#include <map>
using namespace std;


typedef pair<int, int> Index;

class Matrix {
private:
	map<Index, int> cell;




public:

	Matrix() {
		cell[Index(2, 2)] = 10;
		cell[Index(2, 5)] = 1;
		cell[Index(8, 2)] = 110;
	}


	int operator[](const Index& index) {
		return cell[index];
	}

	

};



int main() {
	Matrix matrix;
	cout << matrix[Index(2, 2)]<<endl << matrix[Index(2, 5)] << endl << matrix[Index(8, 2)] << endl << matrix[Index(2, 1)] << endl;
}