#include <iostream>
#include <string>
#include <cmath>
#include <iomanip>

using namespace std;

#define MAX 5

struct Kereta {
    int nomor;
    string nama;
    string asal;
    string tujuan;
    int harga;
};

struct Penumpang {
    string nama_penumpang;
    string rute_kereta;
};

Penumpang antrian[MAX];
int front = -1;
int rear = -1;

Penumpang riwayat[MAX];
int top = -1;

void push(Penumpang data) {
    if (top == MAX - 1) {
        cout << "Riwayat transaksi sudah penuh.\n";
        return;
    }
    top++;
    riwayat[top] = data;
    cout << "Transaksi atas nama " << data.nama_penumpang << " dicatat ke riwayat.\n";
}

void enqueue() {
    if (rear == MAX - 1) {
        cout << "Antrian pembelian tiket sudah penuh\n";
        return;
    }
    Penumpang p;
    cout << "\n--- Form Pembelian Tiket ---\n";
    cout << "Masukkan Nama Penumpang : "; 
    getline(cin, p.nama_penumpang);
    cout << "Masukkan Rute Kereta    : "; 
    getline(cin, p.rute_kereta);
    
    if (front == -1) front = 0;
    rear++;
    antrian[rear] = p;
    cout << "Penumpang " << p.nama_penumpang << " berhasil masuk ke antrian\n";
}

void dequeue() {
    if (front == -1 || front > rear) {
        cout << "Antrian kosong, tidak ada tiket yang bisa diproses.\n";
        return;
    }
    
    Penumpang diproses = antrian[front];
    cout << "\n>>> MEMPROSES TIKET <<<\n";
    cout << "Nama Penumpang : " << diproses.nama_penumpang << "\n";
    cout << "Rute Kereta    : " << diproses.rute_kereta << "\n";
    cout << "-----------------------\n";

    push(diproses);

    Penumpang* ptrAntrian = antrian;
    for (int i = front; i < rear; i++) {
        *(ptrAntrian + i) = *(ptrAntrian + i + 1);
    }
    rear--;
    
    if (rear == -1) {
        front = -1;
    }
}

void pop() {
    if (top == -1) {
        cout << "Riwayat transaksi kosong, tidak ada yang dibatalkan.\n";
        return;
    }
    cout << "Transaksi terakhir atas nama " << riwayat[top].nama_penumpang << " berhasil dibatalkan.\n";
    top--;
}

void peek() {
    cout << "\n=== DATA TERDEPAN (PEEK) ===\n";
    if (front != -1 && front <= rear) {
        cout << "[Antrian Selanjutnya] : " << antrian[front].nama_penumpang << " (Rute: " << antrian[front].rute_kereta << ")\n";
    } else {
        cout << "[Antrian Selanjutnya] : KOSONG\n";
    }
    
    if (top != -1) {
        cout << "[Riwayat Terakhir]    : " << riwayat[top].nama_penumpang << " (Rute: " << riwayat[top].rute_kereta << ")\n";
    } else {
        cout << "[Riwayat Terakhir]    : KOSONG\n";
    }
}

void tampilkanSemuaAntrian(Penumpang* q, int f, int r) {
    if (f == -1 || f > r) {
        cout << "Antrian tiket saat ini kosong.\n";
        return;
    }
    cout << "\n--- Daftar Antrian Tiket ---\n";
    for (int i = 0; i <= (r - f); i++) {
        cout << i + 1 << ". Nama: " << (q + i)->nama_penumpang << " | Rute: " << (q + i)->rute_kereta << "\n";
    }
}

void tampilkanSemuaRiwayat(Penumpang* s, int t) {
    if (t == -1) {
        cout << "Riwayat transaksi kosong.\n";
        return;
    }
    cout << "\n--- Riwayat Transaksi ---\n";
    for (int i = t; i >= 0; i--) {
        cout << (t - i + 1) << ". Nama: " << (s + i)->nama_penumpang << " | Rute: " << (s + i)->rute_kereta << "\n";
    }
}

