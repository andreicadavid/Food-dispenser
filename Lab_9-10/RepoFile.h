//
// Created by andre_pzeda4p on 5/15/2023.
//

#ifndef LAB_9_10_REPOFILE_H
#define LAB_9_10_REPOFILE_H
#include "Repo.h"

class RepoFile:public Repo {
private:
    vector<Produs> P;
    TonomatMaiBun T;
    char* filenameProduse;
    char* filenameBancnote;
    void savetofileP();
    void savetofileB();
public:
    RepoFile();
    RepoFile(const char*,const char*);
    void addProdus(Produs&);
    void updateProdus(int,Produs&);
    void deleteProdus(int);
    void addBancnota(int,int);
    void Buy(int,float,float&);
    vector<Produs> getAll();
    RepoFile& operator=(RepoFile&);
    int getSize();
    TonomatMaiBun& getTonomat();
    Produs getElem(int);
    vector<int> getAllBancnote();
    ~RepoFile();



};


#endif //LAB_9_10_REPOFILE_H
