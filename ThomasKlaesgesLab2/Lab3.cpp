#include <vector>
#include <string>
#include "ArithmeticShape.h"
using namespace std;

int main() {

	ArithmeticShape shape("X..XX.XXX");
	vector<string> shapeString = shape.stringify();
	cout << "Testing stringify:\n";
	for (int i = 0; i < 3; i++) {
		cout << shapeString[i] << endl;
	}
	cout << "Testing print:\n";
	cout << shape << endl;
	ArithmeticShape shape2("XXXXX..X.");
	cout << shape2;
	cout << "Testing Addition: \n";
	cout << shape + shape2;
	cout << "Testing Multiplication: \n";
	cout << shape * shape2;
	cout << "Testing Subtraction:\n";
	cout << shape - shape2;
}