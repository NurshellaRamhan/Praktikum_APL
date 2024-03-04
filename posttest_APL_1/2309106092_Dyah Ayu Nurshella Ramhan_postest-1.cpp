#include <iostream>
using namespace std;

// menu login
int main() {
    string Nama;
    unsigned long int Nim;
    int menu;
    const int batas_max = 3;
    int coba = 0;

    while (coba < batas_max) {
        cout << "Masukkan Nama Anda: ";
        cin >> Nama;
        cout << "Masukkan NIM Anda: ";
        cin >> Nim;

        if (Nama == "Shella" && Nim == 2309106092) {
            break;
        } else {
            cout << "Nama atau NIM kamu salah. Silahkan coba lagi" << endl;
            coba++;
        }
    }

    if (coba == batas_max) {
        cout << "Anda sudah gagal login sebanyak 3 kali. Program berhenti" << endl;
        return 0;
    }

// menu konversi
    while (true) {
       cout << "\n=============== Menu Konversi Suhu: ===============" << endl;
        cout << "1. Konversi Celcius ke (Reamur, Farenheit, Kelvin)" << endl;
        cout << "2. Konversi Reamur ke (Celcius, Farenheit, Kelvin)"<< endl;
        cout << "3. Konversi Farenheit ke (Celcius, Reamur, Kelvin)" << endl;
        cout << "4. Konversi Kelvin ke (Celcius, Reamur, Farenheit)" << endl;
        cout << "5. Keluar" << endl;
        cout << "Pilih menu: ";
        cin >> menu; 

// menu proses konvversi
        float suhu;
        float hasil;

        // konversi celcius
        if (menu == 1) {
            cout << "Masukkan Suhu: ";
            cin >> suhu;
            // reamur
            hasil = 0.8 * suhu;
            cout << "Konversi Celcius ke Reamur: " << hasil << endl;
            // farenheit
            hasil = (suhu * 9.0/ 5.0) + 32;
            cout << "Konversi Celcius ke Farenheit: " << hasil << endl;
            // kelvin
            hasil = suhu + 273.0;
            cout << "Konversi Celcius ke Kelvin: " << hasil << endl; 

        // konversi reamur
         } else if (menu == 2) {
            cout << "Masukkan Suhu: ";
            cin >> suhu;
            // celcius
            hasil = 1.25 * suhu;
            cout << "Konversi Reamur ke Celcius: " << hasil << endl;
            // farenheit
            hasil = (suhu * 9.0/ 4.0) + 32;
            cout << "Konversi Reamur ke Farenheit: " << hasil << endl;
            // kelvin
            hasil = (suhu * 5.0/ 4.0) + 273.0;
            cout << "Konversi Reamur ke Kelvin: " << hasil << endl;

        // konversi farenheit
         } else if (menu == 3) {
            cout << "Masukkan suhu: ";
            cin >> suhu;
            // celcius
            hasil = ((suhu - 32) * 4.0/ 9.0);
            cout << "Konversi Farenheit ke Celcius: " << hasil << endl;
            // reamur
            hasil = ((suhu - 32) * 4.0/ 9.0);
            cout << "Konversi Farenheit ke Reamur: " << hasil << endl;
            // kelvin
            hasil = ((suhu - 32) * 5.0/ 9.0) + 273.0;
            cout << "Konversi Farenheit ke Kelvin: " << hasil << endl;

        // konversi kelvin
         } else if (menu == 4) {
            cout << "Masukkan suhu: ";
            cin >> suhu;
            // celcius
            hasil = (suhu - 273.0);
            cout << "Konversi Kelvin ke Celcius: " << hasil << endl;
            // reamur
            hasil = (suhu - 273.0) * 0.8;
            cout << "Konversi Kelvin ke Reamur: " << hasil << endl;
            // farenheit
            hasil = ((suhu - 273.0) * 9.0/ 5.0) + 32;
            cout << "Konversi Kelvin ke Farenheit: " << hasil << endl;
         } else if (menu == 5) {
             cout << "Anda telah menggunakan program. Arigatou~" << endl;
            break;
         } else {
            cout << "Menu tidak valid. Silakan pilih menu yang benar." << endl;
         }
    }
    return 0;
}