//Jakub Hirsz 180146

#include <iostream>
#include <map>
#include <iomanip>

using namespace std;

const int N = 946;

typedef pair<unsigned int, unsigned int> Index; //(x,y)


class Matrix {
private:

	map<Index, double> cell;

public:

	Matrix() {
	}

	//[Index(x,y)] , równowa¿ne zapisowi [x][y]
	int operator[](const Index& index) {
		return cell[index]; 
		
	}
	
	bool buildMatrix() {

		const int a1 = 6, a2 = -1, a3 = -1;
		const int insertion[] = { a3, a2 , a1, a2, a3 };

		int x = -2;
		try {
			for (int y = 0; y < N; y++) {
				for (int i = 0; i < 5; i++) {//5 wartoœci w tablicy insertion
					if (x + i < 0)
						continue; //pomijanie ujemntych indeksów

					cell[Index(x + i, y)] = insertion[i];
				}
				x++;
			}
		}
		catch(const exception& e){
			cout << "Failed to fill matrix";
			return false;
		}

		return true;
	}
	
	void printInRange(int n) {
		for (int i = 0; i < n; i++) {
			cout << left;
			for (int j = 0; j < n; j++) {
				cout << cell[Index(i, j)] << setw(2) << " ";
			}
			cout << endl;
		}
	}

};



int main() {
	Matrix matrix;
	if (!matrix.buildMatrix())
		return 0;
	matrix.printInRange(10);
}