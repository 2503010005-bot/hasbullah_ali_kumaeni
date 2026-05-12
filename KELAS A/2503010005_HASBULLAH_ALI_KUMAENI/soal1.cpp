#include <iostream>
#include <string>
#include <iomanip>

using namespace std;
struct Buku {
    string judul;
    string pengarang;
    int tahunTerbit;
    float harga;
};

int main() {
    const int MAX_BUKU = 5;
    Buku daftarBuku[MAX_BUKU];
    int n;

    cout << "PROGRAM PENGELOLAAN DATA TOKO BUKU" << endl;
    
    do {
        cout << "Masukkan jumlah buku (1-5): ";
        cin >> n;
        if (n < 1 || n > MAX_BUKU) {
            cout << "Peringatan: Jumlah buku harus antara 1 sampai 5!" << endl;
        }
    } while (n < 1 || n > MAX_BUKU);

    for (int i = 0; i < n; i++) {
        cout << "\n--- Input Data Buku Ke-" << i + 1 << " ---" << endl;
        
        cin.ignore(); 
        
        cout << "Judul         : ";
        getline(cin, daftarBuku[i].judul);
        
        cout << "Pengarang     : ";
        getline(cin, daftarBuku[i].pengarang);
        
        cout << "Tahun Terbit  : ";
        cin >> daftarBuku[i].tahunTerbit;
        
        cout << "Harga         : ";
        cin >> daftarBuku[i].harga;
    }

    cout << "\n" << setfill('=') << setw(72) << "" << endl;
    cout << setfill(' ');
    cout << left << setw(4) << "No" << " | "
         << setw(20) << "Judul" << " | "
         << setw(15) << "Pengarang" << " | "
         << setw(6) << "Tahun" << " | "
         << setw(12) << "Harga" << endl;
    cout << setfill('-') << setw(72) << "" << endl;
    cout << setfill(' ');

    for (int i = 0; i < n; i++) {
        cout << left << setw(4) << i + 1 << " | "
             << setw(20) << (daftarBuku[i].judul.length() > 19 ? daftarBuku[i].judul.substr(0, 16) + "..." : daftarBuku[i].judul) << " | "
             << setw(15) << (daftarBuku[i].pengarang.length() > 14 ? daftarBuku[i].pengarang.substr(0, 11) + "..." : daftarBuku[i].pengarang) << " | "
             << setw(6) << daftarBuku[i].tahunTerbit << " | "
             << fixed << setprecision(2) << setw(12) << daftarBuku[i].harga << endl;
    }
    cout << setfill('=') << setw(72) << "" << endl;

    int indexMax = 0;
    for (int i = 1; i < n; i++) {
        if (daftarBuku[i].harga > daftarBuku[indexMax].harga) {
            indexMax = i;
        }
    }
    cout << "\n>>> Buku dengan Harga Tertinggi <<<" << endl;
    cout << "Judul      : " << daftarBuku[indexMax].judul << endl;
    cout << "Pengarang  : " << daftarBuku[indexMax].pengarang << endl;
    cout << "Tahun      : " << daftarBuku[indexMax].tahunTerbit << endl;
    cout << "Harga      : Rp " << fixed << setprecision(2) << daftarBuku[indexMax].harga << endl;

    float total = 0;
    for (int i = 0; i < n; i++) {
        total += daftarBuku[i].harga;
    }
    float rataRata = total / n;
    cout << "\n>>> Rata-rata Harga Seluruh Buku: Rp " << fixed << setprecision(2) << rataRata << endl;

    int cariTahun;
    bool ada = false;
    cout << "\nMasukkan tahun terbit yang ingin dicari: ";
    cin >> cariTahun;

    cout << "Daftar buku terbit tahun " << cariTahun << ":" << endl;
    for (int i = 0; i < n; i++) {
        if (daftarBuku[i].tahunTerbit == cariTahun) {
            cout << "- " << daftarBuku[i].judul << " (Pengarang: " << daftarBuku[i].pengarang << ")" << endl;
            ada = true;
        }
    }

    if (!ada) {
        cout << "Tidak ada buku yang terbit pada tahun tersebut." << endl;
    }

    return 0;
}
