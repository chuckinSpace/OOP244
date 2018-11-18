// OOP244 Workshop 8: Virtual Functions and Abstract Base Classes
// File: ChequingAccount.cpp
// Version: 2.0
// Date: 2017/12/11
// Author: Chris Szalwinski, based on previous work by Heidar Davoudi
// Description:
// This file implements the ChequingAccount class
///////////////////////////////////////////////////

#include "ChequingAccount.h"

using namespace std;

namespace sict {
    // constructor initializes balance and transaction fee
    //
    ChequingAccount::ChequingAccount(double _initial_account_balance, double _transaction_fee, double _month_end_fee) : Account(_initial_account_balance) {
        
        getTransfee(_transaction_fee);
        getMonthfee(_month_end_fee);
        this->balance(_initial_account_balance);
    }
    
    
    
    // credit (add) an amount to the account balance and charge fee
    // returns bool indicating whether money was credited
    //
    
    bool ChequingAccount::credit(double p) {
        if (Account::credit(p)) {
            Account::debit(TRANSACTION_FEE);
            return true;
        }
        return false;
    }
    
    
    // debit (subtract) an amount from the account balance and charge fee
    // returns bool indicating whether money was debited
    //
    
    bool ChequingAccount::debit(double p) {
        if (Account::debit(p)) {
            Account::debit(TRANSACTION_FEE);
            return true;
        }
        return false;
    }
    
    // monthEnd debits month end fee
    //
    void ChequingAccount::monthEnd(){
        Account::debit(MONTHLY_FEE);
        Account::debit(TRANSACTION_FEE);
    }
    
    
    // display inserts account information into ostream os
    //
    void ChequingAccount::display(std::ostream& ostr) const {
        ostr.setf(ios::fixed);
        ostr << setprecision(2) << "Account type: Chequing" << endl;
        ostr << "Balance: $" << balance() << endl;
        ostr << "Per Transaction Fee: " << TRANSACTION_FEE << endl;
        ostr << "Monthly Fee: " << MONTHLY_FEE << endl;
        ostr.unsetf(ios::fixed);
    }
    void ChequingAccount::getTransfee(double _transaction_fee) {
        if (_transaction_fee > 0) {
            c_transaction = _transaction_fee;
        }
        else {
            c_transaction = 0.0;
        }
    }
    //get month end fee value or set0
    void ChequingAccount::getMonthfee(double _monthly_fee) {
        
        if (_monthly_fee > 0) {
            c_monthendfee = _monthly_fee;
        }
        else {
            c_monthendfee = 0.0;
        }
    }
}
