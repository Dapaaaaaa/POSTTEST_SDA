#include <iostream>
using namespace std;

void tukar (int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
}

int main() {
    int x, y;
    cout << "Masukan nilai X : ";
    cin >> x;
    cout << "Masukan nilai Y : ";
    cin >> y;

    cout << "Sebelum ditukar : " << endl;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;

    tukar(x, y);

    cout << "Setelah ditukar : " << endl;
    cout << "X = " << x << endl;
    cout << "Y = " << y << endl;
    
    return 0;
}