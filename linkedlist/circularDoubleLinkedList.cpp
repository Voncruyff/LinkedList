#include <iostream>
using namespace std;

struct Mahasiswa{
  string npm, nama;
  int jurusan;

  Mahasiswa *prev;
  Mahasiswa *next;
};

Mahasiswa *kepala, *ekor, *nodeBaru, *cur, *del, *afterNode;

// fungsi membuat circular double Linked list
void createDataMahasiswa( string npm, string nama, int jurusan){
  kepala = new Mahasiswa();
  kepala->npm = npm;
  kepala->nama = nama;
  kepala->jurusan = jurusan;
  kepala->prev = kepala;
  kepala->next = kepala;
  ekor = kepala;
}

// add First
void addFirst( string npm, string nama, int jurusan){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    nodeBaru = new Mahasiswa();
    nodeBaru->npm = npm;
    nodeBaru->nama = nama;
    nodeBaru->jurusan = jurusan;
    nodeBaru->prev = ekor;
    nodeBaru->next = kepala;
    kepala->prev = nodeBaru;
    ekor->next = nodeBaru;
    kepala = nodeBaru;
  }
}

// add Last
void addLast( string npm, string nama, int jurusan){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    nodeBaru = new Mahasiswa();
    nodeBaru->npm = npm;
    nodeBaru->nama = nama;
    nodeBaru->jurusan = jurusan;
    nodeBaru->prev = ekor;
    nodeBaru->next = kepala;
    kepala->prev = nodeBaru;
    ekor->next = nodeBaru;
    ekor = nodeBaru;
  }
}

// add Middle
void addMiddle(  string npm, string nama, int jurusan, int posisi ){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      nodeBaru = new Mahasiswa();
      nodeBaru->npm = npm;
      nodeBaru->nama = nama;
      nodeBaru->jurusan = jurusan;

      // tranversing
      cur = kepala;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      afterNode = cur->next;
      cur->next = nodeBaru;
      afterNode->prev = nodeBaru;
      nodeBaru->prev = cur;
      nodeBaru->next = afterNode;
    }
  }
}

// remove First
void removeFirst(){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = kepala;
    kepala = kepala->next;
    ekor->next = kepala;
    kepala->prev = ekor;
    delete del;
  }
}

// remove Last
void removeLast(){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    del = ekor;
    ekor = ekor->prev;
    ekor->next = kepala;
    kepala->prev = ekor;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    if( posisi == 1 ){
      cout << "Posisi 1 bukan posisi tengah" << endl;
    }else if( posisi < 1 ){
      cout << "Posisi diluar jangkauan" << endl;
    }else{
      // tranversing
      cur = kepala;
      int nomor = 1;
      while ( nomor < posisi - 1 ){
        cur = cur->next;
        nomor++;
      }
      del = cur->next;
      afterNode = del->next;
      cur->next = afterNode;
      afterNode->prev = cur;
      delete del;
    }
  }
}

// fungsi print
void printDataMahasiswa()
{
  if( kepala == NULL ){
    cout << "Buat Linked List dahulu!!" << endl;
  }else{
    cout << "Data Mahasiswa : " << endl;
    cur = kepala;
    while( cur->next != kepala ){
      // print
      cout << "NIM : " << cur->npm << endl;
      cout << "Nama : " << cur->nama << " barang" << endl;
      cout << "Jurusan : " << cur->jurusan << "\n" << endl;

      // step
      cur = cur->next;
    }
    // print last node
      cout << "NIM : " << cur->npm << endl;
      cout << "Nama : " << cur->nama << " barang" << endl;
      cout << "Jurusan : " << cur->jurusan << "\n" << endl;
  }
}

int main(){

  createDataMahasiswa("Shampoo", "15", 5000);
  printDataMahasiswa();

  addFirst("Sikat Gigi", "23", 7000);
  printDataMahasiswa();

  addLast("Sabun Mandi", "11", 12000);
  printDataMahasiswa();

  addMiddle("Pomade", "11", 20000, 6);
  printDataMahasiswa();

  removeMiddle(6);
  printDataMahasiswa();



}