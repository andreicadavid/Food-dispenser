//
// Created by andre_pzeda4p on 5/8/2023.
//

#include "Repo.h"

Repo::Repo() {
    this->size = 0;
}

Repo::Repo(vector<Produs> &p1,TonomatMaiBun& T1, int size1) {
    for(int i=0;i<this->getSize();i++)
        this->p[i] = p1[i];
    this->T = T1;
    this->size = size1;
}

Repo::Repo(Repo &R) {
    for(int i=0;i<this->getSize();i++)
        this->p[i] = R.p[i];
    this->T = R.T;
    this->size = R.size;
}

Repo::~Repo() {
    Produs nul(0,"-",0);
    for(int i=0;i<this->getSize();i++)
        this->p[i] = nul;
    this->size = 0;
}

int Repo::getSize() const {
    return this->size;
}

Produs Repo::getElem(int poz) {
    return this->p[poz];
}

void Repo::addElem(Produs &produs) {
    this->p.push_back(produs);
    this->size++;
}

void Repo::updateElem(int poz, Produs& produs) {
    this->p[poz] = produs;
}

void Repo::deleteElem(int poz) {
    Produs nul(0,"-",0);
    this->p[poz] = nul;
}

void Repo::addBancnota(int bancnota,int nr) {

    this->T.addBancnote(bancnota,nr);
}

vector<Produs> Repo::getAll() {
    return this->p;
}

Repo& Repo::operator=(const Repo &R) {
    for(int i=0;i<R.size;i++)
//        this->p[i] = R.p[i];
        this->p.push_back(R.p[i]);
    this->size =R.size;
    return *this;
}

bool Repo::operator==(const Repo &R) const {
    return (this->size == R.size);// mai trebuie
}

TonomatMaiBun &Repo::getTonomat() {
    return this->T;
}

void Repo::Buy(int poz, float valoare, float& rest) {// pozitia produsului / valoarea
    Produs produs = getElem(poz);
    float coprest;
    vector<int> bancnote = T.getBancnote();
    if(valoare == produs.get_pret()){
        deleteElem(poz);//se sterge produsul din tonomat;
        rest = 0;
    }
    if(valoare > produs.get_pret()){
        rest = valoare - produs.get_pret();
        deleteElem(poz);
    }
    coprest = rest;
    while(valoare > 1){
        if (5 >= valoare && valoare > 1) {
            valoare = valoare - 1;
            bancnote[0]++;
        }
        if (10 >= valoare && valoare > 5) {
            valoare = valoare - 5;
            bancnote[1]++;
        }
        if (20 >= valoare && valoare > 10) {
            valoare = valoare - 10;
            bancnote[2]++;
        }
        if (50 >= valoare && valoare > 20) {
            valoare = valoare - 20;
            bancnote[3]++;
        }
        if (100 >= valoare && valoare > 50) {
            valoare = valoare - 50;
            bancnote[4]++;
        }
        if (200 >= valoare && valoare > 100) {
            valoare = valoare - 100;
            bancnote[5]++;
        }
        if (500 >= valoare && valoare > 200) {
            valoare = valoare - 200;
            bancnote[6]++;
        }
        if (valoare > 500) {
            valoare = valoare - 500;
            bancnote[7]++;
        }
    }
    while(coprest > 1){
        if (5 >= coprest && coprest > 1) {
            coprest -= 1;
            bancnote[0]--;
        }
        if (10 >= coprest && coprest > 5) {
            coprest -= 5;
            bancnote[1]--;
        }
        if (20 >= coprest && coprest > 10) {
            coprest -= 10;
            bancnote[2]--;
        }
        if (50 >= coprest && coprest > 20) {
            coprest -= 20;
            bancnote[3]--;
        }
        if (100 >= coprest && coprest > 50) {
            coprest -= 50;
            bancnote[4]--;
        }
        if (200 >= coprest && coprest > 100) {
            coprest -= 100;
            bancnote[5]--;
        }
        if (500 >= coprest && coprest > 200) {
            coprest -= 200;
            bancnote[6]--;
        }
        if (coprest > 500) {
            coprest -= 500;
            bancnote[7]--;
        }
    }
    this->T.setBancnote(bancnote);
}

vector<int> Repo::getAllBancnote() {
    return this->T.getBancnote();
}




