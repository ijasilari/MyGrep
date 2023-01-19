#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <algorithm>

class Appi
{
private:
    std::string teksti{}, haku{};
    std::size_t sijainti{};
    int rivinumero = 0, rivimaara = 0;
    std::fstream tiedosto;
    std::string line, line1;
    bool hh = false;
    std::string alHaku{};

public:
    void kysymykset();
    void lauseesta_etsiminen();
    void tiedostosta_lukeminen(std::string, std::string);
    void linenumbering(std::string, std::string);
    void occurences(std::string);
    void argumentti(std::string);
    void reverse(std::string, std::string);
    
    bool bl[7]{}; //bl[0] = o, bl[1] = l, bl[2] = r ja bl[3] = i
    std::string argumentti1;
};