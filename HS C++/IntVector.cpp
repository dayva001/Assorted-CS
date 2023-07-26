#include "IntVector.h"
#include <stdexcept>
#include <iostream>
using namespace std;

    IntVector::IntVector(): sz(0),cap(0),data(NULL)
    {}
    
   IntVector::IntVector( unsigned size, int value ) : sz(size),cap(size),data(new int[size])
    {
        for(unsigned i=0; i < size; i++)
        {
            data[i]=value;
        }
    }
    
    IntVector::~IntVector()
    {
        delete [] data;
    }
    
   unsigned IntVector::size( ) const
   {
       return sz;
   }
   
   unsigned IntVector::capacity() const
   {
       return cap;
   }
   
   bool IntVector::empty( ) const
   {
       return(sz==0);
   }
   
   const int & IntVector::at( unsigned index ) const
   {
       if(index >= sz)
       {
            throw out_of_range("IntVector::at_range_check");
       }
        else
            return data[index];
   }

   int & IntVector::at(unsigned index)
    {
       if(index >= sz)
       {
            throw out_of_range("IntVector::at_range_check");
       }
        else
            return data[index];
   }
   
   
   
   
   
    void IntVector::insert( unsigned index, int value )
  {
        if(sz+1 > cap)
        {
            expand();
        }
        if(index > sz)
        {
            throw out_of_range("IntVector::insert_range_check");
        }
        for(unsigned i=index;i<sz;i++)
        {
            data[i+1]=data[i];
        }
        data[index]=value;
  }

  void IntVector::erase( unsigned index )
  {
        if(index > sz)
        {
            throw out_of_range("IntVector::erase_range_check");
        }
        for(unsigned i=index;i<sz-1;i++)
        {
            data[i]=data[i+1];
        }
        sz--;
  }
   

  const int & IntVector::front( ) const
  {
      return data[0];
  }

    int & IntVector::front()
    {
        return data[0];
    }
    
  const int & IntVector::back( ) const
  {
      return data[sz-1];
  }
    
    int & IntVector::back()
    {
      return data[sz-1];
  }
   
  void IntVector::assign(unsigned n, int value)
  {
      if(n>cap)
      {
          reserve(n);
      }
      for(unsigned i=0;i<n;i++)
      {
          data[i]=value;
      }
      sz=n;
  }
  
  void IntVector::push_back( int value )
  {
        if(sz == cap)
        {
            expand();
        }
        data[sz] = value;
        sz++;

  }

  void IntVector::pop_back()
  {
        sz--;
  }

    void IntVector::clear()
    {
        sz=0;
    }

     void IntVector::resize( unsigned size, int value )
    {
      if(size<=sz)
      {
            sz=size;
            return;
      }
      if(size>cap)
      {
            reserve(size);
            for(unsigned i=sz;i<size;i++)
            {
                data[i]=value;
            }
            sz=size;
      }
    }

    void IntVector::IntVector::expand()
      {
          if(cap==0)
          {
              cap=1;
              delete [] data;
              data=new int[1];
              return;
          }
          int* temp=new int[cap*2];
          for(unsigned i=0; i < cap; i++)
          {
              temp[i] = data[i];
          }
          delete[] data;
          data=temp;
          cap+=cap;
      }
       
  void IntVector::expand( unsigned amount )
    {
        if(cap==0)
      {
          cap=amount;
          delete [] data;
          data=0;
          data=new int[cap];
          return;
      }
      if(amount>0)
      {
          int* temp= new int[cap+amount];
          for(unsigned i=0; i < cap; i++)
          {
              temp[i] = data[i];
          }
          delete[] data;
          data=temp;
          cap+=amount;
      }
    }
    
    void IntVector::reserve(unsigned n)
    {
        if(n<cap)
        {
            return;
        }
                if(cap*2 > n)
                {
                    expand();
                    return;
                }
              if(cap*2 <n)
              {
                  expand(n-cap);
                  return;
              }
            
    }


