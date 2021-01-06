#include "Matrix.h"

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

// Constructor for Any Matrix
Matrix::Matrix(unsigned rows, unsigned cols, double z) {
    mrows = rows;
    mcols = cols;
    mate.resize(rows);
    for (unsigned i = 0; i < mate.size(); i++)
    {
        mate[i].resize(cols, z);
    }
}

Matrix::Matrix(std::string filename) // Constructor - reads matrix file
{
    // Check to see if input file exists
    std::ifstream myfile(filename);
    mcols = 0, mrows = 0;
    if (myfile.is_open())
    {
        // Open the input file
        std::string dim;
        (getline(myfile, dim));
        std::stringstream dims(dim);
        std::vector<int> xy{ std::istream_iterator<int>(dims), std::istream_iterator<int>() };
        mcols = xy[0];

        if (xy.size() == 1)
        {
            mrows = mcols;
        }
        else if (xy.size() == 2)
        {
        mrows = xy[1];
        }
        else
        {
        std::cout << "Getcha!" << std::endl;
        }

        int rows = mrows, cols = mcols;
        double z;

        mate.resize(rows);
        for (int i = 0; i < rows; i++)
        {
            mate[i].resize(cols);
        }

        for (unsigned i = 0; i < mcols; i++)
        {
            for (unsigned j = 0; j < mrows; j++)
            {
                myfile >> z;
                mate[i][j] = z;
            }
        }
        myfile.close();    //close the file object. 
    }
    else
    {
    std::cout << "Getcha!" << std::endl;
    }
}

Matrix::Matrix(const Matrix& Mat2)
{
    this->mcols = Mat2.getcols();
    this->mrows = Mat2.getrows();
    this->mate = Mat2.mate;
}
/*
Matrix::Matrix(char sign)
{
    switch (sign)
    {
    case('+'):
         mat3 = mat1 + mat2;
        break;
    case('-'):
        //        if ((mat1.size() != mat2.size()) || (mat1[0].size() != mat2[0].size())) return 3;
        //        mat3 = mat1 + mat2;
        break;
    case('*'):
        //        if ((mat1.size() != mat2[0].size())) return 3;
        //        mat3 = mat1 + mat2;
        break;
    case('/'):
        //        if ((mat1.size() != mat1[0].size()) || (mat2.size() != mat2[0].size()) || (mat1.size() != mat2.size())) return 3;
        return 2;
    }
    return 0;
}
*/
Matrix::~Matrix() {

}

Matrix Matrix::operator+(Matrix& mat2)
{
    Matrix result(mcols, mrows, 0.0);
    for (unsigned i = 0; i < mrows; i++)
    {
        for (unsigned j = 0; j < mcols; j++)
        {
            result(i, j) = this->mate[i][j] + mat2(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator-(Matrix& mat2)
{
    Matrix result(mcols, mrows, 0.0);
    for (unsigned i = 0; i < mrows; i++)
    {
        for (unsigned j = 0; j < mcols; j++)
        {
            result(i, j) = this->mate[i][j] - mat2(i, j);
        }
    }
    return result;
}

Matrix Matrix::operator*(Matrix& mat2)
{
    Matrix result(mcols, mrows, 0.0);
    for (unsigned i = 0; i < mrows; i++)
    {
        for (unsigned j = 0; j < mcols; j++)
        {
            for (unsigned k = 0; k < mrows; k++)
            {
                result(i, j) += this->mate[i][k] * mat2(k, j);
            }
        }
    }
    return result;
}

/*
int Matrix::matAdd(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Adds matrices
{
    for (int i = 0; i < mcols; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < mrows; j++)
        {
            temp.push_back(mat1[i][j] + mat2[i][j]);
        }
        mat3.push_back(temp);
    }
    return 0;
}

int Matrix::matSub(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Subtracts matrices
{
    for (int i = 0; i < mcols; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < mrows; j++)
        {
            temp.push_back(mat1[i][j] - mat2[i][j]);
        }
        mat3.push_back(temp);
    }
    return 0;
}

int Matrix::matMul(std::vector<std::vector<double>> mat1, std::vector<std::vector<double>> mat2, std::vector<std::vector<double>>& mat3) // Multiplies matrices
{
    for (int i = 0; i < mcols; i++)
    {
        std::vector<double> temp;
        for (int j = 0; j < mrows; j++)
        {
            double madd = 0;
            for (int m = 0; m < mcols; m++)
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
*/
void Matrix::printRes() const // Print the result
{ 
    std::cout << "The result is" << std::endl;
    for (unsigned i = 0; i < mrows; i++)
    {
        for (unsigned j = 0; j < mcols; j++)
        {
            std::cout << mate[i][j] << " ";
        }
        std::cout << "" << std::endl;
    }
}

void Matrix::outRes(std::string filename) const // Write the result
{ 
    std::ofstream myfile(filename);
    for (unsigned i = 0; i < mcols; i++)
    {
        for (unsigned j = 0; j < mrows; j++)
        {
            myfile << mate[i][j] << " ";
        }
        myfile << "" << std::endl;
    }
    myfile.close();
}

// Returns matrix value at given location
double& Matrix::operator()(const unsigned& row, const unsigned& col)
{
    return this->mate[row][col];
}

// Return row
unsigned Matrix::getrows() const
{
    return this->mrows;
}

// Return column
unsigned Matrix::getcols() const
{
    return this->mcols;
}
