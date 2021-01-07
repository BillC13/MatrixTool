#pragma once

#include <fstream> 
#include <iostream>
#include <string>
#include <vector>

class Matrix {
private:
	std::vector<std::vector<double>> mate;
	unsigned int mrows;
	unsigned int mcols;

public:
	// Matrix stuff and functions
	
	unsigned int getrows() const;
	unsigned int getcols() const;
	double& operator()(const unsigned int& rows, const unsigned int& cols);
	Matrix(unsigned int rows, unsigned int cols);
	Matrix(std::string Filname);
	Matrix(const Matrix& mat2);
	~Matrix();

	// Operators
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);

	//  Output
	void printRes() const;
	void outRes(std::string outFile) const;
};