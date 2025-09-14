#include <iostream>
#include <string>
using namespace std;

struct Mahasiswa {
    string nama;
    int nim;
    float ipk;
};

void sortingIPK(Mahasiswa mhs[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (mhs[i].ipk > mhs[j].ipk) {
                Mahasiswa temp = mhs[i];
                mhs[i] = mhs[j];
                mhs[j] = temp;
            }
        }
    }
}

int main() {
    const int jumlah = 4;
    Mahasiswa mhs[jumlah];

    for (int i = 0; i < jumlah; i++) {
        cout << "Masukkan data mahasiswa ke-" << i + 1 << " : \n";
        cout << "Nama (Tanpa Menggunakan Spasi) : ";
        cin >> mhs[i].nama;
        cout << "NIM : ";
        cin >> mhs[i].nim;
        cout << "IPK : ";
        cin >> mhs[i].ipk;
        
    }

    sortingIPK(mhs, jumlah);

    cout << "Data Mahasiswa setelah diurutkan berdasarkan IPK:\n";
    for (int i = 0; i < jumlah; i++) {
        cout << i + 1 << ". "
             << "Nama: " << mhs[i].nama << ", "
             << "NIM: " << mhs[i].nim << ", "
             << "IPK: " << mhs[i].ipk << endl;
    }

    return 0;
}