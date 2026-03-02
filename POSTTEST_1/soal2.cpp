#include <iostream>
#include <string>

using namespace std;

struct mahasiswa {
    string nama;
    string nim;
    float ipk;
};

int main() {
    mahasiswa mhs[5];

    cout << "= Program Input Data Mahasiswa =" << endl;

    for (int i = 0; i < 5; i++) {
        cout << "Data Mahasiswa ke-" << i + 1 << endl;
        cout << "Nama : ";
        getline(cin >> ws, mhs[i].nama); 
        cout << "NIM  : ";
        cin >> mhs[i].nim;
        cout << "IPK  : ";
        cin >> mhs[i].ipk;
        cout << "================================" << endl;
    }

    int indeks_max = 0; 
    float ipk_tertinggi = mhs[0].ipk;

    for (int i = 1; i < 5; i++) {
        if (mhs[i].ipk > ipk_tertinggi) {
            ipk_tertinggi = mhs[i].ipk;
            indeks_max = i;
        }
    }

    cout << "\n= Mahasiswa dengan IPK Tertinggi =" << endl;
    cout << "Nama : " << mhs[indeks_max].nama << endl;
    cout << "NIM  : " << mhs[indeks_max].nim << endl;
    cout << "IPK  : " << mhs[indeks_max].ipk << endl;

    return 0;
}