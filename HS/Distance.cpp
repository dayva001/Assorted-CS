#include <stdio.h>
#include <cstdlib>
#include <cmath>  
#include "Distance.h"


Distance::Distance()
:feet(0), inches(0.0)
{
}

Distance::Distance(unsigned ft, double in)
{
    feet=ft;
    inches=fabs(in);
    init();
}
Distance::Distance(double i)
{
    
    if(fabs(i)<12.0)
    {
        feet=0;
        inches=fabs(i);
    }
    if(fabs(i)>12.0)
    {
        feet = fabs(i)/12;
        inches= fabs(i)-feet*12;
    }
}

unsigned Distance::getFeet() const
{
    return feet;
}
double Distance::getInches() const
{
    return inches;
}
double Distance::distanceInInches() const
{
    return (feet*12.0 + inches);
}

double Distance::distanceInFeet() const
{
    return (feet+inches/12.0);
}

double Distance::distanceInMeters() const
{
    return (feet*12.0+inches)*0.0254;
}

const Distance Distance::operator+(const Distance &rhs) const
{
    return Distance(feet+rhs.feet, inches+rhs.inches);
}



const Distance Distance::operator-(const Distance &rhs) const
{
    Distance ret;
    if(distanceInInches()>rhs.distanceInInches()  )
    {
        ret=Distance(distanceInInches()-rhs.distanceInInches());
    }
    else
    {
        ret=Distance(rhs.distanceInInches()-distanceInInches());
    }
   
    return ret;
}

ostream & operator<<(ostream &out, const Distance &rhs)
{
    out << rhs.feet <<"' " << rhs.inches<< "\"";
    return out;
    
}

void Distance::init()
{
    
    while(abs(inches) >= 12.0)
    {
        feet++;
        inches = fabs(inches - 12.0);
    } 

}