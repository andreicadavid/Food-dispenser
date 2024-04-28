//
// Created by andre_pzeda4p on 5/15/2023.
//

#include "RepoFile.h"
#include <fstream>
#include <cstring>

void RepoFile::savetofileP() {
    ofstream  f(this->filenameProduse);
    for(Produs crt : this->p)
        f<<crt.get_cod()<<" "<<crt.get_nume()<<" "<<crt.get_pret()<<endl;
    f.close();
}
void RepoFile::savetofileB() {
    ofstream  f(this->filenameBancnote);
    for(int i = 0 ;i < 8; i++)
        f<<T.getBancnota(i)<<" "<<T.getAparitie(i)<<endl;
    f.close();
}

RepoFile::RepoFile(const char *filename1,const char *filename2) {
    Produs produs;
    this->filenameProduse = new char[strlen(filename1) + 1];
    strcpy(this->filenameProduse,filename1);
    ifstream fP(this ->  filenameProduse);
    while(!fP.eof()){
        int cod = 0;
        char* nume = new char[50];
        float pret = 0;
        fP>>cod>>nume>>pret;
        produs.set_cod(cod);
        produs.set_nume(nume);
        produs.set_pret(pret);
        addProdus(produs);
        delete[] nume;
    }
    fP.close();
    this->filenameBancnote = new char[strlen(filename2) + 1];
    strcpy(this->filenameBancnote,filename2);
    ifstream fB(this->filenameBancnote);
    while(!fB.eof()){
        int bancnota = 0;
        int frecventa = 0;
        fB>>bancnota>>frecventa;
        RepoFile::addBancnota(bancnota, frecventa);
        this->addBancnota(bancnota,frecventa);
    }
    fB.close();
}

RepoFile::RepoFile() : Repo() {
    this->filenameProduse = nullptr;
    this->filenameBancnote = nullptr;
}

void RepoFile::addProdus(Produs &p) {
    Repo::addElem(p);
    savetofileP();
}

void RepoFile::updateProdus(int poz, Produs &p) {
    Repo::updateElem(poz,p);
    savetofileP();
}

void RepoFile::deleteProdus(int poz) {
    Repo::deleteElem(poz);
    savetofileP();
}

void RepoFile::Buy(int poz, float valoare, float &rest) {
    Repo::Buy(poz,valoare,rest);
    savetofileP();
}

vector<Produs> RepoFile::getAll() {
    return Repo::getAll();
}

RepoFile::~RepoFile() {

}

void RepoFile::addBancnota(int bancnota, int frecventa) {
    Repo::addBancnota(bancnota ,frecventa);
    savetofileB();
}

RepoFile &RepoFile::operator=(RepoFile &R1) {
    Repo::operator=(R1);
    this->filenameProduse = new char[100];
    std::strcpy(this->filenameProduse,R1.filenameProduse);
    this->filenameBancnote = new char[100];
    std::strcpy(this->filenameBancnote,R1.filenameBancnote);
}

int RepoFile::getSize() {
    return Repo::getSize();
}

TonomatMaiBun &RepoFile::getTonomat() {
    return Repo::getTonomat();
}

Produs RepoFile::getElem(int poz) {
    return Repo::getElem(poz);
}

vector<int> RepoFile::getAllBancnote() {
    return Repo::getAllBancnote();
}

//void RepoFile::savetofileB() {
//    ofstream  f(filenameBancnote);
//    for(int crt : B)
//        f<<crt.<<" "<<crt.get_nume()<<" "<<crt.get_pret()<<endl;
//    f.close();
//}

