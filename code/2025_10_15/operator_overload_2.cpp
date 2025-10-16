//
// Created by PC on 2025/10/16.
//

#include <iomanip>
#include <iostream>
#include <vector>
using std::vector;

class Matrix {
public:
    explicit Matrix(vector<vector<int>> data): data(std::move(data)) {}

    Matrix operator*(const Matrix& other) const {
        const int kColumns = other.data[0].size(), kRows = data.size();
        vector<vector<int>> new_data(kColumns);
        for (int r = 0; r < kRows; ++r) {
            new_data[r].resize(kRows);
            for (int c = 0; c < kColumns; ++c) {
                int result = 0;
                for (int i = 0; i < data[0].size(); ++i) {
                    result += data[r][i] * other.data[i][c];
                }
                new_data[r][c] = result;
            }
        }
        return Matrix(new_data);
    }

    friend std::ostream & operator<<(std::ostream &os, const Matrix &obj) {
        for (int r = 0; r < obj.data.size(); ++r) {
            for (int c = 0; c < obj.data[0].size(); ++c) {
                std::cout << std::setw(5) << std::left << obj.data[r][c];
            }
            std::cout << '\n';
        }
        return os;
    }
private:
    vector<vector<int>> data;
};

int main() {
    Matrix m1({{1,2}});
    Matrix m2({{3}, {4}});
    std::cout << m1 * m2 << std::endl;
    std::cout << m2 * m1 << std::endl;
    Matrix m3({{1,2},{3,4}});
    std::cout << m3 * m3 << std::endl;
}