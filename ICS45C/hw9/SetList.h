#ifndef SETLIST_H
#define SETLIST_H
#include <string>
#include <algorithm>
#include <fstream>
#include <iterator>
#include <iostream>

template
	<typename T>
class SetList
{
public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef T value_type;
		typedef T& reference;
		typedef T* pointer;
		typedef std::ptrdiff_t difference_type;
	private:
		pointer ibuf;
	public:
		iterator(pointer ptr): ibuf(ptr)
		{
		}
		self_type operator++()
		{
			++ibuf;
			return *this;
		}
		self_type operator++(int postfix)
		{
			self_type cpy = *this;
			ibuf++;
			return cpy;
		}
		reference operator*()
		{
			return *ibuf;
		}
		pointer operator->()
		{
			return ibuf;
		}
		bool operator==(const self_type& rhs)const
		{
			return ibuf == rhs.ibuf;
		}
		bool operator!=(const self_type& rhs)const
		{
			return ibuf != rhs.ibuf;
		}
	};
	SetList()
		:head(0)
	{
	}
	~SetList()
	{
		ListNode::deleteList(head);
	}
	/*SetList<T> operator=(const SetList<T> & set)
	{
		
	}*/
	int size()
	{
		return ListNode::length(head);
	}
	bool empty()
	{
		return head == 0 ? true : false;
	}
	void insert(const T item)
	{
		ListNode* inser = new ListNode(item, 0);
		head = ListNode::concat(head,inser);
	}
	/*
	iterator find(T item)
	{
		return iterator(ListNode::findList(head, item));
	}
	*/
	bool find(T item)
	{
		return ListNode::findLisT(head, item);
	}
	iterator begin()
	{
		return iterator(head);
	}
	iterator end()
	{		
		return iterator(head + size());
	}
private:
	struct ListNode
	{
		T info;
		ListNode * next;
		ListNode(T newInfo, ListNode* newNext)
		 :info(newInfo), next(newNext)
		{
		}
		static ListNode* copy(ListNode* L)
		{
			if(!L)
				return 0;
			return new ListNode(L->info, copy(L->next));
		}
		static ListNode* concat(ListNode* L1, ListNode* L2)
		{	
			if(L1==0)
				return copy(L2);
			return new ListNode(L1->info, concat(L1->next, L2));
		}
		static ListNode* findList(ListNode* L, T item)
		{
			for(ListNode* p=L; p; p=p->next)
			{
				if(p->info==item)
					return p;
			}
			return L;
		}
		static bool findLisT(ListNode* L, T item)
		{
			for(ListNode* p=L; p; p=p->next)
			{
				if(p->info==item)
					return true;
			}
			return false;	
		}
		static ListNode* deleteList(ListNode* L)
		{
			ListNode* temp;
			for(ListNode* p=L; p;)
			{
				temp = p;
				p=p->next;		
				delete temp;
			}	
		}
		static int length(ListNode * L)
		{
			if(L == 0)
				return 0;
			else
				return 1 + length(L->next);
		}
	};
	ListNode* head;
};


#endif
