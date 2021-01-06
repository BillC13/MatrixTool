#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <vector>
#include "Matrix.h"

int main(int argc, char* argv[])
{
// this program performs simple matrix calculations
    
     std::string inFile1 = argv[1], inFile2 = argv[2], outFile = argv[3];
     char sign = argv[4][0];
 //   std::string inFile1 = "full1.txt", inFile2 = "full2.txt", outFile = "results.txt";
 //   char sign = '+';
    Matrix mat1(inFile1);
    Matrix mat2(inFile2);
    Matrix mat3(mat1.getcols(), mat2.getrows(), 0);
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
 
      mat3.printRes(); // Print results
      mat3.outRes(outFile); // Write results to output file
    
    return 0;
}
