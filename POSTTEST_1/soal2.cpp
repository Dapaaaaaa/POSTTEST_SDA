#include <iostream>
using namespace std;

int main() {
    int matrix[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int genap = 0;
    for (int i = 0; i < 3; i++) {
        if (i % 2 == 1) {
            for (int j =0; j < 3; j++) {
                genap += matrix[i][j];
            }
        }
    }

    cout << "Matriks 3 x 3 : \n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Jumlah bilangan genap : " << genap << endl;
    return 0;
}