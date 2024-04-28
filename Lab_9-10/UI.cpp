//
// Created by andre_pzeda4p on 5/8/2023.
//
#include <iostream>
#include "UI.h"
using namespace std;

UI::UI() {

}

UI::UI(Service &S1) {
    this->S = S1;
}

UI::UI(UI &U) {
    this->S = U.S;
}

UI::~UI() {

}

void UI::addElemU() {
    try {
        int cod;
        char *nume = new char[20];
        float pret;
        Validator v;
        cout << "Introduceti CODUL produsului: ";
        cin >> cod;
        cout << endl;
        cout << "Introduceti NUMELE produsului: ";
        cin.get();
        cin.getline(nume, 20);
        cout << endl;
        cout << "Introduceti PRETUL produsului: ";
        cin >> pret;
        cout << endl;
        v.validare_adaugare(cod, nume, pret);
        S.addElemS(cod, nume, pret);
        delete[] nume;
    }catch(std::invalid_argument e){
        cout<<endl;
        cout<<e.what();
        cout<<endl;
    }
}

void UI::updateElemU() {
    try {
        int cod, poz;
        char *nume = new char[20];
        float pret;
        Validator v;
        printAll();
        cout << "Introduceti NUMARUL PRODUSULUI pe care doriti sa il modificati: ";
        cin >> poz;
        cout << endl;
        cout << "Introduceti CODUL produsului: ";
        cin >> cod;
        cout << endl;
        cout << "Introduceti NUMELE produsului: ";
        cin.get();
        cin.getline(nume, 20);
        cout << endl;
        cout << "Introduceti PRETUL produsului: ";
        cin >> pret;
        cout << endl;
        v.validare_update(cod, nume, pret);
        S.updateElemS(poz, cod, nume, pret);
        delete[] nume;
    }catch(std::invalid_argument e){
        cout<<endl;
        cout<<e.what();
        cout<<endl;
    }
}

void UI::deleteElemU() {
    int poz;
    cout<<"Introduceti NUMARUL PRODUSULUI pe care doriti sa il stergeti: ";
    cin>>poz;
    cout<<endl;
    S.deleteElemS(poz);
}
void UI::addBancnota() {
    try {
        int bancnota, nr;
        Validator v;
        cout << "Introduceti BANCNOTA pe care doriti sa o introduceti: ";
        cin >> bancnota;
        cout << endl;
        cout << "Cate bancnote: ";
        cin >> nr;
        cout << endl;
        v.validare_bancnota(nr);
        S.addBancnota(bancnota, nr);
    }catch(std::invalid_argument e){
        cout<<endl;
        cout<<e.what();
        cout<<endl;
    }
}

void UI::printAll() {
    vector<Produs> vector = S.getAll();
    cout<<"-------------------------------"<<endl;
    for(int i=0;i<S.getSize();i++)
        cout<<"Numarul Produsului: "<<i<<" "<<"Codul: "<<vector[i].get_cod()<<" "<<"Numele: "<<vector[i].get_nume()<<" "<<"Pretul: "<<vector[i].get_pret()<<" "<<endl;
    cout<<"-------------------------------"<<endl;
}

void UI::findElem() {

}

void UI::printMenu() {
    cout<<"1.Adauga Produs."<<endl;
    cout<<"2.Modifica Produs."<<endl;
    cout<<"3.Sterge Produs."<<endl;
    cout<<"4.Print All."<<endl;
    cout<<"5.Adauga Bancnota."<<endl;
    cout<<"6.Print Bancnote."<<endl;
    cout<<"7.BUY"<<endl;
    cout<<"0.Exit."<<endl;
}

void UI::menu() {
    int op;
    bool value = true;
//    this->S.addElemS(123,"corn",12);
//    this->S.addElemS(456,"lapte",7);
    this->S.addBancnota(20,1);
    this->S.addBancnota(5,1);
    this->S.addBancnota(1,3);
    while(value) {
        printMenu();
        cout << "Introduceti optiunea dorita: ";
        cin >> op;
        cout << endl;
        switch (op) {
            case 1:
                addElemU();
                break;
            case 2:
                updateElemU();
                break;
            case 3:
                deleteElemU();
                break;
            case 4:
                printAll();
                break;
            case 5:
                addBancnota();
                break;
            case 6:
                printAllBancnote();
                break;
            case 7:
                BuyU();
                break;
            default:
                cout << "Introduceti o optiune valida" << endl;
                value = false;
                break;
        }
    }
}

UI &UI::operator=(UI &U) {
    if(this != &U)
        this->S = U.S;
    return* this;
}

void UI::BuyU() {
    int numarProdus;
    float valoare,rest = 0;
    cout<<"Introduceti NUMARUL PRODUSULUI pe care doriti sa il CUMPARATI: ";
    cin>>numarProdus;
    cout<<endl;
    cout<<"Introduceti VALOAREA de care dispuneti: ";
    cin>>valoare;
    cout<<endl;
    this->S.Buy(numarProdus,valoare,rest);
    cout<<"Restul dumneavoastra este:  ";
    cout<<rest;
    cout<<endl;
}

void UI::printAllBancnote() {
    vector<int> bancnote = S.getAllBancnote();
//    bancnote.push_back(1);
//    bancnote.push_back(5);
//    bancnote.push_back(10);
//    bancnote.push_back(20);
//    bancnote.push_back(50);
//    bancnote.push_back(100);
//    bancnote.push_back(200);
//    bancnote.push_back(500);
//    aparitii.push_back(23);
//    aparitii.push_back(23);
//    aparitii.push_back(23);
//    aparitii.push_back(23);
//    aparitii.push_back(23);
//    aparitii.push_back(10);
//    aparitii.push_back(10);
//    aparitii.push_back(10);
    cout<<"-------------------------------"<<endl;
    cout<<"Bancnote de 1 leu:  "<<bancnote[0]<<endl;
    cout<<"Bancnote de 5 lei:  "<<bancnote[1]<<endl;
    cout<<"Bancnote de 10 lei:  "<<bancnote[2]<<endl;
    cout<<"Bancnote de 20 de lei:  "<<bancnote[3]<<endl;
    cout<<"Bancnote de 50 de lei:  "<<bancnote[4]<<endl;
    cout<<"Bancnote de 100 de lei:  "<<bancnote[5]<<endl;
    cout<<"Bancnote de 200 de lei:  "<<bancnote[6]<<endl;
    cout<<"Bancnote de 500 de lei:  "<<bancnote[7]<<endl;
    cout<<endl;
    cout<<endl;
    int suma = 0;
    for(int i = 0 ; i < 8 ; i++){
        if(i == 0)
            suma += (1*bancnote[0]);
        if(i == 1)
            suma += (5*bancnote[1]);
        if(i == 2)
            suma += (10*bancnote[2]);
        if(i == 3)
            suma += (20*bancnote[3]);
        if(i == 4)
            suma+=(50*bancnote[4]);
        if(i == 5)
            suma += (100*bancnote[5]);
        if(i == 6)
            suma += (200*bancnote[6]);
        if(i == 7)
            suma += (500*bancnote[7]);
    }
    cout<<"Suma totala este: ";
    cout<<suma<<endl;
    cout<<"-------------------------------"<<endl;
}



