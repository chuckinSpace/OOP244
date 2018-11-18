//
//  Perishable.h
//  MS05
//
//  Created by Carlos  Moyano on 10/4/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef Perishable_h
#define Perishable_h


#include "Product.h"
#include "Date.h"
#include <fstream>
#include <iostream>




namespace AMA {
    
    class Perishable : public Product{
        Date expiry_date;
    public:
        Perishable();
        void expiry(const Date& date);
        std::fstream& store(std::fstream& file, bool newLine = true) const;
        std::fstream& load(std::fstream& file);
        std::ostream& write(std::ostream& os, bool linear) const;
        std::istream& read(std::istream& is);
        const Date& expiry() const;
        void setYear(int _year);
        
        
    };
}



#endif /* Perishable_h */
