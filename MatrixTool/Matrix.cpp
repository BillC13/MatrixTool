#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Matrix.h"

Matrix::Matrix(unsigned rows, unsigned cols, double z) { // Constructor for Any Matrix
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
    std::cout << "There was an error" << std::endl;
    }
}

Matrix::Matrix(const Matrix& Mat2)
{
    this->mcols = Mat2.getcols();
    this->mrows = Mat2.getrows();
    this->mate = Mat2.mate;
}

Matrix::~Matrix() {

}

Matrix Matrix::operator+(Matrix& mat2) // Matrix addition
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

Matrix Matrix::operator-(Matrix& mat2) // Matrix subtraction
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

Matrix Matrix::operator*(Matrix& mat2) // Matrix multiplication
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

double& Matrix::operator()(const unsigned& row, const unsigned& col) // Returns matrix value at given location
{
    return this->mate[row][col];
}

unsigned Matrix::getrows() const // Return row
{
    return this->mrows;
}

unsigned Matrix::getcols() const // Return column
{
    return this->mcols;
}
