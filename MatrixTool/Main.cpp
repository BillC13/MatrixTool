#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Matrix.h"

int main(int argc, char* argv[])
{
    // this program takes a matrix, either sparse or full, and multiplies it by a vector
    // It first performs this using triplet storage, and then checks this against a full matrix calculation

    Matrix matrix;

    //    std::string inFile1 = "full1.txt", inFile2 = "full2.txt", outFile = "results.txt";
    std::string inFile1 = argv[1], inFile2 = argv[2], outFile = argv[3];
    char sign = argv[4][0];
    //    char sign = signe[0];
    std::vector<std::vector<double>> mat1;
    switch (matrix.readFile(inFile1, mat1))
    {
    case(1):
        std::cout << "Couldn't open " << inFile1 << std::endl;
        return 1;
    case(2):
        std::cout << "Invalid matrix specifier in " << inFile1 << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> mat2;
    switch (matrix.readFile(inFile2, mat2))
    {
    case(1):
        std::cout << "Couldn't open " << inFile2 << std::endl;
        return 1;
    case(2):
        std::cout << "Invalid matrix specifier in " << inFile2 << std::endl;
        return 1;
    }

    std::vector<std::vector<double>> mat3;
    switch (matrix.readSign(sign, mat1, mat2, mat3))
    {
    case(1):
        std::cout << "Invalid operator " << std::endl;
        return 1;
    case(2):
        std::cout << "That feature is not currently implemented " << std::endl;
        return 1;
    case(3):
        std::cout << "The matrices are the wrong sizes " << std::endl;
        return 1;
    }

    matrix.printRes(mat3);
    matrix.outRes(outFile, mat3);

    return 0;
}
