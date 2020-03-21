#ifndef MATRIX_H
#define MATRIX_H

#include<string>
#include <vector>
#include <cstdlib>
using std::vector;
void checkIsCorrectMatrix(vector<vector<int>> &);

void add_matrices(vector<vector<int>> &,vector<vector<int>> &,vector<vector<int>> &);

void multiply_matrices(vector<vector<int>> &,vector<vector<int>> &,vector<vector<int>> & );
void matrix_det(vector<vector<int>> &,vector<vector<int>> &);

void disp(vector<vector<int>> &);

std::string matrixCheckInput(std::string);

#endif // MATRIX_H
