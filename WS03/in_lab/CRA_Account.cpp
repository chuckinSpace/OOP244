

#include <iostream>
#include <cstring>
#include "CRA_Account.h"

using namespace std;

namespace sict {


	void CRA_Account::set(const char * famn, const char * gname, int sin) {
		if (sin >= min_sin && sin <= max_sin) {
			strncpy(family_name, famn, (max_name_length + 1));
			family_name[max_name_length] = '\0';
			strncpy(given_name, gname, (max_name_length + 1));
			given_name[max_name_length] = '\0';
			SIN = sin;

		}
		else {
			family_name[0] = '\0';
			given_name[0] = '\0';
			SIN = '\0';
		}
	}
	bool CRA_Account::isEmpty() const {
		return SIN == '\0';
	}
	void CRA_Account::display() const {
		if (isEmpty()== 0) {
			cout << "Family Name: " << family_name << endl;
			cout << "Given Name : " << given_name << endl;
			cout << "CRA Account: " << SIN << endl;
		}
		else {
			cout << "Account is empty!" << endl;
		}


	}
}
