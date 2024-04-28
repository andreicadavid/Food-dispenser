//
// Created by andre_pzeda4p on 5/8/2023.
//

#include "Tests.h"
#include <cassert>

void Tests::testeService() {
    Produs p1(123,"Slanina",12.12),p2(456,"Lapte",16.99),p3(789,"Sunca",13);
    this->S.addElemS(123,"Slanina",12.12);
    assert(this->S.getSize() == 1);
    this->S.addElemS(789,"Sunca",13);
    this->S.addBancnota(20,2);
    this->S.updateElemS(1,456,"Lapte",16.99);
}

void Tests::testeRepo() {
    Produs p1(123,"Slanina",12.12),p2(456,"Lapte",16.99),p3(789,"Sunca",13);
    this->R.addElem(p1);
    assert(this->R.getSize() == 1);
    this->R.addElem(p2);
    assert(this->R.getSize() == 2);
    this->R.updateElem(0,p3);
    assert(this->R.getElem(0) == p3);
    Produs nul(0,"-",0);
    this->R.deleteElem(1);
    assert(this->R.getElem(1) == nul);
}
