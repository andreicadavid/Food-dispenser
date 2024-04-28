//
// Created by andre_pzeda4p on 5/9/2023.
//

#ifndef LAB_9_10_TONOMAT_H
#define LAB_9_10_TONOMAT_H
#include <vector>
using namespace std;

class TonomatMaiBun {
private:
    vector<int> bancnote;
public:
    TonomatMaiBun();
    explicit TonomatMaiBun(vector<int>);
    TonomatMaiBun(TonomatMaiBun&);
    ~TonomatMaiBun();
    int getAparitie(int);
    int getPozitieBancnota(int);
    int getBancnota(int);
    void addBancnote(int,int);
    vector<int> getBancnote();
    void setBancnote(vector<int>&);
    TonomatMaiBun& operator=(const TonomatMaiBun&);
};


#endif //LAB_9_10_TONOMAT_H
