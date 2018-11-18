
//
//  CRA_Account.h
//  LAB3
//
//  Created by Carlos  Moyano on 6/2/18.
//  Copyright © 2018 Carlos  Moyano. All rights reserved.
//

#ifndef CRA_Account_h
#define CRA_Account_h

namespace sict {


	const int max_name_length = 40;
	const int min_sin = 100000000;
	const int max_sin = 999999999;

	class CRA_Account {

		char family_name[max_name_length + 1];
		char given_name[max_name_length + 1];
		int SIN;

	public:
		void set(const char*, const char*, int);
		bool isEmpty() const;
		void display() const;


	};

}

#endif /* CRA_Account_h */
