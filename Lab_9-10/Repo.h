//
// Created by andre_pzeda4p on 5/8/2023.
//

#ifndef LAB_9_10_REPO_H
#define LAB_9_10_REPO_H
#include "Produs.h"
#include "TonomatMaiBun.h"
#include <vector>
using namespace std;

class Repo {
protected:
    vector<Produs> p;
    TonomatMaiBun T;
    int size;
public:
    Repo();
    Repo(vector<Produs>&,TonomatMaiBun&,int);
    Repo(Repo& R);
    ~Repo();
    int getSize() const;
    TonomatMaiBun& getTonomat();
    Produs getElem(int);
    void addElem(Produs&);
    void updateElem(int, Produs&);
    void deleteElem(int);
    void addBancnota(int, int);
    void Buy(int,float,float&);
    vector<Produs> getAll();
    vector<int> getAllBancnote();
    //void aloc();
    Repo& operator=(const Repo&);
    bool operator==(const Repo&) const;
};


#endif //LAB_9_10_REPO_H
