#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Matrix.h"

int main(int argc, char* argv[])
{
//  this program performs simple matrix calculations
//  std::string inFile1 = argv[1], inFile2 = argv[2], outFile = argv[3];
//  char sign = argv[4][0];
    std::string inFile1 = "full1.txt", inFile2 = "full2.txt", outFile = "results.txt";
    char sign = '+';
    Matrix mat1(1, 1);
    Matrix mat2(1, 1);
    switch (mat1.readFile(inFile1))
    {
    case(1):
        std::cout << "Invalid file: " << inFile1 << std::endl;
        return 1;
    case(2):
        std::cout << "Error in file dimensions : " << inFile1 << std::endl;
        return 1;
    }

    switch (mat2.readFile(inFile2))
    {
    case(1):
        std::cout << "Invalid file: " << inFile2 << std::endl;
        return 1;
    case(2):
        std::cout << "Error in file dimensions : " << inFile2 << std::endl;
        return 1;
    }
    
    Matrix mat3(mat1.getcols(), mat2.getrows());
    switch (mat3.readSign(sign, mat1, mat2, mat3))
    {
    case(1):
        std::cout << "The matrices are the wrong size" << std::endl;
        return 1;
    case(2):
        std::cout << "This feature is not implemented yet" << std::endl;
        return 1;
    }
 
    mat3.printRes(); // Print results
    mat3.outRes(outFile); // Write results to output file
    
    return 0;
}
