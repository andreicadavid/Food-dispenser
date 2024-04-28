//
// Created by andre_pzeda4p on 5/14/2023.
//

#include "TonomatMaiBun.h"

TonomatMaiBun::TonomatMaiBun(){
    for(int i = 0; i < 8 ; i++)
        this->bancnote.push_back(0);
}

TonomatMaiBun::TonomatMaiBun(vector<int> bancnote1) {
    for(int i = 0; i < 8 ; i++)
        this->bancnote[i] = bancnote1[i];
}

TonomatMaiBun::TonomatMaiBun(TonomatMaiBun &T1) {
    for(int i = 0; i < 8 ; i++)
        this->bancnote[i] = T1.bancnote[i];
}

TonomatMaiBun::~TonomatMaiBun() {
    for(int i = 0; i < 8 ; i++)
        this->bancnote[i] = 0;
}

int TonomatMaiBun::getAparitie(int poz) {
    return this->bancnote[poz];
}

int TonomatMaiBun::getPozitieBancnota(int bancnota) {
    if(bancnota == 1) return 0;
    if(bancnota == 5) return 1;
    if(bancnota == 10) return 2;
    if(bancnota == 20) return 3;
    if(bancnota == 50) return 4;
    if(bancnota == 100) return 5;
    if(bancnota == 200) return 6;
    if(bancnota == 500) return 7;
}

int TonomatMaiBun::getBancnota(int poz) {
    if(poz == 0) return 1;
    if(poz == 1) return 5;
    if(poz == 2) return 10;
    if(poz == 3) return 20;
    if(poz == 4) return 50;
    if(poz == 5) return 100;
    if(poz == 6) return 200;
    if(poz == 7) return 500;
}

void TonomatMaiBun::addBancnote(int bancnota,int nr) {
    this->bancnote[getPozitieBancnota(bancnota)]+=nr;
}

vector<int> TonomatMaiBun::getBancnote() {
    return this->bancnote;
}

TonomatMaiBun &TonomatMaiBun::operator=(const TonomatMaiBun &T1) {
    for(int i = 0; i < 8 ; i++)
        this->bancnote[i] = T1.bancnote[i];
    return* this;
}

void TonomatMaiBun::setBancnote(vector<int>&bancnote1) {
    this->bancnote = bancnote1;
}
