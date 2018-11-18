//
//  Product.cpp
//  MS03
//
//  Created by Carlos  Moyano on 24/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#include "Product.h"
#include <iostream>
#include <cstring>
#include <iomanip>



namespace AMA {
    
    // default constructor
    
    Product::Product(char _type){
        type = _type;
        Sku[0] = '\0';
        Unit[0] = '\0';
        product_name = nullptr;
        tax = taxes;
        qty_on_hand = 0;
        Price = 0.0;
        taxable_status = true;
        // product_errorState = 0;
        
    }
    // 7 param contructor
    Product::Product(const char* p_sku, const char* p_name, const char* p_unit, int p_qty_on_hand, bool p_taxable_status, double p_price, int p_qty_needed){
        
        strncpy(Sku,p_sku,max_sku_length);
        name(p_name);
        strncpy(Unit,p_unit,max_unit_length);
        qty_on_hand = p_qty_on_hand;
        taxable_status = p_taxable_status;
        Price = p_price;
        qty_needed = p_qty_needed;
        
        
        
        
    }
    // copy contructor, copy rhs Product object to curretn object
    Product::Product( const Product& otherProduct){
        
        *this = otherProduct;
      
    }
    // overloading operator = copying rhs to lhs
    Product& Product::operator=( const Product& otherProduct){
        if(this != &otherProduct){
            
            strncpy(Sku,otherProduct.Sku,max_sku_length);
            name(otherProduct.product_name);
            strncpy(Unit,otherProduct.Unit,max_unit_length);
            qty_on_hand = otherProduct.qty_on_hand;
            taxable_status = otherProduct.taxable_status;
            Price = otherProduct.Price;
            qty_needed = otherProduct.qty_needed;
        }
        return *this;
    }
    // destructor
    Product::~Product(){
        delete [] product_name;
    }
    // allocating dynamic memory for name and assigning it to the call data member
    void Product::name(const char* nm){
        if(nm == nullptr){
            delete [] product_name;
        }else{
            product_name = nullptr;
            product_name = new char [max_name_length + 1 ];
            strncpy(product_name,nm,max_name_length);
        }
        
       
    }
    
 // return produt name if not nullptr
  const char* Product::name() const{
        if(product_name == nullptr){
            return nullptr;
        }else{
            return product_name;
        }
        
    }
  
    double Product::cost() const{
        if(taxable_status){
            return (Price * taxes);
        }else{
            return Price;
        }
        
    }
   void Product::message(const char* msg){
       product_errorState.message(msg);
    }
   
