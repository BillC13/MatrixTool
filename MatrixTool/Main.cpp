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

//    Matrix Matrix;
    

//    std::string inFile1 = "full1.txt", inFile2 = "full2.txt", outFile = "results.txt";
//     std::string inFile1 = argv[1], inFile2 = argv[2], outFile = argv[3];
     std::string inFile1 = "big1.txt", inFile2 = "big2.txt", outFile = "results.txt";
     char sign = '*';
//    char sign = '+';
    Matrix mat1(inFile1);
    Matrix mat2(inFile2);
    Matrix mat3 = mat1;
 //   if(sign == '+') Matrix mat3 = mat1 + mat2;
        switch (sign)
        {
        case('+'):
            mat3 = mat1 + mat2;
            break;
       case('-'):
            mat3 = mat1 - mat2;
            break;
        case('*'):
            mat3 = mat1 * mat2;
            break;
        case('/'):
            std::cout << "This feature is not implemented yet" << std::endl;
            return 2;
        }
  
    
 /*   std::vector<std::vector<double>> mat1;
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
    */
      mat3.printRes();
      mat3.outRes(outFile);
    
    return 0;
}
