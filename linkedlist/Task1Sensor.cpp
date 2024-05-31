#include <iostream>

using namespace std;

struct Data
{
    string sensor, waktu;
    double nilai;

    Data *next;
};

Data *Kepl, *bt, *ini, *nodeBaru, *delt;

void inLinkedlist (string sensor, string waktu, double nilai) {
    Kepl = new Data();
    Kepl->sensor = sensor;
    Kepl->waktu = waktu;
    Kepl->nilai = nilai;
    Kepl->next = NULL;
    bt = Kepl;    
}

void addAwal (string sensor, string waktu, double nilai) {
    nodeBaru = new Data();
    nodeBaru->sensor = sensor;
    nodeBaru->waktu = waktu;
    nodeBaru->nilai = nilai;
    nodeBaru->next = Kepl;
    Kepl = nodeBaru;
}

void addbelakang (string sensor, string waktu, double nilai) {
    nodeBaru = new Data();
    nodeBaru->sensor = sensor;
    nodeBaru->waktu = waktu;
    nodeBaru->nilai = nilai;
    nodeBaru->next = NULL;
    bt->next = nodeBaru;
    bt = nodeBaru;
}


void csAwal(string sensor, string waktu, double nilai) {
    Kepl->sensor = sensor;
    Kepl->waktu = waktu;
    Kepl->nilai = nilai;
}
void csBelakang(string sensor, string waktu, double nilai){
    bt->sensor = sensor;
    bt->waktu = waktu;
    bt->nilai = nilai;
}

void deltAwal () {
    delt = Kepl;
    Kepl = Kepl->next;
    delete delt;
}

void deltBelakang () {
    delt = bt;
    ini = Kepl;
    while (ini->next != bt)
    {
        ini = ini->next;
    }
    bt = ini;
    bt->next = NULL;
    delete delt;  
}

void cetakLinkedlist(){
    ini = Kepl;
    while (ini != NULL)
    {
        cout << "Nama Sensor : " << ini->sensor << endl;
        cout << "Waktu Pemantauan : " << ini->waktu << endl;
        cout << "Nilai Sensor : " << ini->nilai << endl;
        cout << endl;
    ini = ini->next;
    }
    
}

int main () {
 inLinkedlist("Alt", "20 minutes", 90) ;
 addAwal("Eatin Lizard", "170 minutes", 1999999);
 addbelakang("Unknown", "Not Found", 404);
//  deltAwal();
//  deltBelakang();
 csAwal("Lock", "1 minutes", 50);
 csBelakang("Che", "0 minutes", 20);
 deltAwal();
 deltBelakang();
 cetakLinkedlist();

 return 0;
}