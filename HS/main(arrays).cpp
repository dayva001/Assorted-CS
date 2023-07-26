#include "iostream"
using namespace std;
double mean(const double array[], int arraySize);

void remove(double array[], int arraySize, int index);

void display(const double array[], int arraySize);

double mean(const double array[], int arraySize)
{
    double dTotal=0;
    for(int i=0;i<arraySize;i++)
    {
        dTotal+=array[i];
    }
    return dTotal/arraySize;
}

void remove(double array[], int arraySize, int index)
{
    for(int i=index;i<arraySize-1;i++)
    {
        array[i]=array[i+1];
    }
}

void display(const double array[], int arraySize)
{
    for(int i=0;i<arraySize;i++)
    {
        if(i==arraySize-1)
        {
            cout << array[i];
        }
        else
        {
            cout << array[i] << ", ";
        }
    }
}
const int ARR_CAP=10;

int main()
{
    int index;
    double dArr[ARR_CAP];
    cout << "Enter 10 values:"<<endl ;
    for(unsigned i=0;i<ARR_CAP;i++)
    {
        cin >> dArr[i];
    }
    cout << endl;
    cout <<"Mean: " << mean(dArr,ARR_CAP) << endl << endl;
    cout <<"Enter index of value to be removed: " << endl ;
    cin >> index;
    cout << "Before removing value: "; display(dArr, ARR_CAP); cout << endl;
    remove(dArr,ARR_CAP,index);
    cout << "After removing value: "; display(dArr, ARR_CAP-1); cout << endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
}