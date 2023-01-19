#include "Appi.h"

void Appi::argumentti(std::string argumentti1) {
    if (argumentti1[0] == '-' && argumentti1[1] == 'o') {
        for (int i = 2; i < argumentti1.size(); i++) {
            if (argumentti1[i] == 'o') {
                bl[0] = true;
            }
            else if (argumentti1[i] == 'l') {
                bl[1] = true;
            }
            else if (argumentti1[i] == 'r') {
                bl[2] = true;
            }
            else if (argumentti1[i] == 'i')
                bl[3] = true;
        }
    }
}

void Appi::kysymykset()
{
    std::cout << "Give a string from which to search for: ";
    std::getline(std::cin, teksti);

    std::cout << "Give search string: ";
    std::getline(std::cin, haku);
}

void Appi::lauseesta_etsiminen()
{
    sijainti = -1;

    do {
        sijainti = teksti.find(haku, sijainti + 1);

        if (sijainti != -1) {
            hh = true;
            std::cout << "\"" << haku << "\"" << " found in " << "\"" << teksti << "\"" << " in position " << sijainti << std::endl;
        }
    } while (sijainti != -1);

    if (!hh)
        std::cout << "\"" << haku << "\"" << " NOT found in " << "\"" << teksti << "\"" << std::endl;
}

void Appi::tiedostosta_lukeminen(std::string arg1,std::string arg2)
{
    alHaku = arg1;
    tiedosto.open(arg2, std::ios::in);
    if (tiedosto.is_open())
    {
       

        while (getline(tiedosto, line)) {
            line1 = line;
            if (bl[3])
            {
                // 'i' toiminto
                std::for_each(arg1.begin(), arg1.end(), [](char& c) {
                    c = ::tolower(c);
                    });
                std::for_each(line.begin(), line.end(), [](char& c) {
                    c = ::tolower(c);
                    });
            }

            sijainti = line.find(arg1);
            ++rivinumero;

            if (bl[2] == false) {
                if (sijainti != -1) {
                    ++rivimaara;

                    if (bl[1]) {     // 'l' linenumbering tarkistus
                        std::cout << rivinumero << ": ";
                    }
                    std::cout << line1 << std::endl;
                }

            }else if (bl[2]) {
                if (sijainti == -1) {
                    ++rivimaara;

                    if (bl[1]) {     // 'l' linenumbering tarkistus
                        std::cout << rivinumero << ": ";
                    }
                    std::cout << line1 << std::endl;
                }
            }
        }
        if (bl[0]) // 'o' occurance tarkistus
            std::cout << "\nOccurences of lines ";
            if (bl[2])
                std::cout << "NOT ";
            std::cout << "containing \"" << alHaku << "\": " << rivimaara;
    }
    else { // Poikkeuskäsittely
        try {
            if (!tiedosto.is_open())
                throw "kissa";
        }
        catch (const char* error) {
            error = "kissa";
            std::cout << "File could not be opened.";
        }
    }

}
