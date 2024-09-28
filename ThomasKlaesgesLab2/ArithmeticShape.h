#pragma once
#include <iostream>
#include <string>
#include <vector>
using namespace std;

//Thomas Klaesges

class ArithmeticShape {
	
private:
	const int WIDTH;
	const int HEIGHT;

	char filled;
	char empty;

public:
	vector<vector<bool>> points;
	//Constructor for a default height and width
	ArithmeticShape(string input) : WIDTH(3), HEIGHT(3) {
		filled = 'X';
		empty = '.';
		int z{ 0 };

		for (int i = 0; i < HEIGHT; i++) {
			vector<bool> tempVec;
			points.push_back(tempVec);
			for (int j = 0; j < WIDTH; j++) {
				if (input[z] == filled) {
					points[i].push_back(true);
				}
				else {
					points[i].push_back(false);
				}
				z++;
			}
		}
	}
	//Constructor for a custom height and width
	ArithmeticShape(string input, int width, int height) : WIDTH(width), HEIGHT(height) {
		filled = 'X';
		empty = '.';
		int z{ 0 };

		for (int i = 0; i < HEIGHT; i++) {
			vector<bool> tempVec;
			points.push_back(tempVec);
			for (int j = 0; j < WIDTH; j++) {
				if (input[z] == filled) {
					points[i].push_back(true);
				}
				else {
					points[i].push_back(false);
				}
				z++;
			}
		}
	}
	//default constructor
	ArithmeticShape() : HEIGHT(3), WIDTH(3){
		filled = 'X';
		empty = '.';
	}

	//METHODS
	int getHeight() const {
		return HEIGHT;
	}
	int getWidth() const {
		return WIDTH;
	}
	char getFilled() const {
		return filled;
	}
	char getEmpty() const {
		return empty;
	}
	void setFilled(char n) {
		filled = n;
	}
	void setEmpty(char n) {
		empty = n;
	}
	//Takes each vector of booleans inside of points and converts each nested vector into one string of 
	//the shape's characters and stores all the strings in a vector that is then returned
	vector<string> stringify() const {
		vector<string> vec;
		string line{ "" };

		for (int i = 0; i < HEIGHT; i++) {
			for (int j = 0; j < WIDTH; j++) {
				if (points[i][j]) {
					line += string(1, filled);
				}
				else {
					line += string(1, empty);
				}
			}
			vec.push_back(line);
			line = "";
		}
		return vec;
	}

	//OPERATOR OVERLOADS
	ArithmeticShape operator+(const ArithmeticShape& other) {
		string newShape{ "" };
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				if (this->points[i][j] || other.points[i][j]) {
					newShape += string(1, this->filled);
				}
				else { newShape += string(1, this->empty); }
			}
		}
		return ArithmeticShape(newShape, WIDTH, HEIGHT);
	}
	//Multiplication
	ArithmeticShape operator*(const ArithmeticShape& other) {
		string newShape{ "" };
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				if (this->points[i][j] && other.points[i][j]) {
					newShape += string(1, this->filled);
				}
				else { newShape += string(1, this->empty); }
			}
		}
		return ArithmeticShape(newShape, WIDTH, HEIGHT);

	}
	//Subtraction
	ArithmeticShape operator-(const ArithmeticShape& other) {
		string newShape{ "" };
		for (int i = 0; i < WIDTH; i++) {
			for (int j = 0; j < HEIGHT; j++) {
				if (this->points[i][j] && !(other.points[i][j])) {
					newShape += string(1, this->filled);
				}
				else { newShape += string(1, this->empty); }
			}
		}
		return ArithmeticShape(newShape, WIDTH, HEIGHT);
	}
};


//OSTREAM OVERLOAD
std::ostream& operator<<(std::ostream& out, const ArithmeticShape printShape) {
	vector<string> vector = printShape.stringify();
	for (string line : vector) {
		out << line << endl;
	}
	return out;
}