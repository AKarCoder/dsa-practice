#include <iostream>
#include <vector>

using namespace std;


// Wave Print a 2D vector in O(m*n) time and Constant space
void wavePrint(vector<vector<int>> &matrix)
{
    int col = 0; // Col indicator

    while (col < matrix[0].size())
    {
        // down loop
        for (int row = 0; row < matrix.size(); row++)
        {
            cout << matrix[row][col] << " ";
        }
        col++;

        // up loop
        for (int row = matrix.size() - 1; row >= 0; row--)
        {
            cout << matrix[row][col] << " ";
        }
        col++;
    }
    cout << endl;
}

int main()
{
    // matrix
    vector<vector<int>> matrix = {{1, 2, 3, 4},
                                  {5, 6, 7, 8},
                                  {9, 10, 11, 12},
                                  {13, 14, 15, 16},
                                  {17, 18, 19, 20}};

    cout << "Wave Print of Matrix : " << endl;
    wavePrint(matrix);
    return 0;
}