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
    bool statusPembayaran;
};

struct Laundry {
    string namaCust;
    string hargaLaundry;
    string jenisLaundry;
    bool statusPengerjaan;
    bool statusPembayaran;
    unsigned long int nomorTelepon;  
    vector<DetailLaundry> detailLaundry;
};

const int MAX_LAUNDRY = 5;
vector<Laundry> daftarLaundry(MAX_LAUNDRY);
int banyakLaundry = 0;

bool isIndexValid(int index) {
    return (index >= 0 && index < MAX_LAUNDRY);
}

int findIndexByPhoneNumber(unsigned long int phoneNumber, int* index) {
    if (*index == banyakLaundry)
        return -1;
    else if (daftarLaundry[*index].nomorTelepon == phoneNumber)
        return *index;
    else
        return findIndexByPhoneNumber(phoneNumber, index + 1);
}

int findIndexByName(const string& name, int* index) {
    if (*index == banyakLaundry)
        return -1;
    else if (daftarLaundry[*index].namaCust == name)
        return *index;
    else
        return findIndexByName(name, index + 1);
}

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

void tambahLaundry(std::vector<Laundry>& daftarLaundry, int* banyakLaundry) {
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

        int jumlahPakaian;
        cout << "Masukkan jumlah jenis pakaian: ";
        cin >> jumlahPakaian;
        for (int i = 0; i < jumlahPakaian; ++i) {
            tambahDetailLaundry(&newLaundry);
        }

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

void updateLaundry(const string& nama, std::vector<Laundry>& daftarLaundry, int* index) {
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

void bubblesortdesc(vector<Laundry>& arr) {
    for (int i = 0; i < banyakLaundry - 1; ++i) {
        for (int j = 0; j < banyakLaundry - i - 1; ++j) {
            if (daftarLaundry[j].namaCust < daftarLaundry[j + 1].namaCust) {
                swap(daftarLaundry[j], daftarLaundry[j + 1]);
            }
        }
    }
}

void merge(vector<Laundry>& arr, int l, int m, int r) {
    int n1 = m - l + 1;
    int n2 = r - m;

    vector<Laundry> L(n1), R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2) {
        if (L[i].hargaLaundry <= R[j].hargaLaundry) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSortAscending(vector<Laundry>& arr, int l, int r) {
    if (l >= r)
        return;
    int m = l + (r - l) / 2;
    mergeSortAscending(arr, l, m);
    mergeSortAscending(arr, m + 1, r);
    merge(arr, l, m, r);
}

void mergeSortAscendingCaller() {
    mergeSortAscending(daftarLaundry, 0, banyakLaundry - 1);
}

int partition(vector<Laundry>& arr, int low, int high) {
    Laundry pivot = arr[high];
    int i = (low - 1);

    for (int j = low; j <= high - 1; j++) {
        if (arr[j].nomorTelepon < pivot.nomorTelepon) {
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]);
    return (i + 1);
}

void quickSortAscending(vector<Laundry>& arr, int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSortAscending(arr, low, pi - 1);
        quickSortAscending(arr, pi + 1, high);
    }
}

void quickSortAscendingCaller() {
    quickSortAscending(daftarLaundry, 0, banyakLaundry - 1);
}

void menuPengurutan() {
    cout << "\nMenu Pengurutan:\n";
    cout << "1. Bubble Sort (Nama Pelanggan Descending)\n";
    cout << "2. Merge Sort (Harga Laundry Ascending)\n";
    cout << "3. Quick Sort (Nomor Telepon Ascending)\n";
    cout << "Pilih Metode Pengurutan: ";
    int metode;
    cin >> metode;
    switch (metode) {
        case 1:
            bubblesortdesc(daftarLaundry);
            cout << "Pengurutan menggunakan Bubble Sort selesai.\n";
            lihatStatus();
            break;
        case 2:
            mergeSortAscendingCaller();
            cout << "Pengurutan menggunakan Merge Sort selesai.\n";
            lihatStatus();
            break;
        case 3:
            quickSortAscendingCaller();
            cout << "Pengurutan menggunakan Quick Sort selesai.\n";
            lihatStatus();
            break;
        default:
            cout << "Pilihan tidak valid.\n";
            break;
    }
}

int sequentialSearchAscending(const vector<Laundry>& arr, const string& name) {
    for (int i = 0; i < banyakLaundry; ++i) {
        if (arr[i].namaCust == name) {
            return i;
        }
        // Karena data terurut secara ascending, jika nama pelanggan
        // pada indeks ke-i sudah melebihi nama yang dicari, berhenti pencarian
        if (arr[i].namaCust > name) {
            break;
        }
    }
    return -1; // Jika tidak ditemukan
}

int sequentialSearchDescending(const vector<Laundry>& arr, const string& name) {
    for (int i = 0; i < banyakLaundry; ++i) {
        if (arr[i].namaCust == name) {
            return i;
        }
        // Karena data terurut secara descending, jika nama pelanggan
        // pada indeks ke-i sudah kurang dari nama yang dicari, berhenti pencarian
        if (arr[i].namaCust < name) {
            break;
        }
    }
    return -1; // Jika tidak ditemukan
}

int binarySearchAscending(const vector<Laundry>& arr, const string& name) {
    int left = 0;
    int right = banyakLaundry - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].namaCust == name) {
            return mid;
        } else if (arr[mid].namaCust < name) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1; // Jika tidak ditemukan
}