void swapKereta(Kereta* a, Kereta* b) {
    Kereta temp = *a;
    *a = *b;
    *b = temp;
}

void tampilJadwal(Kereta* arr, int n) {
    if (n == 0) {
        cout << "Jadwal kereta masih kosong\n";
        return;
    }
    cout << "\n===============================================================================\n";
    cout << "| " << left << setw(10) << "Nomor"
         << "| " << left << setw(20) << "Nama Kereta"
         << "| " << left << setw(25) << "Rute (Asal -> Tujuan)"
         << "| " << left << setw(14) << "Harga Tiket" << "|\n";
    cout << "===============================================================================\n";
    for (int i = 0; i < n; i++) {
        string rute = (arr + i)->asal + " -> " + (arr + i)->tujuan;
        cout << "| " << left << setw(10) << (arr + i)->nomor 
             << "| " << left << setw(20) << (arr + i)->nama 
             << "| " << left << setw(25) << rute
             << "| Rp " << left << setw(11) << (arr + i)->harga << "|\n";
    }
    cout << "===============================================================================\n";
}

void tambahKereta(Kereta* arr, int &n) {
    cout << "\n--- Tambah Data Kereta ---\n";
    cout << "Nomor Kereta : "; cin >> (arr + n)->nomor;
    cin.ignore();
    cout << "Nama Kereta  : "; getline(cin, (arr + n)->nama);
    cout << "Kota Asal    : "; getline(cin, (arr + n)->asal);
    cout << "Kota Tujuan  : "; getline(cin, (arr + n)->tujuan);
    cout << "Harga Tiket  : "; cin >> (arr + n)->harga;
    n++;
    cout << "Data berhasil ditambahkan\n";
}

void linearSearchRute(Kereta* arr, int n, string asal, string tujuan) {
    cout << "\n--- Pencarian Rute: " << asal << " ke " << tujuan << " ---\n";
    bool ketemu = false;
    for (int i = 0; i < n; i++) {
        if ((arr + i)->asal == asal && (arr + i)->tujuan == tujuan) {
            cout << "=>  DITEMUKAN  <=\n";
            cout << "Kereta: " << (arr + i)->nama << "\n";
            cout << "Harga: Rp" << (arr + i)->harga << "\n";
            ketemu = true;
        }
    }
    if (!ketemu) cout << "Rute tidak ada\n";
}

void jumpSearchNomor(Kereta* arr, int n, int cari) {
    if (n == 0) return;
    for(int i = 0; i < n - 1; i++) {
        for(int j = 0; j < n - i - 1; j++) {
            if ((arr + j)->nomor > (arr + j + 1)->nomor) {
                swapKereta((arr + j), (arr + j + 1)); 
            }
        }
    }

    int step = (int)sqrt((double)n);
    int prev = 0;
    int lompat = step;
    if (lompat > n) lompat = n;

    while ((arr + lompat - 1)->nomor < cari) {
        prev = step;
        step += (int)sqrt((double)n);
        if (prev >= n) {
            cout << "Nomor kereta tidak ditemukan\n";
            return;
        }
        lompat = step;
        if (lompat > n) lompat = n;
    }

    while ((arr + prev)->nomor < cari) {
        prev++;
        if (prev == lompat) {
            cout << "Nomor kereta tidak ditemukan\n";
            return;
        }
    }

    if ((arr + prev)->nomor == cari) {
        cout << "=> DITEMUKAN: Kereta " << (arr + prev)->nama << " (Rute " << (arr + prev)->asal << "-" << (arr + prev)->tujuan << ")\n";
    } else {
        cout << "Nomor kereta tidak ditemukan.\n";
    }
}

void selectionSortHarga(Kereta* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if ((arr + j)->harga < (arr + min_idx)->harga) {
                min_idx = j;
            }
        }
        if (min_idx != i) {
            swapKereta((arr + min_idx), (arr + i)); 
        }
    }
    cout << "\nBerhasil diurutkan berdasarkan harga termurah\n";
}

