#include <iostream>
#include <string>
using namespace std;

struct batalyon
{
    int ID;
    string general;
    string tipe_pasukan;
    int jumlah_pasukan;
};

string soldier[3] = {"Infantry", "Kavaleri", "Archer"};
batalyon Batalyon[100];
int jumlahBatalyon = 0;
int idBatalyon = 1;

bool soldierValid(string Type)
{
    for (int i = 0; i < 3; i++)
    {
        if (Type == soldier[i])
        {
            return true;
        }
    }
    return false;
}

void tambahBatalyon()
{
    if (jumlahBatalyon >= 100)
    {
        cout << "Batalyon sudah penuh" << endl;
        return;
    }

    batalyon *ptr = &Batalyon[jumlahBatalyon];

    cin.ignore();
    cout << " Input General Name : ";
    getline(cin, Batalyon[jumlahBatalyon].general);

    for (int i = 0; i < jumlahBatalyon; i++)
    {
        if (Batalyon[i].general == Batalyon[jumlahBatalyon].general)
        {
            cout << "General sudah ada" << endl;
            return;
        }
    }

    cout << "Input Soldier Type : ";
    getline(cin, Batalyon[jumlahBatalyon].tipe_pasukan);

    if (!soldierValid(Batalyon[jumlahBatalyon].tipe_pasukan))
    {
        cout << "Tipe pasukan tidak valid" << endl;
        return;
    }

    cout << "Input Soldier Qty : ";
    cin >> Batalyon[jumlahBatalyon].jumlah_pasukan;

    if (Batalyon[jumlahBatalyon].jumlah_pasukan <= 0)
    {
        cout << "Jumlah pasukan tidak valid" << endl;
        return;
    }

    if (jumlahBatalyon > 0)
    {
        int i = jumlahBatalyon - 1;
        while (i >= 0 && Batalyon[i].general > Batalyon[jumlahBatalyon].general)
        {
            Batalyon[i + 1] = Batalyon[i];
            i--;
        }
    }
    Batalyon[jumlahBatalyon].ID = idBatalyon++;
    jumlahBatalyon++;

    cout << "Batalyon berhasil ditambahkan" << endl;
}

void cariBatalyon()
{
    if (jumlahBatalyon == 0)
    {
        cout << "Batalyon tidak tersedia" << endl;
        return;
    }

    cin.ignore();
    string namaGeneral;
    cout << "Nama General yang ingin dicari : ";
    getline(cin, namaGeneral);

    int awal = 0, akhir = jumlahBatalyon - 1, tengah;
    bool found = false;

    while (awal <= akhir)
    {
        tengah = (awal + akhir) / 2;
        if (Batalyon[tengah].general == namaGeneral)
        {
            found = true;
            cout << "ID : " << Batalyon[tengah].ID << endl;
            cout << "General : " << Batalyon[tengah].general << endl;
            cout << "Tipe Pasukan : " << Batalyon[tengah].tipe_pasukan << endl;
            cout << "Jumlah Pasukan : " << Batalyon[tengah].jumlah_pasukan << endl;
            break;
        }
        else if (Batalyon[tengah].general < namaGeneral)
        {
            awal = tengah + 1;
        }
        else
        {
            akhir = tengah - 1;
        }
    }

    if (!found)
    {
        cout << "General tidak ditemukan" << endl;
    }
}

int main()
{
    int pilih;
    string keluar;
    do
    {
        cout << "MENU" << endl;
        cout << "1. Tambah Batalyon" << endl;
        cout << "2. Cari Batalyon" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilih Menu : ";
        cin >> pilih;

        switch (pilih)
        {
        case 1:
            tambahBatalyon();
            break;
        case 2:
            cariBatalyon();
            break;
        case 3:
            cout << "Apakah anda ingin log out?(Y/N)" << endl;
            cin >> keluar;
            if (keluar == "Y" || keluar == "y")
            {
                cout << "Anda telah keluar" << endl;
                return 0;
            }
            break;
        default:
            cout << "Menu tidak tersedia" << endl;
        }
    } while (pilih != 3);
    return 0;
}
