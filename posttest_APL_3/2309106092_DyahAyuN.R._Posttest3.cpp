#include <iostream>
#include <string>
#include <conio.h>
using namespace std;

const string adminUsername = "Dyah Ayu Nurshella";
const string adminPassword = "2309106092";

const int MAX_LAUNDRY = 5;
string namaCust[MAX_LAUNDRY];
string hargaLaundry[MAX_LAUNDRY];
bool statusLaundry[MAX_LAUNDRY];
bool statusPembayaran[MAX_LAUNDRY];
unsigned long int nomorHpCust[MAX_LAUNDRY];
int banyakLaundry = 0;

// fungsi rekursif untuk mencari indeks dalam array
bool isIndexValid(int index) {
    return (index >= 0 && index < MAX_LAUNDRY);
}

int findIndexByPhoneNumber(unsigned long int phoneNumber, int index) {
    if (index == banyakLaundry)
        return -1; // Jika tidak ditemukan
    else if (nomorHpCust[index] == phoneNumber)
        return index;
    else
        return findIndexByPhoneNumber(phoneNumber, index + 1); //rekursif
}

int findIndexByName(const string& name, int index) {
    if (index == banyakLaundry)
        return -1; // Jika tidak ditemukan
    else if (namaCust[index] == name)
        return index;
    else
        return findIndexByName(name, index + 1); //rekursif
}

void tambahLaundry() {
    if (banyakLaundry < MAX_LAUNDRY) {
        cout << "Masukkan nama Customer Laundry: ";
        cin.ignore();
        getline(cin, namaCust[banyakLaundry]);
        cout << "Masukkan harga laundry: ";
        cin >> hargaLaundry[banyakLaundry];
        cout << "Masukkan nomor telepon pelanggan: ";
        cin >> nomorHpCust[banyakLaundry];
        statusLaundry[banyakLaundry] = false;        // status pengerjaan awal
        statusPembayaran[banyakLaundry] = false;    // status pembayaran awal
        banyakLaundry++;
        cout << "Laundry berhasil ditambahkan.\n";
    } else {
        cout << "Daftar laundry sudah penuh.\n";
    }
}

void lihatStatus() {
    if (banyakLaundry > 0) {
        cout << "Daftar Laundry:\n";
        for (int i = 0; i < banyakLaundry; ++i) {
            cout << i + 1 << ". " << namaCust[i] << " - Rp" << hargaLaundry[i]
                 << " - No Telepon: " << nomorHpCust[i] << endl
                 << " - Status pengerjaan: " << (statusLaundry[i] ? "Selesai" : "Belum Selesai") << endl
                 << " - Status pembayaran: " << (statusPembayaran[i] ? "Lunas" : "Belum Lunas") << endl;
        }
    } else {
        cout << "Daftar laundry kosong.\n";
    }
}

void updateLaundry() {
    int index;
    cout << "Masukkan nama pelanggan yang ingin di update: ";
    string name;
    cin >> name;
    
    index = findIndexByName(name, 0);

    if (index != -1) {
        cout << "Perbarui nama Customer Laundry: ";
        cin.ignore();
        getline(cin, namaCust[index]);
        cout << "Perbarui harga laundry: ";
        cin >> hargaLaundry[index];
        cout << "Perbarui nomor telepon pelanggan: ";
        cin >> nomorHpCust[index];
        cout << "Perbarui status pengerjaan laundry ('1' untuk Selesai, '0' untuk Belum Selesai'): ";
        cin >> statusLaundry[index];
        cout << "Perbarui status pembayaran ('1' untuk Lunas, '0' untuk Belum Lunas'): ";
        cin >> statusPembayaran[index];
        cout << "Laundry berhasil diupdate.\n";
    } else {
        cout << "Nomor telepon tidak ditemukan.\n";
    }
}

void hapusLaundry() {
    cout << "Masukkan nama Customer Laundry yang akan dihapus: ";
    cin.ignore();
    string name;
    getline(cin, name);

    int index = findIndexByName(name, 0);

    if (index != -1) {
        for (int i = index; i < banyakLaundry - 1; ++i) {
            namaCust[i] = namaCust[i + 1];
            hargaLaundry[i] = hargaLaundry[i + 1];
            statusLaundry[i] = statusLaundry[i + 1];
            statusPembayaran[i] = statusPembayaran[i + 1];
            nomorHpCust[i] = nomorHpCust[i + 1];
        }
        banyakLaundry--;
        cout << "Laundry berhasil dihapus.\n";
    } else {
        cout << "Nama pelanggan tidak ditemukan.\n";
    }
}

