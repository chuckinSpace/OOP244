
#include <iostream>
#include <iomanip>

namespace sict {
    // These numbers define
    // a) the range of data we expect to see in this workshop
    //    0 to 1 billion
    //    use them in the min and max function
    // b) the output column width for a single data field
    
    const int LARGEST_NUMBER  = 1000000000; // 1,000,000,000
    const int SMALLEST_NUMBER = 0;
    const int COLUMN_WIDTH    = 15;
    
    // max returns the largest item in data
    //
    template<typename T>
    T max(const T* data, int n){
        double largest = data[0];
        
        for(int i= 0; i < n; i++){
            if(data[i] > largest){
                largest = data[i];
            }
        }
        return largest;
    }
    
    
    // min returns the smallest item in data
    template<typename T>
    T min(const T* data, int n){
        double smallest = data[0];
        
        for(int i= 0; i < n; i++){
            if(data[i] < smallest){
                smallest = data[i];
            }
        }
        return smallest;
    }
    
    
    
    // sum returns the sum of n items in data
    //
    template<typename T>
    T sum(const T* data, int n){
        T sum=0;
        for(int i = 0; i < n; i ++){
            sum += data[i];
        }
        return sum;
    }
    
    // average returns the average of n items in data
    //
    template<typename T>
    double average(const T* data, int n){
        double average = (sum(data,n) / n );
        return average;
    }
    
    
    // read extracts n items from input and stores them in data
    // - the items are comma separated
    // - this function assumes that a comma exists at the next field to be read
    // - for example: ,data1, data2,data3, ...., datan
    //
    
    template<typename T>
    bool read(std::istream& input, T* data, int n){
        for(int i = 0; i < n; i ++){
            input.ignore();
            input >> data [i];
            if(input.fail()){
                return false;
            }
            
        }
        return true;
    }
    
    
    // display inserts n items of data into std::cout
    //
    
    template<typename T>
    void display(const char *name, const T* data, int n){
       
            std::cout << std::setw(20) << std::right  << name;
        
        for (int i = 0; i < n; i++){
            std::cout << std::setw(15) << data[i];
        }
       
        std::cout << "\n";
        
    }
    
 
    
    bool readRow(std::istream& input, const char* name, int* data, int n);
    bool readRow(std::istream& input, const char* name, double* data, int n);
    void answers(const int*, const int*, const int*, const double*, const int*, const int n);
}
