#include <iostream>
#include <string>
#include <vector>
#include <conio.h>
using namespace std;

const string adminUsername = "Dyah Ayu Nurshella";
const string adminPassword = "2309106092";

struct DetailLaundry {
    string jenisPakaian;
    int beratPakaian;
    int hargaSatuan;
    bool statusPengerjaan;
    bool statusPembayaran; //struct untuk variable DeatilLaundry
};

struct Laundry {
    string namaCust;
    string hargaLaundry;
    string jenisLaundry;
    bool statusPengerjaan;
    bool statusPembayaran;
    unsigned long int nomorTelepon;
    vector<DetailLaundry> detailLaundry; // Nested struct untuk detail pakaian
};

const int MAX_LAUNDRY = 5;
Laundry daftarLaundry[MAX_LAUNDRY];
int banyakLaundry = 0;

// fungsi rekursif untuk mencari indeks dalam array
bool isIndexValid(int index) {
    return (index >= 0 && index < MAX_LAUNDRY);
}

// Menggunakan fungsi parameter dengan address-of
int findIndexByPhoneNumber(unsigned long int phoneNumber, int* index) {
    if (*index == banyakLaundry)
        return -1; // Jika tidak ditemukan
    else if (daftarLaundry[*index].nomorTelepon == phoneNumber)
        return *index;
    else
        return findIndexByPhoneNumber(phoneNumber, index + 1); //rekursif
}

// Menggunakan fungsi parameter dengan address-of
int findIndexByName(const string& name, int* index) {
    if (*index == banyakLaundry)
        return -1; // Jika tidak ditemukan
    else if (daftarLaundry[*index].namaCust == name)
        return *index;
    else
        return findIndexByName(name, index + 1); //rekursif
}

// Fungsi untuk menambahkan laundry menggunakan pointer
// Fungsi untuk menambahkan detail laundry menggunakan pointer
void tambahDetailLaundry(Laundry* laundry) {
    if (laundry->detailLaundry.size() < MAX_LAUNDRY) {
        DetailLaundry detail;

        cout << "Jenis pakaian (formal)/(nonformal): ";
        cin.ignore();
        getline(cin, detail.jenisPakaian);
        cout << "Berat pakaian (kg): ";
        cin >> detail.beratPakaian;
        cout << "Harga satuan pakaian: ";
        cin >> detail.hargaSatuan;

        laundry->detailLaundry.push_back(detail);
        cout << "Detail laundry berhasil ditambahkan.\n";
    } else {
        cout << "Detail laundry sudah penuh.\n";
    }
}

// Fungsi untuk menambahkan laundry menggunakan pointer
void tambahLaundry(Laundry* daftarLaundry, int* banyakLaundry) {
    if (*banyakLaundry < MAX_LAUNDRY) {
        Laundry newLaundry;

        cout << "Masukkan nama Customer Laundry: ";
        cin.ignore();
        getline(cin, newLaundry.namaCust);
        cout << "Masukkan harga laundry: ";
        cin >> newLaundry.hargaLaundry;
        cout << "Masukkan nomor telepon pelanggan: ";
        cin >> newLaundry.nomorTelepon;
        newLaundry.statusPengerjaan = false;
        newLaundry.statusPembayaran = false;

        // Memanggil fungsi untuk tambah detail laundry menggunakan pointer
        int jumlahPakaian;
        cout << "Masukkan jumlah jenis pakaian: ";
        cin >> jumlahPakaian;
        for (int i = 0; i < jumlahPakaian; ++i) {
            tambahDetailLaundry(&newLaundry);
        }

        // Menyimpan data laundry ke dalam array menggunakan pointer
        daftarLaundry[*banyakLaundry] = newLaundry;
        (*banyakLaundry)++;
        cout << "Laundry berhasil ditambahkan.\n";
    } else {
        cout << "Daftar laundry sudah penuh.\n";
    }
}


void lihatStatus() {
    if (banyakLaundry > 0) {
        cout << "Daftar Laundry:\n";
        for (int i = 0; i < banyakLaundry; ++i) {
            cout << i + 1 << ". " << daftarLaundry[i].namaCust << " - Rp" << daftarLaundry[i].hargaLaundry
                 << " - No Telepon: " << daftarLaundry[i].nomorTelepon << endl
                 << " - Status pengerjaan: " << (daftarLaundry[i].statusPengerjaan ? "Selesai" : "Belum Selesai") << endl
                 << " - Status pembayaran: " << (daftarLaundry[i].statusPembayaran ? "Lunas" : "Belum Lunas") << endl;
            cout << "   Detail Pakaian:\n";
            for (const auto& detail : daftarLaundry[i].detailLaundry) {
                cout << "     - Jenis: " << detail.jenisPakaian << ", Berat: " << detail.beratPakaian << " kg, Harga Satuan: " << detail.hargaSatuan << endl;
            }
        }
    } else {
        cout << "Daftar laundry kosong.\n";
    }
}

