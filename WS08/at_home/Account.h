//
//  Account.hpp
//  WS08
//
//  Created by Carlos  Moyano on 1/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef SICT_ACCOUNT_H__
#define SICT_ACCOUNT_H__
#include "iAccount.h"
#include <stdio.h>
namespace sict {
    const double INTEREST_RATE = 0.05;
    const double TRANSACTION_FEE = 0.50;
    const double MONTHLY_FEE = 2.00;
    class Account: public iAccount
    {
        
        double current_balance;
        
    protected:
        double balance() const;
        void balance( const double);
    public:
        
        Account(double);
        Account();
        
        
        bool credit(double);
        bool debit(double);
        void setEmpty();
        bool validateBalance(double) const;
    };
    
    
}

#endif /* Account_h
*/
