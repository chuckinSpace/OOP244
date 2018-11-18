#ifndef SICT_SAVINGSACCOUNT_H__
#define SICT_SAVINGSACCOUNT_H__

#include "Account.h"
#define max_name_lenght 9

namespace sict{
    
    class SavingsAccount: public Account {
    
       double interest_RateSavings;
       double getInterestRate() const ;
 
    
public:
    // TODO: constructor initializes balance and interest rate
        SavingsAccount(double,double);
    
    // TODO: perform month end transactions
        void monthEnd();
    
    // TODO: display inserts the account information into an ostream
        void display(std::ostream&) const;
        bool validateIntRate(double _interestRate) const;
        
        
};
}
#endif
