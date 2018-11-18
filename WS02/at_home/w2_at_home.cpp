//
//  main.cpp
//  asig2
//
//  Created by Carlos  Moyano on 4/2/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include <iostream>
#include "Kingdom.h"

using namespace std;
using namespace sict;

void read(Kingdom&);

int main() {
    int count = 0; // the number of kingdoms in the array
    
    // TODO: declare the pKingdom pointer here (don't forget to initialize it)
    Kingdom * pKingdom = nullptr;
    Kingdom * pKingdom2 = nullptr;
    
    cout << "==========\n"
    << "Input data\n"
    << "==========\n"
    << "Enter the number of Kingdoms: ";
    cin >> count;
    cin.ignore();
    
    if (count < 1) return 1;
    
    // TODO: allocate dynamic memory here for the pKingdom pointer
    pKingdom = new Kingdom[count];
    for (int i = 0; i < count; ++i) {
        cout << "Kingdom #" << i + 1 << ": " << endl;
        // TODO: add code to accept user input for Kingdom i
        read(pKingdom[i]);
    }
    cout << "==========" << endl << endl;
    
    // testing that "display(...)" works
    cout << "------------------------------" << endl
    << "The 1st Kingdom entered is" << endl
    << "------------------------------" << endl;
    display(pKingdom[0]);
    
    pKingdom2 = new Kingdom[count+1];
    
    for(int i = 0 ; i < count; i++){
        pKingdom2[i]  = pKingdom[i];
    }
    delete [] pKingdom;
    
   
    cout << "------------------------------" << endl << endl;
    cout << "==========\n"
         << "Input data\n"
         << "==========\n"
         << "Kingdom #" << count + 1<< ": " << endl;
    //TODO accept input for the new element in the array
    read(pKingdom2[count]);
    count++;
    cout << "==========\n" << endl;
    
    // testing that the overload of "display(...)" works
    display(pKingdom2, count);
    cout << endl;
    
    // TODO: deallocate the dynamic memory here
    delete [] pKingdom2;
    return 0;
}

// read accepts data for a Kingdom from standard input
//
void read(Kingdom& kingdom) {
    
    cout << "Enter the name of the Kingdom: ";
    cin.get(kingdom.m_name, 32, '\n');
    cin.ignore(2000, '\n');
    cout << "Enter the number of people living in " << kingdom.m_name << ": ";
    cin >> kingdom.m_population;
    cin.ignore(2000, '\n');
}
