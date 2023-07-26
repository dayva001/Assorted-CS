#include <iostream>
using namespace std;

void flipString(string &s);

int main() {
 string line;
   cout << "Enter a sentence:" << endl;
   getline(cin, line);
   cout << endl;
   cout << line << endl;
   flipString(line);
   cout << line << endl;

   return 0;
}

void flipString(string &s)
{
    
    if(s.size()==0||s.size()==1)
    {
        return;
    }
    if(s.size()==2)
    {
        char temp=s.at(0);
        s.at(0)=s.at(s.size()-1);
        s.at(s.size()-1)=temp;
       return;
    }
    if(s.size()==3)
    {
        char temp=s.at(0);
        s.at(0)=s.at(2);
        s.at(2)=temp;
        return;
    }
    else
    {
        char temp=s.at(0);
        s.at(0)=s.at(s.size()-1);
        s.at(s.size()-1)=temp;
        string t=s.substr(1,s.size()-2);
        flipString(t);
        s.at(1)=t.at(0);
        s.at(s.size()-2)=t.at(t.size()-1);
    }
    
    
}