// Fungsi untuk memperbarui laundry menggunakan pointer
void updateLaundry(const string& nama, int* index) {
    string updateNama;
    cout << "Masukkan nama pelanggan yang ingin diupdate: ";
    cin.ignore();
    getline(cin, updateNama);
    
    *index = findIndexByName(nama, 0);
    if (*index != -1) {
        cout << "Perbarui detail laundry untuk " << nama << ":" << endl;
        
        cout << "Masukkan jenis laundry (formal)/(nonformal): ";
        string jenis;
        cin >> jenis;
        daftarLaundry[*index].jenisLaundry = jenis;
        
        cout << "Masukkan harga laundry: ";
        string harga; 
        cin >> harga;
        daftarLaundry[*index].hargaLaundry = harga;
        
        cout << "Status pengerjaan (1 untuk Selesai, 0 untuk Belum Selesai): ";
        bool statusPengerjaan; 
        cin >> statusPengerjaan;
        daftarLaundry[*index].statusPengerjaan = statusPengerjaan;
        
        cout << "Status pembayaran (1 untuk Lunas, 0 untuk Belum Lunas): ";
        bool statusPembayaran; 
        cin >> statusPembayaran;
        daftarLaundry[*index].statusPembayaran = statusPembayaran;

        cout << "Detail laundry berhasil diperbarui." << endl;
    } else {
        cout << "Pelanggan dengan nama tersebut tidak ditemukan." << endl;
    }
}

// Fungsi untuk menghapus laundry menggunakan pointer
void hapusLaundry(int* index) {
    cout << "Masukkan nama Customer Laundry yang akan dihapus: ";
    cin.ignore();
    string name;
    getline(cin, name);

    *index = findIndexByName(name, 0);

    if (*index != -1) {
        for (int i = *index; i < banyakLaundry - 1; ++i) {
            daftarLaundry[i] = daftarLaundry[i+1];
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
                tambahLaundry(daftarLaundry, &banyakLaundry);// pointer address of operator
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
    string nama; 
    unsigned long int phoneNumber; 
    int index;
    
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
                tambahLaundry(daftarLaundry, &banyakLaundry); // pointer address-of operator
                break;
            case 2:
                lihatStatus();
                break;
            case 3:
                cout << "\nApakah Anda ingin mencari pelangan berdasarkan no. telpon (T) atau nama customer (C)? ";
                cin >> option;
                if (option == 'T' || option == 't') {
                    cout << "Masukkan Nomor Telpon yang ingin dicari: ";
                    cin >> phoneNumber;
                    int index = findIndexByPhoneNumber(phoneNumber, 0);
                    if (index != -1){
                        cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                        cout << "Detail pelanggan:\n";
                        cout << "Nama: " << daftarLaundry[index].namaCust << endl;
                        cout << "Harga Laundry: " << daftarLaundry[index].hargaLaundry << endl;
                        cout << "Status pengerjaan: " << (daftarLaundry[index].statusPengerjaan ? "Selesai" : "Belum Selesai") << endl;
                        cout << "Status pembayaran: " << (daftarLaundry[index].statusPembayaran ? "Lunas" : "Belum Lunas") << endl;
                    } else {
                        cout << "Nomor pelanggan tidak ditemukan." << endl;
                    }
                    break;
                } else if (option == 'C' || option == 'c') {
                    cout << "Masukkan Nama Customer yang ingin dicari: ";
                    cin.ignore();
                    getline(cin, nama);
                    int index = findIndexByName(nama,0);
                    if (index != -1) {
                        cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                        cout << "Detail pelanggan:\n";
                        cout << "Nama: " << daftarLaundry[index].namaCust << endl;
                        cout << "Harga Laundry: " << daftarLaundry[index].hargaLaundry << endl;
                        cout << "Status pengerjaan: " << (daftarLaundry[index].statusPengerjaan ? "Selesai" : "Belum Selesai") << endl;
                        cout << "Status pembayaran: " << (daftarLaundry[index].statusPembayaran ? "Lunas" : "Belum Lunas") << endl;
                    } else {
                        cout << "Nama pelanggan tidak ditemukan." << endl;
                    }
                    break;
                } else {
                    cout << "Input Option anda tidak valid. Program berhenti." << endl;
                    break;
                }
            case 4:
                updateLaundry(nama, &index); // Menggunakan parameter dengan address-of operator
                break;
            case 5:
                hapusLaundry(&index); // Menggunakan parameter dengan address-of operator
                break;  
            case 6:
                cout << "Terima kasih. Sampai jumpa lagi!" << endl;
                exit(0);
            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 6);
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

    switch(role) {
        case 'p' :
        case 'P' :
            cout  << "Anda berhasil login sebagai user!" << endl;
            userMenu();
            break;
        case 'a' :
        case 'A' :
            login();
            break;
        default:
            cout << "Role tidak valid. Program berhenti." << endl;
    }
    return 0;
}
