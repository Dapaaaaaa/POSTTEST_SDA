#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <cstdlib>
using namespace std;

struct jadwal
{
    string kodePenerbangan;
    string tujuan;
    string status;
    jadwal *next;
};

jadwal *head = nullptr;
int jumlahJadwal = 0;

void cls() {
    system("cls");
}

void delay(int seconds) {
    this_thread::sleep_for(chrono::seconds(seconds));
}

void style() {
    cout << "------------------------------\n";
}

void style2() {
    cout << "==============================\n";
}

string pilihStatus() {
    int pilih;
    cout << "1. Tepat Waktu\n";
    cout << "2. Terlambat\n";
    cout << "3. Boarding\n";
    cout << "4. Dalam Penerbangan\n";
    cout << "5. Mendarat\n";
    cout << "6. Dibatalkan\n";
    cout << "Pilih (1-6): ";
    cin >> pilih;
    cin.ignore();

    switch (pilih) {
        case 1: return "Tepat Waktu";
        case 2: return "Terlambat";
        case 3: return "Boarding";
        case 4: return "Dalam Penerbangan";
        case 5: return "Mendarat";
        case 6: return "Dibatalkan";
        default: return "Tidak Diketahui";
    }
}

// Fungsi untuk membuat kode penerbangan otomatis berdasarkan NIM
string buatKodePenerbangan(string nim, int index) {
    string kode = nim.substr(nim.size() - 3);
    if (index == 0) {
        return "JT-" + kode;
    } else {
        return "JT-" + kode + "-" + to_string(index);
    }
}

// Fungsi untuk menambahkan jadwal penerbangan di akhir atau ekor
void tambahJadwal(string nim) {
    jadwal *baru = new jadwal;
    baru->kodePenerbangan = buatKodePenerbangan(nim, jumlahJadwal);
    cls();
    style2();
    cout << "Masukkan tujuan penerbangan : ";
    cin.ignore();
    getline(cin, baru->tujuan);
    cout << "Masukan status penerbangan : ";
    baru->status = pilihStatus();
    baru->next = nullptr;

    if (head == nullptr) {
        head = baru;
    } else {
        jadwal *temp = head;
        while (temp->next != nullptr) {
            temp = temp->next;
        }
        temp->next = baru;
    }
    jumlahJadwal++;
    cls();
    cout << "Jadwal penerbangan berhasil ditambahkan!. \n" << endl;
    delay(2);
    cls();
}

// Menyisipkan di posisi (AddSpesific) sesuai NIM + 1
// Jika NIM ...042, posisi sisip adalah 2 + 1 = 3.
// Jika digit terakhir nim anda 0 maka jadinya 0 + 2 = 2

void menyisipkanJadwal(string nim) {
    if (head == nullptr) {
        cls();
        cout << "Data jadwal kosong, silahkan tambah jadwal terlebih dahulu.\n";
        delay(2);
        cls();
        return;
    }

    // Untuk menyisipkan berdasarkan digit terakhir NIM + 1 atau 2 sesuai ketentuan post test
    char digitAkhir = nim[nim.size() - 1];
    int digit = digitAkhir - '0';
    int posisi;
    if (digit == 0) posisi = 2;
    else posisi = digit + 1;

    jadwal *baru = new jadwal;
    baru->kodePenerbangan = buatKodePenerbangan(nim, jumlahJadwal);
    cls();
    style2();
    cout << "Masukkan tujuan penerbangan : ";
    cin.ignore();
    getline(cin, baru->tujuan);
    cout << "Masukan status penerbangan : ";
    getline(cin, baru->status);

    // Sisipkan di posisi
    jadwal *temp = head;
    int index = 1;

    // jika posisi 1, maka sisipkan di depan
    if (posisi == 1) {
        baru->next = head;
        head = baru;
    } 
    // Cari node sebelum posisi yang diinginkan
    else {
        while (index < posisi -1 && temp->next != nullptr) {
            temp = temp->next;
            index++;
        }
        baru->next = temp->next;
        temp->next = baru;
    }

    jumlahJadwal++;
    cls();
    cout << "Jadwal penerbangan berhasil disisipkan pada posisi " << posisi << "!\n" << endl;
    delay(2);
    cls();
}

