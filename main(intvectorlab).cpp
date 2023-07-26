#include "IntVector.h"

#include <iostream>

using namespace std;

int main()
{
    IntVector test = IntVector();
    
    cout << test.size() << " "  << test.capacity() << endl;
    
    IntVector test2 = IntVector(10,4);
    
    cout << test2.size() << " "  << test2.capacity() << endl;
    
    cout << test2.front() << " "  << test2.back() << endl;
     
     return 0;
}
