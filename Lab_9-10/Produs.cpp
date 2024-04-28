//
// Created by andre_pzeda4p on 5/7/2023.
//
#include <cstring>
#include "Produs.h"

Produs::Produs() {
    this->cod = 0;
    this->nume = new char[50];
    this->pret = 0;
}

Produs::Produs(int c,const char *n, float p) {
    this->cod = c;
    this->nume = new char[strlen(n) + 1];
    strcpy(this->nume,n);
    this->pret = p;
}

Produs::Produs(const Produs &P) {
    this->cod = P.cod;
    this->nume = new char[strlen(P.nume) + 1];
    strcpy(this->nume,P.nume);
    this->pret = P.pret;
}

int Produs::get_cod() {
    return this->cod;
}

char *Produs::get_nume() {
    return this->nume;
}

float Produs::get_pret() {
    return this->pret;
}

void Produs::set_cod(int c) {
    this->cod = c;
}

void Produs::set_nume(char *n) {
    if(this->nume != nullptr)
        delete[] this->nume;
    this->nume = new char[strlen(this->nume) + 1];
    strcpy(this->nume,n);
}

void Produs::set_pret(float p) {
    this->pret = p;
}

bool Produs::operator==(Produs &P) {
    return (this->cod == P.cod) and (strcmp(this->nume,P.nume) == 0) and (this->pret == P.pret);
}

Produs& Produs::operator=(const Produs &P) {
    this->cod = P.cod;
    this->pret = P.pret;
    delete[] this->nume;
    this->nume = new char[20];
    strcpy(this->nume,P.nume);
    return* this;
}

Produs::~Produs() {
    this->cod = 0;
    this->pret = 0;
//    delete[] this->nume;
}
