#include <iostream>
#include <vector>
#include <fstream>  // For file handling

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

vector<vector<int>> convolve(const vector<vector<int>>& matrix, const vector<vector<int>>& kernel) {
    int n = matrix.size();
    int k = kernel.size();
    int output_size = n - k + 1;
    vector<vector<int>> output(output_size, vector<int>(output_size, 0));

    for (int i = 0; i < output_size; ++i) {
        for (int j = 0; j < output_size; ++j) {
            int sum = 0;
            for (int ki = 0; ki < k; ++ki) {
                for (int kj = 0; kj < k; ++kj) {
                    sum += matrix[i + ki][j + kj] * kernel[ki][kj];
                }
            }
            output[i][j] = sum;
        }
    }
    return output;
}

int main() {
    vector<vector<int>> matrix1 = readMatrixFromFile("input_matrix.in", 32, 32);

    vector<vector<int>> kernel = {
        {0, -1, 0},
        {-1, 5, -1},
        {0, -1, 0}
    };

    parsec_roi_begin();
    vector<vector<int>> output = convolve(matrix1, kernel);
    parsec_roi_end();

    return 0;
}
