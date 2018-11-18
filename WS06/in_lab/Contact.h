//
//  Contact.hpp
//  Ws06
//
//  Created by Carlos  Moyano on 11/3/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef Contact_hpp
#define Contact_hpp
#define SIZE 20



using namespace std;

namespace sict {
    
    
    class Contact{
        
        char name[SIZE];
        long long * phoneNumber;
        int validnumbers;
      
        
        public:
        
        Contact(); // default contructor
        Contact(const char* nm, const long long* pnumber, int nopnumbers);
        ~Contact();        
        bool isEmpty() const;
        void display() const;
        bool nvalid(const long long numval);
        int getCountryCode(const long long * num)const;
        int getAreaCode(const long long * num)const;
        int getNumber(const long long * num)const;
       
        
        
    };
    
    
    
    
}

#endif /* Contact_hpp */
