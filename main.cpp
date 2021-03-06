//Jakub Hirsz 180146

#include <iostream>
#include <map>
#include <math.h>

using namespace std;

const int N = 946;

typedef pair<unsigned int, unsigned int> Index; //(x,y)


class Matrix {
private:

	map<Index, double> cell;

public:

	Matrix() {}

	//[Index(x,y)] , r?wnowa?ne zapisowi [x][y]
	double operator[](const Index& index) {
		return cell[index]; 
	}
	
	bool buildMatrix() {

		const int a1 = 6, a2 = -1, a3 = -1;
		const int insertion[] = { a3, a2 , a1, a2, a3 };

		int x = -2;
		try {
			for (int y = 0; y < N; y++) {
				for (int i = 0; i < 5; i++) {//5 warto?ci w tablicy insertion
					if (x + i < 0)
						continue; //pomijanie ujemntych indeks?w

					cell[Index(x + i, y)] = insertion[i];
				}
				x++;
			}
		}
		catch(const exception& e){ // W przypadku b??du zako?cz program
			cout << "Failed to fill matrix";
			return false;
		}

		return true;
	}
	
	//Wypisanie w konsoli pierwszych N x N element?w macierzy

	void printInRange(int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cout << cell[Index(i, j)] << " ";
			}
			cout << endl;
		}
	}

};

class Vector {
private:
	map<unsigned int, double> cell;

public:
	double operator[](const int& index){
		return cell[index];
	}

	bool buildVector() {
		try {

			for (int i = 0; i < N; i++) {
				cell[i] = sin(i);
				cout << sin(i);
			}
		}
		catch (const exception& e) {
			cout << "Wyjatek przy tworzeniu wektora ";
			return false;
		}
		return true;
	}

	void printInRange(int n) {
		for (int i = 0; i < n; i++) {
			cout << cell[i] << " ";
		}
		cout << endl;
	}

};

int main() {
	Matrix matrix;
	Vector b;

	if (!matrix.buildMatrix())
		return -1;
	if (!b.buildVector())
		return -2;

	matrix.printInRange(10);

	cout << endl;

	b.printInRange(10);
}