void userMenu() {
    int pilihan;
    do {
        cout << "\n=========Menu User========" << endl;
        cout << "|    1. Tambah Laundry    |" << endl;
        cout << "|    2. Lihat Status      |" << endl;
        cout << "|    3. Keluar            |" << endl;
        cout << "===========================" << endl;
        cout << "\nPilih Menu: ";
        cin >> pilihan;

        switch(pilihan) {
            case 1:
                tambahLaundry();
                break;
            case 2:
                lihatStatus();
                break;
            case 3:
                cout << "Program Berhenti, Terima Kasih" << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while(pilihan != 3);
}
            
void adminMenu() {
    int pilihan;
    char option;
        do {
            cout << "\n==========================Menu Admin=========================" << endl;
            cout << "|               1. Tambah Laundry                              |" << endl;
            cout << "|               2. Lihat Daftar                                |" << endl;
            cout << "|               3. Cari Pelanggan based on nama or no telpon   |" << endl;
            cout << "|               4. Update Laundry                              |" << endl;
            cout << "|               5. Hapus Laundry                               |" << endl;
            cout << "|               6. Keluar                                      |" << endl;
            cout << "===============================================================" << endl;
            cout << "\nPilih Menu: ";
            cin >> pilihan;

            switch (pilihan) {
                case 1:
                    tambahLaundry();
                    break;
                case 2:
                    lihatStatus();
                    break;
                case 3:
                    cout << "\nApakah Anda ingin mencari pelangan berdasarkan no. telpon (T) atau nama customer (C)? ";
                    cin >> option;
                    if (option == 'T' || option == 't') {
                        unsigned long int phoneNumber;
                        cout << "Masukkan Nomor Telpon yang ingin dicari: ";
                        cin >> phoneNumber;
                        int index = findIndexByPhoneNumber(phoneNumber, 0);
                        if (index != -1){
                            cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                           cout << "Detail pelanggan:\n";
                           cout << "Nama: " << namaCust[index] << endl;
                           cout << "Harga Laundry: " << hargaLaundry[index] << endl;
                           cout << "Status pengerjaan: " << (statusLaundry[index] ? "Selesai" : "Belum Selesai") << endl;
                           cout << "Status pembayaran: " << (statusPembayaran[index] ? "Lunas" : "Belum Lunas") << endl;
                        } else {
                            cout << "Nomor pelanggan tidak ditemukan." << endl;
                        }
                       break;
                    } else if (option == 'C' || option == 'c') {
                        string name;
                        cout << "Masukkan Nama Customer yang ingin dicari: ";
                        cin.ignore();
                        getline(cin, name);
                        int index = findIndexByName(name,0);
                        if (index != -1) {
                            cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                            cout << "Detail pelanggan:\n";
                            cout << "Nama: " << namaCust[index] << endl;
                            cout << "Harga Laundry: " << hargaLaundry[index] << endl;
                            cout << "Status pengerjaan: " << (statusLaundry[index] ? "Selesai" : "Belum Selesai") << endl;
                            cout << "Status pembayaran: " << (statusPembayaran[index] ? "Lunas" : "Belum Lunas") << endl;
                        } else {
                            cout << "Nama pelanggan tidak ditemukan." << endl;
                        }
                        break;
                    } else {
                        cout << "Input Option anda tidak valid. Program berhenti." << endl;
                        break;
                case 4:
                    updateLaundry();
                    break;
                case 5:
                    hapusLaundry();
                    break;  
                case 6:
                    cout << "Terima kasih. Sampai jumpa lagi!" << endl;
                    exit(0);
                default:
                    cout << "Pilihan tidak valid." << endl;
            }
        } 
    }
    while (pilihan != 6);
}

void login() {
    string username;
    string password;
    int coba = 0 ;
    int max_coba = 3;

    while (coba < max_coba)
    {
        cout << "\nMasukkan username: "; 
        getline(cin, username);

        cout << "Masukkan password: "; 
        getline(cin, password);


        cout << "Nama yang dimasukkan: " << username << endl;
        cout << "NIM yang dimasukkan: " << password << endl;

        if (username == adminUsername && password == adminPassword) {
            cout << "Selamat kamu berhasil login!" << endl;
            cout << "Please click Enter/ anything untuk melanjutkan\n ";
            getch();
            adminMenu();
            return;
        } else {
            cout << "Username atau Password anda salah. Silahkan coba lagi" << endl;
            coba++;
            if (coba == max_coba){
                cout << "Anda sudah gagal login sebanyak 3 kali. Program berhenti" << endl;
                return;
            }
        }
    }
}

int main() {
    char role;
    cout << "\n=====================================================" << endl;
    cout << "   SELAMAT DATANG DI PROGRAM DAFTAR TRANSAKSI LAUNDRY" << endl;
    cout << "\n=====================================================" << endl;
    
    cout << "\nApakah Anda pengguna (p) atau admin (a)? ";
    cin >> role;
    cin.ignore();


    if (role == 'p' || role == 'P') {
        cout << "Anda berhasil login sebagai user!" << endl;
        userMenu();
    } else if (role == 'a' || role == 'A') {
        login();
    } else {
        cout << "Role tidak valid. Program berhenti." << endl;
    }
    return 0;
}
