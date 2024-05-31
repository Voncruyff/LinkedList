#include <iostream>

using namespace std;

struct Buku{

  string judul, pengarang;
  int tahunTerbit;

  Buku *next;

};

Buku *kepala, *ekor, *cur, *nodeBaru, *del;

void buatSingleLinkedList(string judul, string pengarang, int tB) {
    kepala = new Buku();
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->tahunTerbit = tB;
    kepala->next = NULL;
    ekor = kepala;
}

void addFirst(string judul, string pengarang, int tB) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->tahunTerbit = tB;
    nodeBaru->next = kepala;
    kepala = nodeBaru;
}

void addLast(string judul, string pengarang, int tB) {
    nodeBaru = new Buku();
    nodeBaru->judul = judul;
    nodeBaru->pengarang = pengarang;
    nodeBaru->tahunTerbit = tB;
    nodeBaru->next = NULL;
    if (ekor != NULL) {
        ekor->next = nodeBaru;
    }
    ekor = nodeBaru;
    if (kepala == NULL) {
        kepala = ekor;
    }
}

void hapusawal() {
    if (kepala == NULL) {
        cout << "List kosong, tidak bisa menghapus" << endl;
        return;
    }
    del = kepala;
    kepala = kepala->next;
    delete del;
    if (kepala == NULL) {
        ekor = NULL;
    }
}

void hapusakhir() {
    if (kepala == NULL) {
        cout << "List kosong, tidak bisa menghapus" << endl;
        return;
    }
    if (kepala == ekor) {
        delete kepala;
        kepala = ekor = NULL;
    } else {
        del = ekor;
        cur = kepala;
        while (cur->next != ekor) {
            cur = cur->next;
        }
        ekor = cur;
        ekor->next = NULL;
        delete del;
    }
}

void changeFirst(string judul, string pengarang, int tB) {
    if (kepala == NULL) {
        cout << "List kosong, tidak bisa mengubah" << endl;
        return;
    }
    kepala->judul = judul;
    kepala->pengarang = pengarang;
    kepala->tahunTerbit = tB;
}

void changeLast(string judul, string pengarang, int tB) {
    if (ekor == NULL) {
        cout << "List kosong, tidak bisa mengubah" << endl;
        return;
    }
    ekor->judul = judul;
    ekor->pengarang = pengarang;
    ekor->tahunTerbit = tB;
}

int hitungSingleLinkedList() {
    int count = 0;
    cur = kepala;
    while (cur != NULL) {
        count++;
        cur = cur->next;
    }
    return count;
}

void printSingleLinkedList() {
    cout << "Jumlah data ada : " << hitungSingleLinkedList() << endl;
    cur = kepala;
    while (cur != NULL) {
        cout << "Judul Buku : " << cur->judul << endl;
        cout << "Pengarang Buku : " << cur->pengarang << endl;
        cout << "Tahun Terbit Buku : " << cur->tahunTerbit << endl;
        cur = cur->next;
    }
}

int main() {
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
    changeLast("Finale", "Ender", 2025);
    printSingleLinkedList();

    cout << "\n\n" << endl;

    return 0;
}