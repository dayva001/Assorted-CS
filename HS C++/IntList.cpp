#include "IntList.h"


IntList::IntList():head(0), tail(0)
{}

IntList::~IntList()
{   
   while(head!=0)
   {
       pop_front();
   }
}

void IntList::display() const
{
    IntNode* move = head;
   
    while(move!=0)
    {
        if(move==tail)
        {
            cout << move->data;
        }
        else
        {
            cout << move->data << " ";
        }
        move=move->next;
    }

}

void IntList::push_front(int value)
{
    if(head==0)
    {
        head=new IntNode(value);
        tail=head;
    }
    else
    {
        IntNode* temp = new IntNode(value);
        temp -> next = head;
        head = temp;    
    }
    
}

void IntList::pop_front()
{
	if(head==0)
	{
		return;
	}
	
    if(head!=0)
    {
        IntNode* temp = head->next;
        delete head;
        head= temp;
    }
        
}

bool IntList::empty() const
{
    return(head==0);
} 

IntList::IntList(const IntList &cpy)
{
	if(cpy.head==0)
	{
		head=0;
		tail=0;
		return;
	} 
	IntNode *rhsT=cpy.head;
	head=new IntNode(rhsT->data);
	IntNode *temp=head;
	while(rhsT->next!=0)
	{
		IntNode *up=new IntNode(rhsT->next->data);
		temp->next=up;
		temp=up;
		rhsT=rhsT->next;
	}
	tail=temp;
}

IntList & IntList::operator=(const IntList &rhs)
{
	if(&rhs!=this)
	{
		
		clear();
		if(rhs.head==0)
		{
			return *this;
		} 
		IntNode *rhsT=rhs.head;
		head=new IntNode(rhsT->data);
		IntNode *temp=head;
		while(rhsT->next!=0)
		{
			IntNode *up=new IntNode(rhsT->next->data);
			temp->next=up;
			temp=up;
			rhsT=rhsT->next;
		}
		tail=temp;
		return *this;
	}
	return *this;
}

void IntList::push_back( int value )
{
     if(head==0)
    {
        head=new IntNode(value);
        tail=head;
    }
    else
    {
        IntNode* temp = new IntNode(value);
        tail->next = temp;
	    tail = temp;
    }
}

void IntList::clear()
{
	while(head!=0)
   {
       pop_front();
   }
   head=tail=0;
}

void IntList::selection_sort( )
{
    if(head == 0)
    {
        return;
    }
    for(IntNode *wall = head; wall != 0; wall = wall->next)
	{
		int minVal = wall->data;
		for(IntNode *curr = wall->next; curr != 0; curr = curr->next)
		{
			if(curr->data < minVal)
			{
				minVal = curr->data;
				curr->data = wall->data;
				wall->data = minVal;
			}
		}
	}
}



void IntList::insert_ordered( int value )
{
    if(head == 0)
	{
		push_front(value);
		return;
	}
	if(head->next == 0)
	{
		
		if(head->data <= value)
		{
			push_back(value);
			return;
		}
		else
		{
			push_front(value);
			return;
		}
	}
	if(tail->data <= value)
	{
		push_back(value);
		return;
	}
    if(head->data >= value)
	{
		push_front(value);
		return;
	}
	else 
	{
		
		IntNode* cTemp = head;
		IntNode* nTemp = head->next;
		IntNode* i = 0;
		
		for(i = head; !(cTemp->data <= value && nTemp->data >= value);i = i->next)
		{
			cTemp = i->next;
			nTemp = cTemp->next;
		}
		
		IntNode *rTemp = new IntNode(value);
		rTemp->next = nTemp;
		cTemp->next = rTemp;
	}
}

void IntList::remove_duplicates()
{
	for(IntNode *wall = head; wall != 0; wall = wall->next)
	{
		int val = wall->data;
		IntNode *prev = wall;
		
		
		for(IntNode *curr = wall->next; curr != 0;)
		{
			
			if(val == curr->data && curr->next != 0)
			{
				prev->next = curr->next;
				delete curr;
				curr = prev;
			}
			if(val == curr->data && curr == tail)
			{
				tail = prev;
				delete curr;
				tail->next = 0;
			}
			if(curr != prev)
			{
				curr = curr->next;
				prev = prev->next;
			}
			else
			{
				curr = curr->next;
			}
		}
	}


}


ostream & operator<<(ostream &out, const IntList &rhs)
{
	 IntNode* move = rhs.head;
   
    while(move!=0)
    {
        if(move==rhs.tail)
        {
            out << move->data;
        }
        else
        {
            out << move->data << " ";
        }
        move=move->next;
    }
	return out;
}