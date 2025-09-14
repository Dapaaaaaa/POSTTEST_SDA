#include <iostream>
using namespace std;

void membalikArray (int* array, int i) {
    int* awal = array;
    int* akhir = array + i - 1;
    while (awal < akhir) {
        int temp = *awal;
        *awal = *akhir;
        *akhir = temp;
        awal++;
        akhir--;
    }
    return;
}

int main() {
    const int data = 7;

    int array[data] = {2,3,5,7,11,13,17};

    cout << "Array sebelum dibalik : ";
    for (int i = 0; i < data; i++) {
        cout << array[i] << " ";
    }
    cout << endl;

    membalikArray(array, data);

    cout << "Array setelah dibalik : ";
    for (int i = 0; i < data; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
}