void merge(Kereta* arr, int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    Kereta* L = new Kereta[n1];
    Kereta* R = new Kereta[n2];

    for (int i = 0; i < n1; i++) *(L + i) = *(arr + left + i);
    for (int j = 0; j < n2; j++) *(R + j) = *(arr + mid + 1 + j);

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if ((L + i)->nama <= (R + j)->nama) {
            *(arr + k) = *(L + i);
            i++;
        } else {
            *(arr + k) = *(R + j);
            j++;
        }
        k++;
    }
    while (i < n1) { *(arr + k) = *(L + i); i++; k++; }
    while (j < n2) { *(arr + k) = *(R + j); j++; k++; }

    delete[] L;
    delete[] R;
}

void mergeSortNama(Kereta* arr, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSortNama(arr, left, mid);
        mergeSortNama(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

int main() {
    int kapasitas = 100;
    Kereta* daftarKereta = new Kereta[kapasitas];
    int jumlahKereta = 0;
    int pilihan;

    do {
        cout << "\n=========================================";
        cout << "\n|      SISTEM MANAJEMEN KERETA API      |";
        cout << "\n=========================================\n";
        cout << "--- MANAJEMEN JADWAL KERETA ---\n";
        cout << "1. Tampil Jadwal Kereta\n";
        cout << "2. Tambah Data Kereta\n";
        cout << "3. Cari Rute (Linear)\n";
        cout << "4. Cari Nomor Kereta (Jump)\n";
        cout << "5. Urutkan by Harga Termurah (Selection)\n";
        cout << "6. Urutkan by Nama A-Z (Merge)\n";
        cout << "\n--- MANAJEMEN TIKET (QUEUE & STACK) ---\n";
        cout << "7. Beli Tiket (Masuk Antrian)\n";
        cout << "8. Proses Tiket (Dequeue & Masuk Riwayat)\n";
        cout << "9. Batalkan Transaksi Terakhir (Pop)\n";
        cout << "10. Lihat Data Terdepan (Peek)\n";
        cout << "11. Tampilkan Semua Antrian\n";
        cout << "12. Tampilkan Semua Riwayat\n";
        cout << "0. Keluar\n";
        cout << "Pilihan: ";
        cin >> pilihan;

        switch (pilihan) {
            case 1: tampilJadwal(daftarKereta, jumlahKereta); break;
            case 2: tambahKereta(daftarKereta, jumlahKereta); break;
            case 3: {
                cin.ignore();
                string asal, tujuan;
                cout << "Masukkan Kota Asal: "; getline(cin, asal);
                cout << "Masukkan Kota Tujuan: "; getline(cin, tujuan);
                linearSearchRute(daftarKereta, jumlahKereta, asal, tujuan);
                break;
            }
            case 4: {
                int cari;
                cout << "Masukkan Nomor Kereta: "; cin >> cari;
                jumpSearchNomor(daftarKereta, jumlahKereta, cari);
                break;
            }
            case 5:
                selectionSortHarga(daftarKereta, jumlahKereta);
                tampilJadwal(daftarKereta, jumlahKereta);
                break;
            case 6:
                if(jumlahKereta > 0) {
                    mergeSortNama(daftarKereta, 0, jumlahKereta - 1);
                    cout << "\nBerhasil diurutkan berdasarkan nama (A-Z)\n";
                    tampilJadwal(daftarKereta, jumlahKereta);
                } else {
                    cout << "Data masih kosong\n";
                }
                break;
            case 7: 
                cin.ignore();
                enqueue(); 
                break;
            case 8: 
                dequeue(); 
                break;
            case 9: 
                pop(); 
                break;
            case 10: 
                peek(); 
                break;
            case 11: 
                tampilkanSemuaAntrian(antrian, front, rear); 
                break;
            case 12: 
                tampilkanSemuaRiwayat(riwayat, top); 
                break;
            case 0:
                cout << "Terima kasih telah menggunakan sistem ini\n";
                break;
            default:
                cout << "Pilihan tidak valid\n";
        }
    } while (pilihan != 0);

    delete[] daftarKereta;
    return 0;
}