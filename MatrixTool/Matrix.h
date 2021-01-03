#pragma once

#include <vector>
#include <string>

class Matrix {
private:
	int k = 0, l = 0;

public:
	int readFile(std::string filename, std::vector<std::vector<double>>& mate);
	int readSign(char sign, std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
	int matAdd(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
	int matSub(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
	int matMul(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
	int matDiv(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3);
	void printRes(std::vector<std::vector<double>> mat3);
	void outRes(std::string outFile, std::vector<std::vector<double>> mat3);
};