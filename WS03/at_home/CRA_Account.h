#ifndef CRA_Account_h
#define CRA_Account_h

namespace sict {


	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;
 	const int max_yrs = 4;
  
	class CRA_Account {

	char family_name[max_name_length + 1];
	char given_name[max_name_length + 1];
	int SIN;
    int tax_rtn[max_yrs];
    double balance[max_yrs];
    int year;
        
    
            
        

	public:
	void set(const char*, const char*, int);
	bool isEmpty() const;
	void display() const;
    void set(int, double);
  //      CRA_Account();
	};
    
    
   

}

#endif /* CRA_Account_h */
