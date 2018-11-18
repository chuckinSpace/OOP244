//
//  Allocator.cpp
//  WS08
//
//  Created by Carlos  Moyano on 1/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include <stdio.h>
#include "SavingsAccount.h"

namespace sict {
    
    // define interest rate
    //
    double interest_rate = 0.05;
    
    
    
    // TODO: Allocator function
    //
    iAccount* CreateAccount(const char* account_Type, double initialBalance){
        if(account_Type[0] == 'S'){
            iAccount * ptr = nullptr;
            ptr = new SavingsAccount(initialBalance,interest_rate);
            return ptr;
            
        }else{
            return nullptr;
        }
    
    }
  
}
