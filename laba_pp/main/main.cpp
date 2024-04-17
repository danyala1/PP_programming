#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void writeMatrixToFile(string filename, const vector<vector<int>> &matrix)
{
    ofstream file("C:/PYTHON/laba_pp/matrix/matrix_1_2/" + filename);

    if (file.is_open())
    {
        for (const auto &row : matrix)
        {
            for (const int &element : row)
            {
                file << element << " ";
            }
            file << endl;
        }

        file.close();
        cout << "Matrix has been written to file: " << filename << endl;
    }
    else
    {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void createRandMatrix(string file_name, int size)
{
    vector<vector<int>> matrix(size, vector<int>(size));

    for (int i = 0; i < matrix.size(); i++)
    {
        for (int j = 0; j < matrix.size(); j++)
        {
            matrix[i][j] = rand() % 500;
        }
    }
    writeMatrixToFile(file_name, matrix);
}

std::vector<std::vector<int>> createMatrix(int size)
{
    return std::vector<std::vector<int>>(size, std::vector<int>(size));
}

int main()
{
    std::vector<int> sizes = {100, 250, 500, 750, 1000, 1500, 2000, 2500};

    for (int size : sizes)
        for (int i = 0; i < 5; i++)
        {
            std::vector<std::vector<int>> matrix_1 = createMatrix(size);
            std::vector<std::vector<int>> matrix_2 = createMatrix(size);
            std::vector<std::vector<int>> matrix_3 = createMatrix(size);

            createRandMatrix("m_1_" + std::to_string(size) + "_" + std::to_string(i + 1) + ".txt", size);
            createRandMatrix("m_2_" + std::to_string(size) + "_" + std::to_string(i + 1) + ".txt", size);
        }
    return 0;
}
