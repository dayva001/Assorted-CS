#include <stdio.h>
#include <iostream>
#include <cstdlib>

using namespace std;
#include "IntVector.h"
int main()
{
 IntVector test = IntVector();
  
  cout << test.size() << ' '  << test.capacity() << ' ' <<  test.empty() << endl;
  
  test.reserve(400);
  
  cout << test.size() << ' '  << test.capacity() << ' ' <<  test.empty() << endl;
  
  test.resize(40,2);
  
  cout << test.size() << ' '  << test.capacity() << ' ' <<  test.empty() << ' ' << test.back() << endl;
  
  test.insert(20,7);
  
  test.assign(22,3);
  
  cout <<test.at(20) << ' '<< test.size() << endl;
  
  test.assign(50,3);
  
  cout <<test.at(20) << ' '<< test.size() << endl;
  
  test.erase(20);
  
  cout <<test.at(20) << ' '<< test.size() << endl;
  
  cout <<test.at(20) << endl;
  
  test.clear();
  
  cout << test.size() << endl;
  
  IntVector test2 = IntVector(40,4);
  
  cout << test2.size() << ' '  << test2.capacity()<< ' ' <<  test2.empty()  << endl;
  
  cout << test2.front() << ' '  << test2.back() << endl;
  
  test2.pop_back();
  
  cout << test2.size()<< endl;
  
  test2.push_back(30);
  
  cout << test2.back() << endl;
  
 return 0;
 }
