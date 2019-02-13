#ifndef PICTURE_H
#define PICTURE_H
#include "Shape.h"
#include "Circle.h"
#include "Square.h"
#include "Triangle.h"
#include "Rectangle.h"

class Picture
{
public:
	Picture()
		:head(0)
	{
	}
	void add(Shape* sp)
	{
		ListNode* temp = head;
		ListNode* cat = new ListNode(sp,0);
		head = ListNode::concat(temp, cat);
		ListNode::deleteList(temp);
		ListNode::deleteList(cat);
	}
	void drawAll()
	{
		for(ListNode* p=head; p; p=p->next)
			p->shape->draw();
	}
	double totalArea()
	{	
		double result = 0;
		for(ListNode* p=head; p; p=p->next)
			result+=p->shape->area();	
		return result;
	}
	~Picture()
	{
		Shape* s;
		for(ListNode* p=head; p;)
		{
			s = p->shape;
			p = p->next;
			delete s;
		}
		ListNode::deleteList(head);
	}
private:
	struct ListNode
	{
		Shape * shape;
		ListNode * next;
		ListNode(Shape* newShape, ListNode* newNext)
		 :shape(newShape), next(newNext)
		{
		}
		static ListNode* copy(ListNode* L)
		{
			if(!L)
				return 0;
			return new ListNode(L->shape, copy(L->next));
		}
		static ListNode* concat(ListNode* L1, ListNode* L2)
		{	
			if(L1==0)
				return copy(L2);
			return new ListNode(L1->shape, concat(L1->next, L2));
		}
		static ListNode* deleteList(ListNode* L)
		{
			Shape* sp;
			ListNode* temp;
			/*for(ListNode* p=L; p;)
			{
				sp=p->shape;
				p=p->next;	
				delete sp;
			}*/
			for(ListNode* p=L; p;)
			{
				temp = p;
				p=p->next;		
				delete temp;
			}	
		}
		static void deleteShape(ListNode* L)
		{
			Shape* temp;
			for(ListNode* p=L; p;)
			{
				temp = p->shape;
				p=p->next;
				delete p;
			}
		}
	};
	ListNode * head;
};

#endif
