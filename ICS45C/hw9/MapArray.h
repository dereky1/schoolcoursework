#ifndef MAPARRAY_H
#define MAPARRAY_H
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

template
	<typename T1, typename T2>
class MapArray
{
public:
	struct iterator
	{
		typedef std::forward_iterator_tag iterator_category;
		typedef iterator self_type;
		typedef T1 value_type;
		typedef T1& reference;
		typedef T1* pointer;
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
		self_type operator --()
		{
			--ibuf;
			return *this;
		}
		self_type operator --(int postfix)
		{
			self_type cpy = *this;
			ibuf--;
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
	MapArray(const std::pair<T1, T2>* p)
		:items(new std::pair<T1,T2>[ptrlen(p)])
	{
		ptrcpy(items, p);
	}
	MapArray(const MapArray& M)
		:items(new std::pair<T1, T2>[M.size()])
	{
		ptrcpy(items, M.items);
	}
	MapArray()
		:items(0)
	{		
	}
	int size()
	{
		return ptrlen(0);
	}
	iterator begin()
	{
		return iterator(0);
	}
	iterator end()
	{
		return iterator(0);
	}
	T2& operator[](const T1 str)
	{		
		/*
		for(pair* p = items; p; p=p+1)
		{
			if(p->first == str)
				return p->second;
		}
		*/
	
		/*for(int i; i<ptrlen(items); ++i)
		{
			if(items[i].first == str)
				return items[i].second;
		}*/
	}
	void insert(std::pair<T1, T2>* pear)
	{
		std::pair<T1, T2>* temp = items;
		items = ptrcat(temp,pear);
	}
	bool findKey(T1 key)
	{
		for(iterator i = begin(); i != end(); i++)
		{
			if(i->first == key)
				return true;	
		}
	}
	MapArray& operator = (MapArray M)
	{
		delete items;
		items = new std::pair<T1,T2>[M.size()];
		ptrcpy(items, M.items);
	}
	~MapArray()
	{
		delete[] items;
	}
private:
	static std::pair<T1, T2>* ptrcpy(std::pair<T1,T2>* dest, const std::pair<T1,T2>* src)
	{
		int i;
		for(i=0; i<ptrlen(src); ++i)
			dest[i] = src[i];
		dest[i] = src[i];
		return dest;
	}
	static std::pair<T1,T2>* ptrcat(std::pair<T1,T2>* dest, const std::pair<T1,T2>* src)
	{
		ptrcpy(dest + ptrlen(dest), src);
		return dest;
	}
	static int ptrlen(const std::pair<T1,T2>* src)
	{
		int len=0;
		for(; src != 0; src = src + 1)
			++len;
		return len;
	}
	std::pair<T1,T2>* items;
};

#endif
