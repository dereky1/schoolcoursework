#include "String.h"
#include <iostream>
using namespace std;

//////////////////////////////////////////////////
////////////Public Class Methods//////////////////
//////////////////////////////////////////////////
String:: String( const char * s)
	:head(ListNode::stringToList(s))
{	
}
String:: String( const String & s )
	:head(ListNode::copy(s.head))
{
}
String String:: operator = ( const String & s )
{ 
	head = ListNode::copy(s.head);
	return *this;
}
char & String:: operator [] ( const int index )
{
	int count = 0;
	for(ListNode * temp=head; temp; temp=temp->next)
	{
		if(count == index)
			return temp->info;
		++count;	
	}
	cerr << "ERROR: Index Out of Bounds...\nReturning index of 0...\n";
	return head->info;
}
int String:: length() const 
{
	return ListNode::length(head);
}
int String:: indexOf( char c ) const
{
	int index = 0;
	for(ListNode * temp=head; temp; temp=temp->next)
	{
		if(temp->info == c)
			break;
		++index;
	}
	return index;
}
bool String:: operator == ( const String & s ) const
{
	return ListNode::equal(head, s.head);
}
bool String:: operator < ( const String & s ) const
{
	return ListNode::compare(head, s.head);
}
String String:: operator + ( const String & s ) const
{
	String ret;
	ret.head = ListNode::concat(head,s.head);
	return ret;	
}
String String:: operator += ( const String & s )
{
	ListNode * temp = head;
	head = ListNode::concat(temp,s.head);
	ListNode::deleteList(temp);
	return *this;	
}
void String:: print( ostream & out )
{
	for(ListNode * p = head; p; p=p->next)
		out << p->info;
}
void String:: read( istream & in )
{
	char* temp = new char[256];
	in.getline(temp,256);
	head = ListNode::stringToList(temp);
	delete[] temp;
}
String:: ~String()
{
	ListNode::deleteList(head);
}

//////////////////////////////////////////////////
////////////Private Class Methods/////////////////
//////////////////////////////////////////////////
bool String:: inBounds( int i )
{
  return i >= 0 && i < length();
}

String::String::ListNode:: ListNode(char newInfo, ListNode * newNext)
: info( newInfo ), next( newNext )
{
}
String:: ListNode * String::ListNode:: stringToList(const char *s)
{
	if(s[0] == 0)
		return 0;
	else
		return new ListNode(s[0], stringToList(s+1));
}
String:: ListNode * String::ListNode:: copy(ListNode * L)
{
	if(!L)
		return 0;
	else
		return new ListNode(L->info, copy(L->next));	
}
bool String::String::ListNode:: equal(ListNode * L1, ListNode * L2)
{
	for(;L1 && L2; L1=L1->next, L2=L2->next)
		if(L1->info != L2->info)
			return false;
	return !L1 == !L2;
}
String:: ListNode * String::ListNode:: concat(ListNode * L1, ListNode * L2)
{
	if(L1 == 0)
		return copy(L2);
	else 
		return new ListNode(L1->info, concat(L1->next, L2));
}
int String::String::ListNode:: compare(ListNode * L1, ListNode * L2)
{
	if(L1->info != L2->info)
		return (L1->info - L2->info);	
	else if(L1->next == 0 && L2->next == 0)
		return (L1->info - L2->info);
	else	
		return compare(L1->next, L2->next);
}
void String::String::ListNode:: deleteList(ListNode * L)
{
	ListNode * temp;
	for(ListNode * p = L; p != 0;)
	{
		temp = p;
		p = p->next;
		delete temp;
	}
}
int String::String::ListNode:: length(ListNode * L)
{
	if(L == 0)
		return 0;
	else
		return 1 + length(L->next);
}

ostream & operator << ( ostream & out, String str )
{
	str.print(out);
	return out;
}
istream & operator >> ( istream & in, String & str )
{
	str.read(in);
	return in;
}
