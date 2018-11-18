#include <iostream>
#include "Fraction.h"

using namespace std;

// TODO: continue the namespace
namespace sict {
    

// TODO: implement the default constructor
    Fraction::Fraction(){
        this->denominator= 0;
        this->numerator= 0;
    }
// TODO: implement the two-argument constructor
    Fraction::Fraction(int num, int den){
        if (num >=1 && den >=1){
            denominator = den;
            numerator = num;
            reduce();
        }else{
            denominator= 0;
            numerator= 0;
        }
    }
// TODO: implement the max query
    int Fraction::max () const{
        if (numerator > denominator){
            return numerator;
        }else{
            return denominator;
        }
    }
// TODO: implement the min query
    int Fraction::min () const{
        if (numerator > denominator){
            return denominator;
        }else{
            return numerator;
        }
    }
// gcd returns the greatest common divisor of num and denom
//
int Fraction::gcd() const {
    int mn = min();  // min of numerator and denominator
    int mx = max();  // max of numerator and denominator
    int g_c_d = 1;
    bool found = false;
    
    for (int x = mn; !found && x > 0; --x) { // from mn decrement until divisor found
        if (mx % x == 0 && mn % x == 0) {
            found = true;
            g_c_d = x;
        }
    }
    return g_c_d;
}
    
     // TODO: implement the reduce modifier
    void Fraction::reduce(){
        int gcd_res = gcd();  //saves the results of the gcd()
        numerator /= gcd_res;
        denominator /= gcd_res;
    }
     // TODO: implement the display query
    void Fraction::display() const{
        
        if(denominator != 1 && denominator != 0){ 
            cout << numerator << "/" << denominator;
        }else if (denominator == 1){
            cout << numerator;
        }else if ( denominator == 0 && numerator == 0){
            cout << "no fraction stored";
        }
    }
     // TODO: implement the isEmpty query
    bool Fraction::isEmpty() const{
        if(numerator == 0 && denominator == 0 ){
            return true;
        }else{
            return false;
        }
    }
     // TODO: implement the + operato
    Fraction Fraction::operator+(const Fraction& rhs) const{
        if (numerator != 0 && denominator !=0){
            int value1=0;
            int value2=0;
            
            Fraction temp;
            value1 = (this->numerator * rhs.denominator ); //+
            value2 = (this->denominator * rhs.numerator);
            temp.denominator=  (this->denominator * rhs.denominator);
            temp.numerator= (value1 + value2);
            
            return temp;
           
        }else{
            Fraction temp;
            
            return temp;
        }
        
       
     
    }
};

