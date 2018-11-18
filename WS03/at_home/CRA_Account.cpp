

#include <iostream>
#include <cstring>
#include <string>
#include <iomanip>
#include "CRA_Account.h"

using namespace std;

namespace sict {

  void CRA_Account::set(const char * famn, const char * gname, int sin) {
		
     //Declaring variables to check every digit on SIN
        int digit1=0;
        int digit2=0;
        int digit3=0;
        int digit4=0;
        int digit5=0;
        int digit6=0;
        int digit7=0;
        int digit8=0;
        int checkdigit=0;
        int sum1=0;
        int sum2=0;
        int sum3=0;
        int sum4=0;
        int temp1=0;
        int temp2=0;
        int temp3=0;
        int temp4=0;
        int temp5=0;
        int temp6=0;
        int tempsum=0;
        int tempsum2=0;
        int totalsum=0;
        int difference=0;
        int newnumber=0;
      
      //checking every digit of SIN
      
        checkdigit = sin % 10;
        digit8 = sin / 10  % 10;
        digit7 = sin / 100  % 10;
        digit6 = sin / 1000  % 10;
        digit5 = sin / 10000  % 10;
        digit4 = sin / 100000  % 10;
        digit3 = sin / 1000000  % 10;
        digit2 = sin / 10000000  % 10;
        digit1 = sin / 100000000  % 10;
        
        sum1 = (digit2 + digit2);
        sum2 = (digit4 + digit4);
        sum3 = (digit6 + digit6);
        sum4 = (digit8 + digit8);
        
        temp2 = sum1 % 10;
        temp1 = sum1 / 10  % 10;
        
        temp4 = sum3 % 10;
        temp3 = sum3 / 10  % 10;
        
        temp6 = sum4 % 10;
        temp5 = sum4 / 10  % 10;
        
        tempsum = temp1 + temp2 + temp3 + sum2 + temp4 + temp5 + temp6;
        tempsum2 = digit1 + digit3 + digit5 + digit7 ;
        totalsum = tempsum + tempsum2;
        
        if (totalsum % 10){
            newnumber = totalsum + (10 - totalsum % 10);
        }
        // the differnce between the next number divisible by 10 and the check digit
        difference = newnumber - totalsum;
        // checking if the diferrence is equals to the check digit
        if(checkdigit == difference){
        
            if (sin >= min_sin && sin <= max_sin) {
                
                strncpy(family_name, famn, (max_name_length + 1));
                family_name[max_name_length] = '\0';
                strncpy(given_name, gname, (max_name_length + 1));
                given_name[max_name_length] = '\0';
                SIN = sin;
                year=0;

            }
            // assigning values to empty state
            else {
                family_name[0] = '\0';
                given_name[0] = '\0';
                SIN = '\0';
            }
        
      
        }
   
        
        
        
	}
    
    void CRA_Account::set(int yr, double bal){
     
            if(SIN!=0 && year < max_yrs)
            {
            tax_rtn[year] = yr;
            balance[year] = bal;
            year++;
            }
    }
	bool CRA_Account::isEmpty() const {
       
            bool aux = false;
            if(SIN != 0 && family_name[0] != '\0' && given_name[0] != '\0' )
            {
                aux = false;
            }
            else
            {
                aux = true;
            }
                return aux;
            }
	void CRA_Account::display() const {
		
        
            if (isEmpty() == 0) {
            
                cout << "Family Name: " << family_name << endl;
                cout << "Given Name : " << given_name << endl;
                cout << "CRA Account: " << SIN << endl;
                
            for(int i = 0 ; i < max_yrs; i++ ){
              
                 
                if(balance[i] > 2){
                    cout << "Year "<<"("<< tax_rtn[i] <<")" <<" balance owing: " <<setprecision(2) << fixed << balance[i] <<endl;
                }else if(balance[i] < -2){
                    cout << "Year "<<"("<< tax_rtn[i] <<")" <<" refund due: "  <<setprecision(2) << fixed << (-1)*balance[i] <<endl;
                }else {
                    cout << "Year "<<"("<< tax_rtn[i] <<")" <<" No balance owing or refund due!" <<endl;
                }
                 
             }
             
            }else {
                cout << "Account is empty!" << endl;
        }
    }
}
