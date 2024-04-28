//
// Created by andre_pzeda4p on 5/8/2023.
//

#include "Service.h"

Service::Service() = default;

Service::Service(RepoFile &R1) {
    this->R = R1;
}

Service::Service(Service &S) {
    this->R = S.R;
}

Service::~Service() = default;

void Service::addElemS(int cod, const char *nume, float pret) {
    Produs p(cod,nume,pret);
    this->R.addProdus(p);
}

void Service::updateElemS(int poz, int cod, const char *nume, float pret) {
    Produs nou(cod,nume,pret);
    R.updateProdus(poz,nou);
}

void Service::deleteElemS(int poz) {
    R.deleteProdus(poz);
}

void Service::addBancnota(int bancnota,int nr) {
    R.addBancnota(bancnota,nr);
}

int Service::getSize() {
    return this->R.getSize();
}

vector<Produs> Service::getAll() {
    return this->R.getAll();
}

Produs Service::getElem(int poz) {
    return this->R.getElem(poz);
}

void Service::Buy(int numarProdus, float valoare,float& rest) {
    return this->R.Buy(numarProdus,valoare,rest);

}

vector<int> Service::getAllBancnote() {
    return this->R.getAllBancnote();
}

//vector<int> Service::getAllAparitii() {
//    return this->R.getAllAparitii();
//}
//
//int Service::getSizeTonomat() {
//    return this->R.getSizeTonomat();
//}

