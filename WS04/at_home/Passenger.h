// TODO: add file header comments here

// TODO: add header file guard here
#ifndef _Passenger_h
#define _Passenger_h

using namespace std;
// TODO: declare your namespace here
namespace sict{
    // TODO: define the Passenger class here
    class Passenger{
        
        char pass_name[32];
        char destination[32];
        int year_dep;
        int month_dep;
        int day_dep;
      
    public:
        Passenger();
        Passenger(const char * pname ,const char * dest);
        Passenger(const char * pname, const char * dest, const int yr_Dep, const int mont_Dep,
                  const int Day_Dep);
        const char * name() const;
        bool canTravelWith(const Passenger &) const;
        bool isEmpty() const;
        void display() const;
        
    };
}
#endif
