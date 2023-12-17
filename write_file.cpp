#include <iostream>
#include <fstream>
#include "Graph.h"
#include "customer.h"
#include "admin.h"
using namespace std;

int main(){
    Admin A[2];
    A[0].add("Helena", "helena@gmail.com", "123", "helenapw");
    A[1].add("Aiko", "aiko@gmail.com", "456", "aikopw");
    fstream f1;
    f1.open("admins.txt", ios::out);
    for (int i = 0; i <= 1; i++) {
        f1.write((char*)&A[i], sizeof(A[i]));
    }
    f1.close();

    Agent G[3];
    G[0].add("Ana", "ana@gmail.com", "321");
    G[1].add("Rina", "rina@gmail.com", "654");
    G[2].add("Adi", "adi@gmail.com", "987");
    fstream f2("agents.txt", ios::out);
    for (int i = 0; i <= 1; i++) {
        f2.write((char*)&G[i], sizeof(G[i]));
    }
    f2.close();

    Edge E[100];

    E[0].initialize("New Delhi", "Dubai", 7500, 3.35);
    E[1].initialize("New Delhi", "Mumbai", 1400, 2.05);
    E[2].initialize("New Delhi", "Bangkok", 6300, 4.00);
    E[3].initialize("New Delhi", "Moscow", 20000, 14.00);
    E[4].initialize("New Delhi", "London", 25500, 9.25);

    E[5].initialize("Mumbai", "Hong Kong", 17000, 12.55);
    E[6].initialize("Mumbai", "Cape Town", 40000, 18.10);
    E[7].initialize("Mumbai", "London", 24500, 9.15);

    E[8].initialize("Dubai", "Cairo", 13000, 6.00);
    E[9].initialize("Dubai", "New York", 61000, 18.25);

    E[10].initialize("Cairo", "London", 13000, 5.20);
    E[11].initialize("Moscow", "Stockholm", 6900, 7.0);
    E[12].initialize("Stockholm", "London", 3500, 2.40);
    E[13].initialize("Stockholm", "Berlin", 5300, 4.1);

    E[14].initialize("Hong Kong", "Tokyo", 9350, 3.55);
    E[15].initialize("Bangkok", "Singapore", 5500, 2.30);
    E[16].initialize("Singapore", "Melbourne", 47000, 7.25);
    E[17].initialize("Singapore", "Sydney", 19600, 7.45);

    E[18].initialize("Sydney", "Melbourne", 3500, 1.30);

    E[19].initialize("Tokyo", "Sydney", 66000, 9.5);
    E[20].initialize("Tokyo", "Seoul", 9200, 2.40);
    E[21].initialize("Tokyo", "Toronto", 32350, 12.50);
    E[22].initialize("Tokyo", "New York", 29300, 18.10);
    E[23].initialize("Tokyo", "Los Angeles", 25000, 18.30);
    E[24].initialize("Tokyo", "San Francisco", 25000, 18.30);

    E[25].initialize("Toronto", "Los Angeles", 8500, 5.14);
    E[26].initialize("Toronto", "San Francisco", 8000, 5.40);
    E[27].initialize("Toronto", "Chicago", 7700, 1.50);
    E[28].initialize("Toronto", "Washington D.C.", 9100, 1.27);

    E[29].initialize("London", "Rio de Janeiro", 19200, 15.47);
    E[30].initialize("London", "Washington D.C.", 21000, 11.00);
    E[31].initialize("London", "New York", 10000, 8.00);
    E[32].initialize("London", "Paris", 2800, 7.15);
    E[33].initialize("London", "Rome", 1750, 2.55);
    E[34].initialize("London", "Berlin", 1400, 1.50);

    E[35].initialize("Rome", "Cape Town", 19800, 15.20);
    E[36].initialize("Rome", "Paris", 1000, 2.15);
    E[37].initialize("Rome", "Berlin", 4400, 3.00);

    E[38].initialize("Paris", "Berlin", 3500, 3.00);
    E[39].initialize("Paris", "Cape Town", 21300, 16.00);
    E[40].initialize("Paris", "New York", 13500, 11.00);
    E[41].initialize("Paris", "Washington D.C.", 15500, 16.00);

    E[42].initialize("Cape Town", "Rio de Janeiro", 52500, 41.00);
    E[43].initialize("Cape Town", "Washington D.C.", 27400, 24.00);
    E[44].initialize("Cape Town", "New York", 27800, 22.15);
    E[45].initialize("Cape Town", "Dubai", 22000, 24.00);

    E[46].initialize("Rio de Janeiro", "Santiago", 7500, 5.40);
    E[47].initialize("Rio de Janeiro", "Spain", 16500, 15.00);

    E[48].initialize("Santiago", "Peru", 4400, 3.49);
    E[49].initialize("Santiago", "Mexico City", 1700, 9.45);

    E[50].initialize("Spain", "Peru", 19900, 12.00);
    E[51].initialize("Spain", "London", 3700, 2.25);
    E[52].initialize("Spain", "Berlin", 1000, 4.00);
    E[53].initialize("Spain", "Paris", 2500, 2.00);
    E[54].initialize("Spain", "Rome", 1250, 2.55);
    E[55].initialize("Spain", "Dubai", 14450, 24.00);
    E[56].initialize("Spain", "New Delhi", 17800, 12.30);
    E[57].initialize("Spain", "New York", 10500, 10.00);

    E[58].initialize("Mexico City", "New York", 11000, 5.15);
    E[59].initialize("Mexico City", "Los Angeles", 7300, 4.20);
    E[60].initialize("Mexico City", "Washington D.C.", 19300, 4.10);
    E[61].initialize("Mexico City", "Chicago", 8700, 4.10);
    E[62].initialize("Mexico City", "Peru", 8250, 8.00);
    E[63].initialize("Mexico City", "Havana", 12750, 9.00);

    E[64].initialize("Peru", "Miami", 6500, 7.00);
    E[65].initialize("Peru", "Washington D.C.", 7500, 10.00);
    E[66].initialize("Peru", "Havana", 21000, 7.40);
    E[67].initialize("Peru", "Los Angeles", 20000, 9.00);
    E[68].initialize("Peru", "San Francisco", 18000, 14.00);

    E[69].initialize("New York", "New Delhi", 26000, 14.00);
    E[70].initialize("New York", "Chicago", 2500, 2.00);
    E[71].initialize("New York", "Washington D.C.", 5500, 1.15);
    E[72].initialize("New York", "San Francisco", 6400, 6.30);
    E[73].initialize("New York", "Los Angeles", 4200, 7.00);
    E[74].initialize("New York", "Miami", 2500, 2.55);
    E[75].initialize("New York", "Toronto", 5200, 1.40);

    E[76].initialize("Chicago", "New Delhi", 26500, 16.00);
    E[77].initialize("Chicago", "Los Angeles", 2750, 4.30);
    E[78].initialize("Chicago", "San Francisco", 4500, 4.50);
    E[79].initialize("Chicago", "Washington D.C.", 2250, 1.52);

    E[80].initialize("Los Angeles", "Washington D.C.", 4000, 4.45);
    E[81].initialize("Los Angeles", "San Francisco", 2600, 1.20);
    E[82].initialize("Los Angeles", "Miami", 3750, 4.40);
    E[83].initialize("Los Angeles", "New Delhi", 24000, 24.00);
    E[84].initialize("Los Angeles", "Dubai", 31500, 15.55);

    E[85].initialize("Los Angeles", "San Francisco", 7000, 8.00);

    fstream f3;
    f3.open("places.txt", ios::out);

    for (int i = 0; i <= 85; i++) {
        f3.write((char*)&E[i], sizeof(E[i]));
    }
    f3.close();

    return 0;
}