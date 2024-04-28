//
// Created by andre_pzeda4p on 5/8/2023.
//

#ifndef LAB_9_10_SERVICE_H
#define LAB_9_10_SERVICE_H
#include "RepoFile.h"
#include "Produs.h"

class Service {
private:
    RepoFile R;
public:
    Service();
    Service(RepoFile&);
    Service(Service&);
    ~Service();
    void addElemS(int,const char*,float);
    void updateElemS(int,int,const char*,float);
    void deleteElemS(int);
    void addBancnota(int,int);
    void Buy(int,float,float&);
    int getSize();
//    int getSizeTonomat();
    vector<Produs> getAll();
//    vector<int> getAllAparitii();
    vector<int> getAllBancnote();
    Produs getElem(int);
};


#endif //LAB_9_10_SERVICE_H
