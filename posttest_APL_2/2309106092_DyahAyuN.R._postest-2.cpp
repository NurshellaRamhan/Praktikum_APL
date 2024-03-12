#include <iostream>
#include <string>
using namespace std;

// Deklarasi dan info login pengguna
string nama = "Dyah Ayu Nurshella";
unsigned long int nim = 2309106092;
int coba = 0;
int max_coba = 3;
int pilihan;

// Array untuk menyimpan data laundry
const int MAX_LAUNDRY = 100; // nilai maksimum laundry dalam array
string namaCust[MAX_LAUNDRY]; // array untuk menyimpan nama pelanggan
float hargaLaundry[MAX_LAUNDRY]; //array untuk menyimpan harga
bool statusLaundry[MAX_LAUNDRY]; //array untuk menyimpan status
bool statusPembayaran[MAX_LAUNDRY]; //array untuk menyimpan transaksi
unsigned long int nomorHpCust[MAX_LAUNDRY]; // Array untuk menyimpan nomor telepon pelanggan
int banyakLaundry = 0; // Jumlah laundry yang saat ini tersimpan dalam array

// variabel untuk menyimpan inputanlogin 
string input_nama;
unsigned long int input_nim;

int main()
{
    // MENU LOGIN
    while (coba < max_coba)
    {
        cout << "\n=============================================================" << endl;
        cout << "\n| SELAMAT DATANG DI PROGRAM DAFTAR TRANSAKSI LAUNDRY SHELLA |" << endl;
        cout << "\n=============================================================" << endl;
        cout << "\nMasukkan Nama Anda: ";
        cin.ignore();
        getline(cin, input_nama);
        cout << "Masukkan Password/ NIM: ";
        cin >> input_nim;

        cout << "Nama yang dimasukkan: " << input_nama << endl;
        cout << "NIM yang dimasukkan: " << input_nim << endl;

        if (input_nama == nama && input_nim == nim)
        {
            cout << "Login Berhasil!" << endl;
            break;
        }
        else
        {
            cout << "Nama atau NIM kamu salah. Silahkan coba lagi" << endl;
            coba++;
            if (coba == max_coba)
            {
                cout << "Anda sudah gagal login sebanyak 3 kali. Program berhenti" << endl;
                return 0;
            }
        }
    }
    // MENU UTAMA
    do
    {
        cout << "\n=========Menu Utama========" << endl;
        cout << "|    1. Tambah Laundry     |" << endl;
        cout << "|    2. Tampilkan Laundry  |" << endl;
        cout << "|    3. Update Laundry     |" << endl;
        cout << "|    4. Hapus Laundry      |" << endl;
        cout << "|    5. Keluar             |" << endl;
        cout << "============================" << endl;
        cout << "\nPilih Menu: ";
        cin >> pilihan;

    // MENU PROSES

        if (pilihan == 1)
        {
            // Tambah Laundry
            if (banyakLaundry < MAX_LAUNDRY)
            {
                cout << "Masukkan nama Customer Lundry: ";
                cin.ignore();
                getline(cin,namaCust[banyakLaundry]);
                cout << "Masukkan harga laundry: ";
                cin >> hargaLaundry[banyakLaundry];
                cout << "Masukkan nomor telepon pelanggan: ";
                cin >> nomorHpCust[banyakLaundry];
                statusLaundry[banyakLaundry] = false;        // status pengerjaan awal
                statusPembayaran[banyakLaundry] = false;    // status pembayaran awal
                banyakLaundry++;
                cout << "Daftar laundry berhasil ditambahkan.\n";
            }
            else
            {
                cout << "Daftar laundry sudah penuh.\n";
            }
        }
        else if (pilihan == 2)
        {
            // Tampilkan Laundry
            if (banyakLaundry > 0)
            {
                cout << "Daftar Laundry:\n";
                for (int i = 0; i < banyakLaundry; ++i)
                {
                    cout << i + 1 << ". " << namaCust[i] << " - Rp" << hargaLaundry[i]
                         << " - No Telepon: " << nomorHpCust[i] << endl
                         << " - Status pengerjaan: " << (statusLaundry[i] ? "Selesai" : "Belum Selesai") << endl
                         << " - Status pembayaran: " << (statusPembayaran[i] ? "Lunas" : "Belum Lunas") << endl;
                }
            }
            else
            {
                cout << "Daftar laundry kosong.\n";
            }
        }
        else if (pilihan == 3)
        {
            // Update Laundry
            int index;
            cout << "Masukkan indeks laundry yang ingin diupdate: ";
            cin >> index;
            if (index > 0 && index <= banyakLaundry)
            {
                cout << "Perbarui nama customer lama/ baru(jika ingin nama lama diubah): ";
                cin.ignore();
                getline(cin,namaCust[index - 1]);
                cout << "Perbarui harga laundry lama/baru: ";
                cin >> hargaLaundry[index - 1];
                cout << "Perbarui nomor telepon pelanggan: ";
                cin >> nomorHpCust[index - 1];
                cout << "Perbarui status pengerjaan laundry ('1' untuk Selesai, '0' untuk Belum Selesai'): ";
                cin >> statusLaundry[index - 1];
                cout << "Perbarui status pembayaran ('1' untuk Lunas, '0' untuk Belum Lunas'): ";
                cin >> statusPembayaran[index - 1];
                cout << "Laundry berhasil diupdate.\n";
            }
            else
            {
                cout << "Indeks tidak valid.\n";
            }
        }
        else if (pilihan == 4)
        {
            // Hapus Laundry
            int index;
            cout << "Masukkan indeks laundry yang ingin dihapus: ";
            cin >> index;
            if (index > 0 && index <= banyakLaundry)
            {
                for (int i = index - 1; i < banyakLaundry - 1; ++i)
                {
                    namaCust[i] = namaCust[i + 1];
                    hargaLaundry[i] = hargaLaundry[i + 1];
                    nomorHpCust[i] = nomorHpCust[i + 1];
                    statusLaundry[i] = statusLaundry[i + 1];
                    statusPembayaran[i] = statusPembayaran[i + 1];
                }
                banyakLaundry--;
                cout << "Laundry berhasil dihapus.\n";
            }
            else
            {
                cout << "Indeks tidak valid.\n";
            }
        }
        else if (pilihan == 5)
        {
            cout << "Program berhenti. Anda telah menggunakan program Arigatou~";
        }
        else
        {
            cout << "Pilihan tidak valid.\n";
        }
    } while (pilihan != 5);

    return 0;
}
