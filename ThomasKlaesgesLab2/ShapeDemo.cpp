#include <vector>
#include <iostream>
#include <string>
#include "ArithmeticShape.h"
using namespace std;

//Thomas Klaesges

int main() {

	cout << "Printing a 3x3 ArithmeticShape:\n";
	ArithmeticShape shape("X.XXX..X.");
	cout << shape;

	cout << "Printing a 4x3 and 3x4 shape:\n";

	ArithmeticShape shape1("X.XXXX..X.X.", 4, 3);
	ArithmeticShape shapeDeezNuts("X.XXXX..X.X.", 3, 4);
	cout << shape1 << endl;
	cout << shapeDeezNuts;

	cout << "Change filled and empty:\n";
	ArithmeticShape ligmaBallz("X.XX.XX..");
	ligmaBallz.setFilled(':');
	ligmaBallz.setEmpty('-');
	cout << ligmaBallz;

	ArithmeticShape shape2("XX..X.XX.");
	vector<string> shapeString;
	shapeString = shape.stringify();
	vector<string> shape2String;
	shape2String = shape2.stringify();

	ArithmeticShape result = shape + shape2;
	vector<string> resultString = result.stringify();

	cout << "Testing Addition:\n";

	//For loop to display the arithmetic horizontally
	for (int i = 0; i < 3; i++) {
		if (i == 1) {
			cout << shapeString[i] << " + " << shape2String[i] << " = " << resultString[i] << endl;
		}
		else {
			cout << shapeString[i] << "   " << shape2String[i] << "   " << resultString[i] << endl;
		}
	}

	cout << "Testing Multiplication:\n";

	ArithmeticShape product = shape * shape2;
	vector<string> productString = product.stringify();

	for (int i = 0; i < 3; i++) {
		if (i == 1) {
			cout << shapeString[i] << " * " << shape2String[i] << " = " << productString[i] << endl;
		}
		else {
			cout << shapeString[i] << "   " << shape2String[i] << "   " << productString[i] << endl;
		}
	}

	cout << "Testing Subtraction:\n";

	ArithmeticShape difference = shape - shape2;
	vector<string> differenceString = difference.stringify();

	for (int i = 0; i < 3; i++) {
		if (i == 1) {
			cout << shapeString[i] << " - " << shape2String[i] << " = " << differenceString[i] << endl;
		}
		else {
			cout << shapeString[i] << "   " << shape2String[i] << "   " << differenceString[i] << endl;
		}
	}

}