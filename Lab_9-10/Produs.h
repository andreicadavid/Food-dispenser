//
// Created by andre_pzeda4p on 5/7/2023.
//

#ifndef LAB_9_10_PRODUS_H
#define LAB_9_10_PRODUS_H


class Produs {
private:
    int cod;
    char* nume;
    float pret;
public:
    Produs();
    Produs(int,const char*,float);
    Produs(const Produs&);
    int get_cod();
    char* get_nume();
    float get_pret();
    void set_cod(int);
    void set_nume(char*);
    void set_pret(float);
    bool operator==(Produs&);
    Produs& operator=(const Produs&);
    ~Produs();
};


#endif //LAB_9_10_PRODUS_H
