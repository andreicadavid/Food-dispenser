//
// Created by User on 16.05.2023.
//
#pragma once
#include <stdexcept>
#include <string>
#include <cstring>

using namespace std;

class Validator
{
public:
    Validator() = default;;
    ~Validator() = default;;
    static void validare_adaugare(int cod, char* nume, float pret) {

        if (cod < 0)
            throw std::invalid_argument("Codul nu poate fi negativ");
        else if(strcmp(nume,"")==0 && nume != nullptr)
            throw std::invalid_argument("Numele nu poate fi gol");
        else if(pret < 0)
            throw std::invalid_argument("Pretul nu poate fi negativ");
    }
    static void validare_update(int cod, char* nume, float pret) {

        if (cod < 0)
            throw std::invalid_argument("Codul nu poate fi negativ");
        else if(strcmp(nume,"")==0 && nume != nullptr)
            throw std::invalid_argument("Numele nu poate fi gol");
        else if(pret < 0)
            throw std::invalid_argument("Pretul nu poate fi negativ");
    }
    static void validare_bancnota(int nr){
        if (nr < 0)
            throw std::invalid_argument("Numarul de bancnote nu poate fi negativ");
    }
};