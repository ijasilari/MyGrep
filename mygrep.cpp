#include "Appi.h"
using namespace std;

Appi appi = Appi();

int main(int argc, char* argv[])
{
    if (argv[1] != NULL) {
        appi.argumentti1 = argv[1];

        appi.argumentti(appi.argumentti1);
    }

    if (appi.argumentti1 == "") // inkrementti 1
    { 
        appi.kysymykset();
        appi.lauseesta_etsiminen();
    }
    else if (appi.bl[1] || appi.bl[0] || appi.bl[2] || appi.bl[3]) { // o, r, i ja l komento
        appi.tiedostosta_lukeminen(argv[2], argv[3]);
    }
    else { // inkrementti 2
        appi.tiedostosta_lukeminen(appi.argumentti1, argv[2]);
    }

return 0;
}
