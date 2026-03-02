#include <iostream>
using namespace std;

void FindMin(int A[], int n, int &minIndex) {
    int min_val = A[0];
    minIndex = 0;

    for (int i = 1; i < n; i++) {
        if (A[i] < min_val) {
            min_val = A[i];
            minIndex = i;
        }
    }
}

int main() {
    int arr[] = {1, 1, 2, 3, 5, 8, 13, 21};
    int n = 8;
    int indeks_min = 0;
    FindMin(arr, n, indeks_min);
    int nilai_min = arr[indeks_min];

    cout << "Array: {1, 1, 2, 3, 5, 8, 13, 21}" << endl;
    cout << "Nilai minimum        : " << nilai_min << endl;
    cout << "Indeks nilai minimum : " << indeks_min << endl;
    return 0;
}

/*
 ANALISIS(Big-O)
    Best Case : O(n)
    Skenario  : Array terurut menaik (minimum di awal). Perulangan tetap 
    mengecek seluruh elemen sebanyak (n-1) kali, walau
    blok pembaruan nilai min tidak dieksekusi.

 Worst Case: O(n)
    Skenario  : Array terurut menurun (minimum di akhir). Perulangan 
    tetap mengecek seluruh elemen sebanyak (n-1) kali, 
    dan blok pembaruan nilai min selalu dieksekusi 
    di setiap iterasi.
 */