    bool Product::isclear() const{
        return !product_errorState.isClear();
    }
    // insert object attributes to file, in a comma separated fields
    std::fstream& Product::store(std::fstream& file, bool newLine) const{
        file << type << "," << Sku << "," << product_name << "," << Price << "," <<     qty_on_hand << "," << Unit << "," << qty_needed;
        if(newLine){
            file << std::endl;
        }
        return file;
    }
    std::fstream& Product::load(std::fstream& file){
        file >> type >> Sku >> product_name >>  Price >> qty_on_hand >>  Unit >>  qty_needed;
        Product temp;
        file >> temp;
        
        return file;
        
        
    }
    std::ostream& Product::write(std::ostream& os, bool linear) const{
        if(linear){
            os  << std::setw(max_sku_length) <<std::left                << sku()          << "|"
                << std::setw(20)                                        << name() << "|"  << std:: right
                << std::setw(7)  << std::setprecision(2) << std::fixed  << cost()         << "|"
           
                << std::setw(4)                                         << quantity()     << "|"
                << std::setw(10) << std::left                           << unit()         << "|" << std:: right
                << std::setw(4)                                         << qtyNeeded()    << "|";
           
        }else{
            os  << "Sku: "                  <<sku()             << std::endl
                << "Name (no spaces): "     <<name()            << std::endl
                << "Price: "                <<price()           << std::endl;
            if(taxed()){
                os << "Price after tax: "   <<total_cost()      << std::endl;
            }else{
                os << "N/A"          << std::endl;
            }
                os << "Quantity on hand: "  << quantity()       << std::endl
                   << "Quantity needed: "   << qtyNeeded()      << std::endl;
        }
        return os;
    }
    std::istream& Product::read(std::istream& is){
        
        int counter= 0;
        std::cout << " Sku: ";
        
        if(!is.fail()){
            is >> Sku;
            counter++;
        }else{
            return is;
        }
            
        std::cout << " Name (no spaces): ";
        if(!is.fail()){
            is >> product_name;
            counter++;
           
        }else{
            return is;
        }
        
       
        
        std::cout << " Unit: ";
        if(!is.fail()){
            is >> Unit;
            counter++;
        }else{
            return is;
        }
        
        
        std::cout << " Taxed? (y/n): ";
        char input;
        is >> input;
        if(input == 'y' ||input == 'Y' ||input == 'N' ||input == 'n'){
            if(!is.fail()){
                if(input == 'y' ||input == 'Y'){
                    taxable_status = true;
                }else{
                     taxable_status = false;
                }
                counter++;
            }else{
                is.setstate(std::ios::failbit);
                message("Only (Y)es or (N)o are acceptable");
            }
        }else{
           
            return is;
        }
        
        std::cout << " Price: ";
        if(!is.fail()){
            double temp;
            is >> temp;
            if (temp > 0){
                Price = temp;
                counter++;
            }else{
                message( "Invalid Price Entry");
            }
            
           
        }else{
            
            return is;
        }
       
        
        std::cout << " Quantity on hand: ";
        if(!is.fail()){
            int temp;
            is >> temp;
            if (temp > 0){
                qty_on_hand = temp;
                counter++;
            }else{
                message( "Invalid Quantity On Hand Entry");
            }
            
            
        }else{
            
            return is;
        }
        
       
        
        std::cout << " Quantity needed: ";
        if(!is.fail()){
            int temp;
            is >> temp;
            if (temp > 0){
                qty_needed = temp;
                counter++;
            }else{
                message( "Invalid Quantity Needed Entry");
            }
            
            
        }else{
            
            return is;
        }
        if (counter == 7){
            
        }
       Product temp(Sku, product_name, Unit, qty_on_hand, taxable_status, Price, qty_needed);
        
        
        *this = temp;
        return is;
    }
    bool Product::operator == (const char* other_sku) const{
        return (strcmp(Sku,other_sku)==0);
    }
    double Product::total_cost() const{
        return qty_on_hand * cost();
    }
    void Product::quantity(int neo_qty){
        qty_on_hand = neo_qty;
    }
    bool Product::isEmpty()const{
        return product_name == nullptr;
    }
    int Product::qtyNeeded() const{
        return qty_needed;
    }
    int Product::quantity() const{
        return qty_on_hand;
    }
    bool Product::operator>(const char* _sku)const{
        return Sku > _sku;
    }
    bool Product::operator>(const Product& anotherProductName)const{
        return product_name > anotherProductName.product_name;
    }
    int Product::operator+=(int addQty){
        if(addQty > 0){
            qty_on_hand += addQty;
            return qty_on_hand;
        }else{
            return qty_on_hand;
        }
        
    }

    const char * Product::sku() const{
        return Sku;
    }
  
    const char* Product::unit() const{
        return Unit;
    }
    bool Product::taxed() const{
        return taxable_status;
    }
    double Product::price() const{
        return Price;
    }
    std::ostream& operator<<(std::ostream& out, const Product& rhs){
        return rhs.write(out, true);
    }
    std::istream& operator>>(std::istream& in, Product& rhs){
        return rhs.read(in);
    }
    double operator+=(double& addPrice,const Product& anotherProduct){
        double subtotal = anotherProduct.total_cost();
        subtotal += addPrice;
        
        return subtotal;
    }

}
