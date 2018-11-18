#include <iostream>
#include "Kingdom.h"

using namespace std;

namespace sict {

	void display(Kingdom &kingdom) {

		cout << kingdom.m_name << ", population " << kingdom.m_population << endl;

	}

}