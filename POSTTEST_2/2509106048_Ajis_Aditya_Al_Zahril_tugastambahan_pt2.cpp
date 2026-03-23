#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Struct Pelanggan
struct Pelanggan {
    int id;
    string nama;
};

void insertionSort(Pelanggan* arr, int n) {
    for (int i = 1; i < n; i++) {
        Pelanggan key = *(arr + i);
        int j = i - 1;
        
        while (j >= 0 && (arr + j)->id > key.id) {
            *(arr + j + 1) = *(arr + j);
            j = j - 1;
        }
        *(arr + j + 1) = key;
    }
}

bool searchBoyerMoore(string text, string pattern) {
    int n = text.length();
    int m = pattern.length();
    
    if (m == 0 || n < m) return false;

    int badChar[256];
    for (int i = 0; i < 256; i++) {
        badChar[i] = m;
    }
    for (int i = 0; i < m - 1; i++) {
        badChar[(int)pattern[i]] = m - 1 - i;
    }

    int s = 0;
    while (s <= (n - m)) {
        int j = m - 1;

        while (j >= 0 && pattern[j] == text[s + j]) {
            j--;
        }

        if (j < 0) {
            return true; 
        } else {
            int geser = badChar[(int)text[s + j]];
            if (geser < 1) geser = 1;
            s += geser;
        }
    }
    return false;
}

void tampilkanData(Pelanggan* arr, int n, string judul) {
    cout << "\n--- " << judul << " ---\n";
    cout << "==========================\n";
    cout << "| " << left << setw(6) << "ID" 
         << "| " << left << setw(15) << "Nama Pelanggan" << "|\n";
    cout << "==========================\n";
    for (int i = 0; i < n; i++) {
        cout << "| " << left << setw(6) << (arr + i)->id 
             << "| " << left << setw(15) << (arr + i)->nama << "|\n";
    }
    cout << "==========================\n";
}

int main() {
    int n = 7;
    Pelanggan daftarPelanggan[] = {
        {105, "Rania"},
        {102, "Bagas"},
        {107, "Salsa"},
        {101, "Hendra"},
        {104, "Nadia"},
        {106, "Gilang"},
        {103, "Putri"}
    };

    tampilkanData(daftarPelanggan, n, "Data Sebelum Diurut");

    insertionSort(daftarPelanggan, n);

    tampilkanData(daftarPelanggan, n, "Data Setelah Diurut");

    string pola = "an";
    cout << "\nHasil Pencarian Pola \"" << pola << "\n";
    
    bool ada = false;
    for (int i = 0; i < n; i++) {
        if (searchBoyerMoore((daftarPelanggan + i)->nama, pola)) {
            cout << "=> DITEMUKAN PADA: " << (daftarPelanggan + i)->nama 
                 << " (ID: " << (daftarPelanggan + i)->id << ")\n";
            ada = true;
        }
    }

    if (!ada) {
        cout << "Tidak ada nama yang cocok.\n";
    }
    cout << endl;

    return 0;
}