#include <iostream>
#include <vector>
using namespace std;

class ArrayMultiplier {
public:
    virtual void calculate() = 0;
    virtual ~ArrayMultiplier() {}
};

class ArrayMultiplier1D : public ArrayMultiplier {
private:
    vector<int> arr;

public:
    ArrayMultiplier1D(vector<int> input) : arr(input) {}

    void calculate() override {
        if (arr.empty()) {
            cout << "1D Array is empty." << std::endl;
            return;
        }
        
        long long result = 1;
        for (int val : arr) {
            result *= val;
        }
        std::cout << "1D Array Product: " << result << std::endl;
    }
};

class ArrayMultiplier2D : public ArrayMultiplier {
private:
    vector<vector<int>> A;
    vector<vector<int>> B;

public:
    ArrayMultiplier2D(vector<vector<int>> m1, vector<vector<int>> m2) 
        : A(m1), B(m2) {}

    void calculate() override {
        size_t r1 = A.size();
        size_t c1 = A[0].size();
        size_t r2 = B.size();
        size_t c2 = B[0].size();

        if (c1 != r2) {
            cout << "Error: Inner dimensions do not match for multiplication." << endl;
            return;
        }

        vector<vector<int>> result(r1,vector<int>(c2, 0));

        for (size_t i = 0; i < r1; ++i) {
            for (size_t j = 0; j < c2; ++j) {
                for (size_t k = 0; k < c1; ++k) {
                    result[i][j] += A[i][k] * B[k][j];
                }
            }
        }

        cout << "Resulting Matrix (" << r1 << "x" << c2 << "):" <<endl;
        for (const auto& row : result) {
            for (int val : row) {
                cout << val << " ";
            }
            cout <<endl;
        }
    }
};

int main() {
    vector<vector<int>> mat1 = {
        {1, 2, 3},
        {4, 5, 6}
    };

    vector<vector<int>> mat2 = {
        {7, 8},
        {9, 10},
        {11, 12}
    };

    vector<int>m1={1,2,3};
    ArrayMultiplier* multiplier = new ArrayMultiplier2D(mat1, mat2);
    multiplier->calculate();

    ArrayMultiplier* product = new ArrayMultiplier1D(m1);
    product->calculate();
    
    delete product;
    delete multiplier;
    return 0;
}