int binarySearchDescending(const vector<Laundry>& arr, const string& name) {
    int left = 0;
    int right = banyakLaundry - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid].namaCust == name) {
            return mid;
        } else if (arr[mid].namaCust < name) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
    return -1; // Jika tidak ditemukan
} 

void menuPencarian() {
    cout << "\n=============================Menu Pencarian===============================" << endl;
    cout << "| 1. Sequential Search (Ascending)                                        |" << endl;
    cout << "| 2. Sequential Search (Descending)                                       |" << endl;
    cout << "| 3. Binary Search (Ascending)                                             |" << endl;
    cout << "| 4. Binary Search (Descending)                                            |" << endl;
    cout << "============================================================================" << endl;
    cout << "\nPilih Metode Pencarian: ";
    int metodePencarian;
    cin >> metodePencarian;
    switch (metodePencarian) {
        case 1: {
            string nama;
            cout << "Masukkan nama pelanggan yang ingin dicari: ";
            cin.ignore();
            getline(cin, nama);
            int index = sequentialSearchAscending(daftarLaundry, nama);
            if (index != -1) {
                cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                // Tampilkan detail pelanggan
            } else {
                cout << "Pelanggan dengan nama tersebut tidak ditemukan." << endl;
            }
            break;
        }
        case 2: {
            string nama;
            cout << "Masukkan nama pelanggan yang ingin dicari: ";
            cin.ignore();
            getline(cin, nama);
            int index = sequentialSearchDescending(daftarLaundry, nama);
            if (index != -1) {
                cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                // Tampilkan detail pelanggan
            } else {
                cout << "Pelanggan dengan nama tersebut tidak ditemukan." << endl;
            }
            break;
        }
        case 3: {
            string nama;
            cout << "Masukkan nama pelanggan yang ingin dicari: ";
            cin.ignore();
            getline(cin, nama);
            // Sebelum melakukan binary search, pastikan data sudah terurut secara ascending
            mergeSortAscendingCaller();
            int index = binarySearchAscending(daftarLaundry, nama);
            if (index != -1) {
                cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                // Tampilkan detail pelanggan
            } else {
                cout << "Pelanggan dengan nama tersebut tidak ditemukan." << endl;
            }
            break;
        }
        case 4: {
            string nama;
            cout << "Masukkan nama pelanggan yang ingin dicari: ";
            cin.ignore();
            getline(cin, nama);
            // Sebelum melakukan binary search, pastikan data sudah terurut secara descending
            bubblesortdesc(daftarLaundry);
            int index = binarySearchDescending(daftarLaundry, nama);
            if (index != -1) {
                cout << "Pelanggan ditemukan pada indeks: " << index << endl;
                // Tampilkan detail pelanggan
            } else {
                cout << "Pelanggan dengan nama tersebut tidak ditemukan." << endl;
            }
            break;
        }
        default:
            cout << "Pilihan tidak valid." << endl;
            break;
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
                tambahLaundry(daftarLaundry, &banyakLaundry);
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
        cout << "|             1. Tambah Laundry                              |" << endl;
        cout << "|             2. Lihat Daftar                                |" << endl;
        cout << "|             3. Search Pelanggan based on nama              |" << endl;
        cout << "|             4. Update Laundry                              |" << endl;
        cout << "|             5. Hapus Laundry                               |" << endl;
        cout << "|             6. Urutkan/ sortir                             |" << endl;
        cout << "|             7. Keluar                                      |" << endl;
        cout << "===============================================================" << endl;
        cout << "\nPilih Menu: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1:
                tambahLaundry(daftarLaundry, &banyakLaundry);
                break;
            case 2:
                lihatStatus();
                break;
            case 3:
                menuPencarian();
                break;
            case 4:
                updateLaundry(nama, daftarLaundry, &index);
                break;
            case 5:
                hapusLaundry(&index);
                break;
            case 6:
                menuPengurutan();
                break;
            case 7:
                cout << "Program Berhenti, Terima Kasih" << endl;
                exit(0);

            default:
                cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 7);
}

bool isAdminValid(string username, string password) {
    return (username == adminUsername && password == adminPassword);
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

