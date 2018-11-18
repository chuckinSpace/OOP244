//
//  Kingdom.cpp
//  asig2
//
//  Created by Carlos  Moyano on 4/2/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//


#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict {
    
    void display(const Kingdom &kingdom) {
        
        cout << kingdom.m_name << ", population " << kingdom.m_population << endl; //index
 
    }
    void display(const Kingdom kingdom[], int SIZE){
        int total=0;
        for (int i = 0 ; i < SIZE; i++){
            total += kingdom[i].m_population;
        }
        cout << "------------------------------"<< endl;
        cout << "Kingdoms of SICT"<< endl;
        cout << "------------------------------"<< endl;
        for (int i = 0 ; i < SIZE; i++){
            cout<<i+1<<". ";
	    display(kingdom[i]);
        }
        cout << "------------------------------"<< endl;
        cout << "Total population of SICT: " << total << endl;
        cout << "------------------------------"<< endl;
        }
    
}
