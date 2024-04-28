//
// Created by andre_pzeda4p on 5/9/2023.
//

#ifndef LAB_9_10_TONOMAT_H
#define LAB_9_10_TONOMAT_H
#include <vector>
using namespace std;

class Tonomat {
private:
    int suma;
    vector<int> bancnote;
    vector<int> aparitii;
    int size;
public:
    Tonomat();
    Tonomat(int,vector<int>,vector<int>,int);
    Tonomat(Tonomat&);
    ~Tonomat();
    [[nodiscard]] int getSuma() const;
    [[nodiscard]] int getSize() const;
    int getAparitie(int);
    int getPozitieBancnota(int);
    void setSize(int);
    void setSuma(int);
    void increaseAparitie(int);
    void dealocateAparitii();
    void addBancnote(int);
    vector<int> getAparitii();
    vector<int> getBancnote();
    Tonomat& operator=(const Tonomat&);
};


#endif //LAB_9_10_TONOMAT_H