// Fungsi untuk menghapus jadwal penerbangan dari awal atau kepala (head)
void hapusJadwal() {
    if (head == nullptr) {
        cls();
        cout << "Data jadwal kosong, tidak ada yang dihapus.\n";
        delay(2);
        cls();
        return;
    }

    jadwal *hapus = head;
    head = head->next;
    cls();
    cout << "Menghapus jadwal penerbangan dengan kode : " << hapus->kodePenerbangan << endl;
    delete hapus;
    jumlahJadwal--;
    cls();
    cout << "Jadwal penerbangan berhasil dihapus dari awal!\n" << endl;
    delay(2);
    cls();
}

// Fungsi untuk mengubah status penerbangan dengan kode penerbangan
void ubahStatus() {
    if (head == nullptr) {
        cls();
        cout << "Data jadwal kosong, tidak ada yang diubah.\n";
        delay(2);
        cls();
        return;
    }

    string kode;
    cls();
    style2();
    cout << "Masukkan kode penerbangan yang akan diubah statusnya : ";
    cin >> kode;

    jadwal *temp = head;
    bool ditemukan = false;
    while (temp != nullptr) {
        if (temp->kodePenerbangan == kode) {
            cout << "Masukkan status baru : \n";
            cin.ignore();
            temp->status = pilihStatus();
            cls();
            cout << "Status penerbangan berhasil diubah!\n" << endl;
            delay(2);
            cls();
            ditemukan = true;
            break;
        }
        temp = temp->next;
    }
    
    if (!ditemukan) {
        cls();
        cout << "Kode penerbangan tidak ditemukan.\n" << endl;
        delay(2);
        cls();
    }
}

// Fungsi untuk menampilkan semua jadwal penerbangan yang ada
void tampilkanJadwal() {
    if (head == nullptr) {
        cls();
        cout << "Data jadwal kosong, silahkan tambah jadwal terlebih dahulu.\n";
        delay(2);
        return;
    }

    jadwal *temp = head;
    cls();
    style2();
    cout << "Daftar Jadwal Penerbangan : \n";
    while (temp != nullptr) {
        cout << "Kode Penerbangan : " << temp->kodePenerbangan << endl;
        cout << "Tujuan           : " << temp->tujuan << endl;
        cout << "Status           : " << temp->status << endl;
        style();

        cout << "Tekan Enter untuk melanjutkan...";
        cin.ignore();
        cin.get();
        cls();
        temp = temp->next;
    }
}

// Kode utama untuk menjalankan program
int main() {
    string nim = "050";

    int pilihan;

    do {
        cls();
        style2();
        cout << "Sistem Jadwal Penerbangan\n";
        style2();
        cout << "1. Tambah Jadwal Penerbangan\n";
        cout << "2. Sisipkan Jadwal Penerbangan\n";
        cout << "3. Hapus Jadwal Penerbangan (paling awal)\n";
        cout << "4. Update Jadwal Penerbangan\n";
        cout << "5. Tampilkan Jadwal Penerbangan\n";
        cout << "6. Keluar\n";
        style2();
        cout << "Pilih (1-6) : ";
        cin >> pilihan;

        switch (pilihan)
        {
            case 1:
                tambahJadwal(nim);
                break;
            case 2:
                menyisipkanJadwal(nim);
                break;
            case 3:
                hapusJadwal();
                break;
            case 4:
                ubahStatus();
                break;
            case 5:
                tampilkanJadwal();
                break;
            case 6:
                cls();
                cout << "Terima kasih telah menggunakan program ini!\n";
                delay(2);
                cls();
                break;
            default:
                cls();
                cout << "Pilihan tidak valid. Silakan pilih lagi.\n";
                delay(2);
                cls();
                break;
        }
    } while (pilihan != 6);

    return 0;
}