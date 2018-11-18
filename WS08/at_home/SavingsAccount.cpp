//
//  SavingsAccount.cpp
//  WS08
//
//  Created by Carlos  Moyano on 1/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include <iomanip>
#include <stdio.h>
#include <string.h>
#include "SavingsAccount.h"

namespace sict {
    
    SavingsAccount::SavingsAccount(double _initialBalance ,double _interestRate): Account(_initialBalance) {
        if(validateBalance(_interestRate)){
            interest_RateSavings = _interestRate;
            
        }else{
            setEmpty();
        }
    }
    
    
    
    
    bool SavingsAccount::validateIntRate(double _interestRate) const{
        return (_interestRate > 0);
    }
    
    void SavingsAccount::monthEnd(){
        double interestGained = 0 ;
        interestGained = ( balance() * getInterestRate() );
        credit(interestGained);
        
    }
    
    double SavingsAccount::getInterestRate() const{
        return interest_RateSavings;
    }
    
    
    void SavingsAccount::display(std::ostream& out) const{
        out << "Account type: " << "Savings" << std::endl;
        out << "Balance: $" << std::setw(4) << std::setprecision(2) << std::fixed << balance()  << std::endl;
        out << "Interest Rate (%): " << std::setw(1) << std::setprecision(2) << std::fixed << interest_RateSavings * 100 << std::endl;
    }
    
    
}
