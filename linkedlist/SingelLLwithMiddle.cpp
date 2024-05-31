#include <iostream>

using namespace std;

struct Buku{

  string judul, pengarang;
  int tahunTerbit;

  Buku *next;

};

Buku *kepala, *ekor, *cur, *nodeBaru, *del, *sebelum;

void buatSingleLinkedList(string judul, string pengarang, int tB){
  kepala = new Buku();
  kepala->judul = judul;
  kepala->pengarang = pengarang;
  kepala->tahunTerbit = tB;
  kepala->next = NULL;
  ekor = kepala;
}

//menampilkan
int hitungSingleLinkedList(){
  cur = kepala;
  int jumlah = 0;
  while( cur != NULL ){
    jumlah++;
    cur = cur->next;
  }
  return jumlah;
}


void addFirst(string judul, string pengarang, int tB){
  nodeBaru = new Buku();
  nodeBaru->judul = judul;
  nodeBaru->pengarang = pengarang;
  nodeBaru->tahunTerbit = tB;
  nodeBaru->next = kepala;
  kepala = nodeBaru;
}


void addLast(string judul, string pengarang, int tB){
  nodeBaru = new Buku();
  nodeBaru->judul = judul;
  nodeBaru->pengarang = pengarang;
  nodeBaru->tahunTerbit = tB;
  nodeBaru->next = NULL;
  ekor->next = nodeBaru;
  ekor = nodeBaru;
}


void addMiddle(string judul, string pengarang, int tB, int posisi){
  if( posisi < 1 || posisi > hitungSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->tahunTerbit = tB;
//transfer
    cur = kepala;
    int nomor = 1;
    while( nomor < posisi - 1 ){
      cur = cur->next;
      nomor++;
    }
    nodeBaru->next = cur->next;
    cur->next = nodeBaru;
  }
}



void hapusawal(){
  del = kepala;
  kepala = kepala->next;
  delete del;
}


void hapusakhir(){
  del = ekor;
  cur = kepala;
  while( cur->next != ekor ){
    cur = cur->next;
  }
  ekor = cur;
  ekor->next = NULL;
  delete del;
}


void hapusmidle(int posisi){
  if( posisi < 1 || posisi > hitungSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    int nomor = 1;
    cur = kepala;
    while( nomor <= posisi ){
      if( nomor == posisi-1 ){
        sebelum = cur;
      }
      if( nomor == posisi ){
        del = cur;
      }
      cur = cur->next;
      nomor++;
    }
    sebelum->next = cur;
    delete del;
  }
}


void changeFirst(string judul, string pengarang, int tB){
  kepala->judul = judul;
  kepala->pengarang = pengarang;
  kepala->tahunTerbit = tB;
}


void changeLast(string judul, string pengarang, int tB){
  ekor->judul = judul;
  ekor->pengarang = pengarang;
  ekor->tahunTerbit = tB;
}


void changeMiddle(string judul, string pengarang, int tB, int posisi){
  if( posisi < 1 || posisi > hitungSingleLinkedList() ){
    cout << "Posisi diluar jangkauan" << endl;
  }else if( posisi == 1 || posisi == hitungSingleLinkedList() ){
    cout << "Posisi bukan posisi tengah" << endl;
  }else{
    cur = kepala;
    int nomor = 1;
    while( nomor < posisi ){
      cur = cur->next;
      nomor++;
    }
    cur->judul = judul;
    cur->pengarang = pengarang;
    cur->tahunTerbit = tB;
  }
}





void printSingleLinkedList(){
  cout << "Jumlah data ada : " << hitungSingleLinkedList() << endl;
  cur = kepala;
  while( cur != NULL ){
    cout << "Judul Buku : " << cur->judul << endl;
    cout << "Pengarang Buku : " << cur->pengarang << endl;
    cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;

    cur = cur->next;
  }
}

int main(){

  buatSingleLinkedList("yA", "sena", 3000);
  printSingleLinkedList();

  cout << "\n\n" << endl;
  addFirst("how", "sola", 2090);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  addLast("anda", "jamal", 1999);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  hapusawal();
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  addLast("Ambatron", "Rusdi", 2030);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  hapusakhir();
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  changeFirst("Moyji", "Amber", 2015);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  addMiddle("Senja", "budiono", 215, 2);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  addMiddle("GILA", "Jerry", 2019, 2);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  hapusmidle(5);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
  changeMiddle("Makan Air", "Alden", 2999, 2);
  printSingleLinkedList();
  
  cout << "\n\n" << endl;
}