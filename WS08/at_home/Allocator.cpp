//
//  Allocator.cpp
//  WS08
//
//  Created by Carlos  Moyano on 1/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include <stdio.h>
#include "SavingsAccount.h"
#include "ChequingAccount.h"

namespace sict {
    
    // define interest rate
    //
    double interest_rate = 0.05;
    
    
    
    // TODO: Allocator function
    //
    iAccount* CreateAccount(const char* account_Type, double initialBalance){
        Account * ptr = nullptr;
        if(account_Type[0] == 'S'){
            
            ptr = new SavingsAccount(initialBalance,interest_rate);
           
            
        }else if(account_Type[0] == 'C'){
            ptr = new ChequingAccount(initialBalance,TRANSACTION_FEE,MONTHLY_FEE);
           
        }
         return ptr;
    }
    
}
