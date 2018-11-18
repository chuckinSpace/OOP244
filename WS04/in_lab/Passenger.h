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
      
    public:
        Passenger();
        Passenger(const char * pname ,const char * dest);
        bool isEmpty() const;
        void display() const;
    };
}
#endif
