#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

int Matrix::readFile(std::string filename, std::vector<std::vector<double>>& mate) // Reads matrix files
{
    // Check to see if input file exists
    std::ifstream myfile(filename);
    if (!myfile.is_open()) return 1;
    // Open the input file
    std::string dim;
    (getline(myfile, dim));
    std::stringstream dims(dim);
    std::vector<int> xy{ std::istream_iterator<int>(dims), std::istream_iterator<int>() };
    k = xy[0];

    if (xy.size() == 1)
    {
        l = k;
    }
    else if (xy.size() == 2)
    {
        l = xy[1];
    }
    else
    {
        return 1;
    }

    double z;
    for (int i = 0; i < k; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < l; j++)
        {
            myfile >> z;
            temp.push_back(z);
        }
        mate.push_back(temp);
    }
    myfile.close();    //close the file object. 

    return 0;
}

int Matrix::readSign(char sign, std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Checks dimensions and calls matrix functions
{
    switch (sign)
    {
    case('+'):
        if ((mat1.size() != mat2.size()) || (mat1[0].size() != mat2[0].size())) return 3;
        matAdd(mat1, mat2, mat3);
        break;
    case('-'):
        if ((mat1.size() != mat2.size()) || (mat1[0].size() != mat2[0].size())) return 3;
        matSub(mat1, mat2, mat3);
        break;
    case('*'):
        if ((mat1.size() != mat2[0].size())) return 3;
        matMul(mat1, mat2, mat3);
        break;
    case('/'):
        if ((mat1.size() != mat1[0].size()) || (mat2.size() != mat2[0].size()) || (mat1.size() != mat2.size())) return 3;
        return 2;
    }
    return 0;
}

int Matrix::matAdd(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Adds matrices
{
    for (int i = 0; i < k; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < l; j++)
        {
            temp.push_back(mat1[i][j] + mat2[i][j]);
        }
        mat3.push_back(temp);
    }
    return 0;
}

int Matrix::matSub(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Subtracts matrices
{
    for (int i = 0; i < k; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < l; j++)
        {
            temp.push_back(mat1[i][j] - mat2[i][j]);
        }
        mat3.push_back(temp);
    }
    return 0;
}

int Matrix::matMul(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Multiplies matrices
{
    for (int i = 0; i < k; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < l; j++)
        {
            double madd = 0;
            for (int m = 0; m < k; m++)
            {
                madd += (mat1[i][m] + mat2[m][j]);
            }
            temp.push_back(madd);
        }
        mat3.push_back(temp);
    }
    return 0;
}

int Matrix::matDiv(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // I'm not doing this
{
    return 0;
}

void Matrix::printRes(std::vector<std::vector<double>> mat3) { // Print the result
    std::cout << "The result is" << std::endl;
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            std::cout << mat3[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void Matrix::outRes(std::string filename, std::vector<std::vector<double>> mat3) { // Write the result
    std::ofstream myfile(filename);
    for (int i = 0; i < k; i++)
    {
        for (int j = 0; j < k; j++)
        {
            myfile << mat3[i][j] << " ";
        }
        myfile << "" << std::endl;
    }
    myfile.close();
}