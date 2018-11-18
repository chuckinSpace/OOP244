//
//  Product.hpp
//  MS03
//
//  Created by Carlos  Moyano on 24/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef Product_h
#define Product_h
#include <stdio.h>
#include <fstream>
#include "ErrorState.h"
#define taxes 1.13
#define max_sku_length 7
#define max_unit_length 10
#define max_name_length 75


namespace AMA {
    


    class Product {
        char type;
        char Sku[max_sku_length];
        char Unit[max_unit_length];
        char * product_name;
        int tax;
        int qty_on_hand;
        int qty_needed;
        double Price;
        bool taxable_status;
        ErrorState product_errorState;
    protected:
        void name(const char* nm);
      //  const char* name() const;
      //  double cost() const;
        void message(const char* msg);
        bool isclear() const;
    public:
        explicit Product(char _type = 'N');
        Product(const char* p_sku, const char* p_name, const char* p_desc, int p_qty_on_hand = 0, bool p_taxable_status = true, double p_price = 0.0, int p_qty_needed = 0 );
        Product(const Product& otherProduct);
        Product& operator=( const Product& otherProduct);
        ~Product();
        std::fstream& store(std::fstream& file, bool newLine=true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        bool operator == (const char* other_sku) const;
        double total_cost() const;
        void quantity(int _qty);
        const char * sku() const;
        const char * name() const;
        const char * unit() const;
        double price() const;
        double cost() const;
        bool taxed() const;
        bool isEmpty() const;
        int qtyNeeded() const;
        int quantity() const;
        bool operator>(const char* _sku)const;
        bool operator>(const Product& rhs)const;
        int operator+=(int rhs);
        
        
    };
    std::ostream& operator<<(std::ostream& out, const Product& rhs);
    std::istream& operator>>(std::istream& in, Product& rhs);
    double operator+=(double& price,const Product& rhs);
    
}

#endif /* Product_h */
