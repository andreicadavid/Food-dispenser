#include <iostream>
#include "UI.h"
#include "Tests.h"
int main() {
    RepoFile R("C:\\Faculta\\an1sem1\\Programare Orientata Obiect (POO)\\Proiecte\\Lab_9-10\\Produse.txt","C:\\Faculta\\an1sem1\\Programare Orientata Obiect (POO)\\Proiecte\\Lab_9-10\\Bancnote.txt");
    Service S(R);
    UI U(S);
    Tests T;
    T.testeRepo();
    U.menu();
}
