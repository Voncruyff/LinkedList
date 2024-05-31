#include <iostream>
using namespace std;

// deklarasi double linked list
struct DataUser{
  string nama, username, email, password;
  DataUser *prev;
  DataUser *next;
};

DataUser *kepala, *ekor, *cur, *nodeBaru, *del, *afterNode;

// Create Double Linked List
void createDoubleLinkedList( string data[4] ){
  kepala = new DataUser();
  kepala->nama = data[0];
  kepala->username = data[1];
  kepala->email = data[2];
  kepala->password = data[3];
  kepala->prev = NULL;
  kepala->next = NULL;
  ekor = kepala;
}

// count Double Linked List
int countDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cur = kepala;
    int jumlah = 0;
    while( cur != NULL ){
      jumlah++;      
      //step
      cur = cur->next;
    }
    return jumlah;
  }
}

// Add First
void addFirst( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->username = data[1];
    nodeBaru->email = data[2];
    nodeBaru->password = data[3];
    nodeBaru->prev = NULL;
    nodeBaru->next = kepala;
    nodeBaru->prev = nodeBaru;
    nodeBaru = nodeBaru;
  }
}

// Add Last
void addLast( string data[4] ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    nodeBaru = new DataUser();
    nodeBaru->nama = data[0];
    nodeBaru->username = data[1];
    nodeBaru->email = data[2];
    nodeBaru->password = data[3];
    nodeBaru->prev = ekor;
    nodeBaru->next = NULL;
    ekor->next = nodeBaru;
    ekor = nodeBaru;
  }
}

// Add Middle
void addMiddle( string data[4], int posisi ){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{

    if( posisi == 1 ){
      cout << "Posisi 1 itu bukan posisi tengah!!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!!" << endl;
    }else{
      nodeBaru = new DataUser();
      nodeBaru->nama = data[0];
      nodeBaru->username = data[1];
      nodeBaru->email = data[2];
      nodeBaru->password = data[3];

      // tranversing
      cur = kepala;
      int nomor = 1;
      while( nomor <  posisi - 1){
        cur = cur->next;
        nomor++;
      }

      afterNode = cur->next;
      nodeBaru->prev = cur;
      nodeBaru->next = afterNode;
      cur->next = nodeBaru;
      afterNode->prev = nodeBaru;
    }

  }
}

// remove First
void removeFirst()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = kepala;
    kepala = kepala->next;
    kepala->prev = NULL;
    delete del;
  }
}

// remove Last
void removeLast()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    del = ekor;
    ekor = ekor->prev;
    ekor->next = NULL;
    delete del;
  }
}

// remove Middle
void removeMiddle(int posisi){
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    if( posisi == 1 || posisi == countDoubleLinkedList() ){
      cout << "Posisi bukan posisi tegah!!" << endl;
    }else if( posisi < 1 || posisi > countDoubleLinkedList() ){
      cout << "Posisi diluar jangkauan!!" << endl;
    }else{
      int nomor = 1;
      cur = kepala;
      while( nomor < posisi - 1 ){
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

// Print Double Linked List
void printDoubleLinkedList()
{
  if( kepala == NULL ){
    cout << "Double Linked List belum dibuat!!!";
  }else{
    cout << "Jumlah Data : " << countDoubleLinkedList() << endl;
    cout << "Isi Data : " << endl;
    cur = kepala;
    while( cur != NULL ){
      // print
      cout << "Nama User : " << cur->nama << endl;
      cout << "Username User : " << cur->username << endl;
      cout << "Email User : " << cur->email << endl;
      cout << "Password User : " << cur->password << "\n" << endl;
      //step
      cur = cur->next;
    }
  }
}

int main(){

  string newData[4] = {"Alden Jo", "Alden", "aldennnnn@gmail.com", "alden123"};
  createDoubleLinkedList(newData);

  printDoubleLinkedList();

  string data2[4] = {"Asep PPP", "Asep", "aseppengendaliangin@gmail.com", "asepXbambang"};

  addFirst( data2 );

  printDoubleLinkedList();

  string data3[4] = {"Locyi", "nowgart", "yaitu@gmail.com", "locio"};

  addLast( data3 );

  printDoubleLinkedList();

  string data4[4] = {"Manusia", "M", "humanrsc@yahoo.com", "justhuman"};
  addMiddle(data4, 3);

  printDoubleLinkedList();

  removeMiddle(2);

  printDoubleLinkedList();


}