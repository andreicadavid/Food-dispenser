//
// Created by andre_pzeda4p on 5/8/2023.
//

#ifndef LAB_9_10_UI_H
#define LAB_9_10_UI_H
#include "Service.h"
#include "exceptii.h"

class UI {
private:
    Service S;
public:
    UI();
    explicit UI(Service&);
    UI(UI&);
    ~UI();
    void addElemU();
    void updateElemU();
    void deleteElemU();
    void addBancnota();
    void printAll();
    void printAllBancnote();
    void BuyU();
    void findElem();
    static void printMenu();
    void menu();
    UI& operator=(UI&);
};


#endif //LAB_9_10_UI_H
