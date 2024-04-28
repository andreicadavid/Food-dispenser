//
// Created by andre_pzeda4p on 5/9/2023.
//

#include "Tonomat.h"

Tonomat::Tonomat() {
    this->suma = 0;
    this->size = 0;
}

Tonomat::Tonomat(int suma1, vector<int>bancnote1, vector<int>aparitii1, int size1) {
    this->suma = suma1;
    this->size = size1;
    for(int i=0;i<this->size;i++)
        this->bancnote[i] = bancnote1[i];
    for(int i=0;i<this->size;i++)
        this->aparitii[i] = aparitii1[i];
}

Tonomat::Tonomat(Tonomat &T) {
    this->suma = T.suma;
    this->size = T.size;
    for(int i=0;i<this->size;i++)
        this->bancnote[i] = T.bancnote[i];
    for(int i=0;i<this->size;i++)
        this->aparitii[i] = T.aparitii[i];
}

Tonomat::~Tonomat() {
    this->suma = 0;
    for(int i=0;i<this->size;i++)
        this->bancnote[i] = 0;
    for(int i=0;i<this->size;i++)
        this->aparitii[i] = 0;
    this->size = 0;


}

Tonomat &Tonomat::operator=(const Tonomat &T) {
    this->size = T.size;
    this->suma = T.suma;
    this->aparitii = T.aparitii;
    this->bancnote = T.bancnote;
    return* this;
}

int Tonomat::getSuma() const {
    return this->suma;
}

int Tonomat::getSize() const {
    return this->size;
}

int Tonomat::getAparitie(int poz) {
    return this->aparitii[poz];
}

vector<int> Tonomat::getAparitii() {
    return this->aparitii;
}

void Tonomat::addBancnote(int bancnota) {
    this->bancnote.push_back(bancnota);
    this->aparitii.push_back(0);
    this->size++;
}

vector<int> Tonomat::getBancnote() {
    return this->bancnote;
}

int Tonomat::getPozitieBancnota(int tipBancnota) {
    int i = 0;
    while(i < this->size){
        if(this->bancnote[i] == tipBancnota)
            return i;
        i++;
    }
    return 0;
}

void Tonomat::setSize(int s) {
    this->size = s;
}

void Tonomat::setSuma(int s) {
    this->suma = s;
}

void Tonomat::dealocateAparitii() {
    for(int i = 0;i<this->size;i++)
        this->aparitii[i] = 0;
}

void Tonomat::increaseAparitie(int bancnota) {
    this->aparitii[getPozitieBancnota(bancnota)]++;
}



