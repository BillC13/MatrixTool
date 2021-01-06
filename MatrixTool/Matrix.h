#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <vector>

class Matrix {
private:
	std::vector<std::vector<double>> mate;	

public:
	// Matrix stuff and functions
	unsigned mrows;
	unsigned mcols;
	unsigned getrows() const;
	unsigned getcols() const;
	double& operator()(const unsigned&, const unsigned&);
	Matrix(unsigned, unsigned, double);
	Matrix(std::string);
	Matrix(const Matrix&);
	Matrix(char);
	~Matrix();

	// Operators
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);

	//  Output
	void printRes() const;
	void outRes(std::string outFile) const;
};