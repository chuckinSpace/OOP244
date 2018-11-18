//
//  Account.cpp
//  WS08
//
//  Created by Carlos  Moyano on 1/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include "Account.h"
namespace sict{

    double Account::balance() const{
        return current_balance;
    }
    
    Account::Account(){
        setEmpty();
    }
    
    Account::Account(double _balance){
        if(validateBalance(_balance)){
            current_balance = _balance;
        }else{
            setEmpty();
        }
    }
    
    void Account::setEmpty(){
        current_balance = 0.0;
    }
    
    bool Account::validateBalance(double _balance) const{
        return (_balance >= 0);
     }
    
    bool Account::credit(double _credit){
        if(validateBalance(_credit)){
            
            current_balance += _credit;
            return true;
        }else{
            return false;
        }
    }


    bool Account::debit(double _debit){
        if(validateBalance(_debit)){
            current_balance -= _debit;
            return true;
        }else{
            return false;
        }
    }


}
