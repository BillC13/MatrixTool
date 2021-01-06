#pragma once

#include <stdio.h>
#include <fstream> // for file access
#include <iostream>
#include <stdlib.h>
#include <sstream>
#include <string>
#include <vector>
#include <tuple>
#include <cmath>

class Matrix {
private:
	unsigned mrows;
	unsigned mcols;
	std::vector<std::vector<double>> mate;	

public:
	Matrix(unsigned, unsigned, double);
	Matrix(std::string);
	Matrix(const Matrix&);
	Matrix(char);
	Matrix operator+(Matrix&);
	Matrix operator-(Matrix&);
	Matrix operator*(Matrix&);
	~Matrix();
//	int readSign(char sign);
    int readSign(char sign, Matrix mat1, Matrix mat2);
//	int matAdd(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
//	int matSub(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
//	int matMul(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
//	int matDiv(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
	
	void outRes(std::string outFile) const;
	double& operator()(const unsigned&, const unsigned&);
	unsigned getrows() const;
	unsigned getcols() const;
	void printRes() const;
	
};