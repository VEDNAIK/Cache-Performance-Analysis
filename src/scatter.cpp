#include <iostream>
#include <vector>
#include <cstdlib>  
#include <ctime>    
#include <fstream>  

using namespace std;


void parsec_roi_begin() 
{
   
}

void parsec_roi_end() 
{
}

vector<vector<int>> readMatrixFromFile(const string& filename, int rows, int cols) {
    ifstream infile(filename);
    vector<vector<int>> matrix(rows, vector<int>(cols, 0));  
    if (infile.is_open()) {
        for (int i = 0; i < rows; ++i) {
            for (int j = 0; j < cols; ++j) {
                infile >> matrix[i][j];  
            }
        }
        infile.close();
    } else {
        cerr << "Error opening file: " << filename << endl;
    }
    return matrix;
}


vector<vector<int>> scatterRandomData(vector<vector<int>>& matrix, int num_samples, int rows, int cols) {
    for (int i = 0; i < num_samples; i++) {
        int row = rand() % rows;     
        int col = rand() % cols;     
        int data = rand() % 100;     

        matrix[row][col] = data;     
    }
    return matrix;
}

int main() {
    srand(time(0));  

    vector<vector<int>> matrix1 = readMatrixFromFile("input_matrix.in", 150, 150);

    parsec_roi_begin();
    vector<vector<int>> C = scatterRandomData(matrix1, 1000, 150, 150);
    parsec_roi_end();
    return 0;
}