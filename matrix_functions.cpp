#include "matrix_functions.h"

using namespace std;
void checkIsCorrectMatrix(vector<vector<int>> & v1)
{
    int j = v1[0].size();
    for(int i=1;i<v1.size();++i){
        if(v1[i].size() != j)
            throw "Wrong Constructed Matrix";
    }
}
void add_matrices(vector<vector<int>> & v1,vector<vector<int>> & v2,vector<vector<int>> & result){
    checkIsCorrectMatrix(v1);
    checkIsCorrectMatrix(v2);
    result.clear();
    if(v1.size() != v2.size())
        throw "Wrong size";

    for (int i = 0; i < v1.size() ; i++)
	{
	    vector<int>temp;
        for (int j = 0; j < v1.size(); j++)
		{
            temp.push_back( v1 [i][j] + v2 [i][j]);
		}
		result.push_back(temp);
	}
}

void multiply_matrices(vector<vector<int>> & v1,vector<vector<int>> & v2,vector<vector<int>> & result){
    checkIsCorrectMatrix(v1);
    checkIsCorrectMatrix(v2);
    result.clear();
    int r1 = v1.size(), c1 = v1[0].size(), r2 = v2.size(), c2 = v2[0].size(), i, j, k;
    if (c1 != r2)
    {
        throw "Matrices cannot be multiplied!";
    }
    for (i = 0; i < r1; i++)
    {
        vector<int>temp;
        for (j = 0; j < c2; j++)
        {
            temp.push_back(0);
            for (k = 0; k < r2; k++)
            {
                temp[temp.size()-1] += (v1[i][k] * v2[k][j]);
            }
        }
        result.push_back(temp);
    }
}

void matrix_det(vector<vector<int>> &m1,vector<vector<int>> &result)
{
    checkIsCorrectMatrix(m1);
    result.clear();
    if(m1.size() == 2)
        result.push_back(vector<int>{m1[0][0]*m1[1][1] - m1[0][1]*m1[1][0]});
    if(m1.size() == 3)
        result.push_back(vector<int>{m1[0][0]*m1[1][1]*m1[2][2] + m1[0][1]*m1[1][2]*m1[2][0] + m1[0][2]*m1[1][0]*m1[2][1] -
                m1[2][0]*m1[1][1]*m1[0][2] - m1[2][1]*m1[1][2]*m1[0][0] - m1[2][2]*m1[1][0]*m1[0][1]});
    else throw "Cannot calculate";
}

string matrixCheckInput(string input){
    bool open = false;
    bool vectorOpen = false;
    bool useFirst = true;
    vector<vector<int>> matrix1;
    vector<vector<int>> matrix2;
    vector<int> v;
    string f="";

    for(char c:input){
        if(useFirst){
            if(vectorOpen){
                if(c>=48 && c<=57){
                    v.push_back(c-48);
                }
                else if(c == '}'){
                    vectorOpen = false;
                    matrix1.push_back(v);
                    v.clear();
                }
            }
            else if(open){
                if(c == '{'){
                    vectorOpen = true;
                }
                else if(c == '}'){
                    open = false;
                    useFirst = false;
                }

            }
            else if(c == '{'){
                open = true;
            }
        }
        else{
            if(vectorOpen){
                if(c>=48 && c<=57){
                    v.push_back(c-48);
                }
                else if(c == '}'){
                    vectorOpen = false;
                    matrix2.push_back(v);
                    v.clear();
                }
            }
            else if(open){
                if(c == '{'){
                    vectorOpen = true;
                }
                else if(c == '}'){
                    open = false;
                }

            }
            else if(c == '{'){
                open = true;
            }
        }
        if(c == '+')
            f = "add";
        if(c == '*')
            f = "mul";


    }

    string r="";

    vector<vector<int>> matrix;
    if(f == "add")
        add_matrices(matrix1,matrix2,matrix);
    else if(f == "mul")
        multiply_matrices(matrix1,matrix2,matrix);
    else if(f =="")
        matrix_det(matrix1,matrix);


    for(vector<int> v :matrix){
        for(int i:v){
            char c[32];
            itoa(i,c,10);
            r+= c;
            r+=" ";
        }
        r += '\n';
    }
    return r;
}


