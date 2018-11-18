//
//  Fractions.cpp
//  WS05
//
//  Created by Carlos  Moyano on 17/2/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//


// TODO: header file guard
#ifndef _FRACTION_H
#define _FRACTION_H
// TODO: create namespace
namespace sict {

// TODO: define the Fraction class
class Fraction {
    // TODO: declare instance variables
    int numerator;
    int denominator;
    
    // TODO: declare private member functions
    int max () const;
    int min () const;
    void reduce();
    
public:
    // TODO: declare public member functions
    Fraction();
    Fraction(int numerator, int denominator);
    int gcd() const;
    bool isEmpty() const;
    void display() const;
    
    
    // TODO: declare the + operator overload 
    Fraction operator+(const Fraction& rhs) const;
    Fraction operator*(const Fraction& rhs) const;
    bool operator==(const Fraction& rhs) const;
    bool operator!=(const Fraction& rhs) const;
    Fraction operator+=(const Fraction& rhs);
    
    
};
}


#endif
