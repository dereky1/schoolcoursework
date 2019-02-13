#define MAXLEN 128
#include <iostream>
using namespace std;

class String
{
public:
	String( const char * s = "")
	{
		strcpy(buf,s);
	}
	String( const String & s)
	{
		strcpy(buf,s.buf);
		
	}
	String operator = (const String & s)
	{
		strcpy(buf, s.buf);
		return buf;
	}
	char & operator [] (int index)
	{
		return buf[index];
	}
	int size()
	{
		return strlen(buf);
	}
	//broken
	String reverse()
	{	
		int len = strlen(buf);
		char array[len-1];
		for(int i=0; i<len; i++)
			array[len-i] = buf[i];
		String temp(array);
		return temp;
	}
	int indexOf(const char c)
	{
		int len = strlen(buf);
		int count = 0;
		if(strchr(buf, c))
		{
			for(int i=0; i<len; ++i)
			{
				if (buf[i] == c)	
					return count;
				count++;
			}
		return count;
		}
		return -1;
	}
	int indexOf(const String pattern)
	{
		int len = strlen(buf);
		int patlen = strlen(pattern.buf);
		int patindex=0;
		int count =0;
		int match =0;	
		for(int i; i<len; ++i)
		{
			if(match == patlen)
				return count;
			else if(buf[i] == pattern.buf[patindex])
			{
				match++;
				patindex++;
			}
			else
			{
				match=0;
				patindex=0;
			}	
		count++;
		}
		return count;
	}
	bool operator == (const String s)
	{
		return strcmp(buf, s.buf) == 0;		
	}
	bool operator != (const String s)
	{
		return (strcmp(buf, s.buf)) ? true: false;
	}
	bool operator > (const String s)
	{
		return strcmp(buf, s.buf) > 0;	
	}
	bool operator < (const String s)
	{
		return strcmp(buf, s.buf) < 0;
	}
	bool operator <= (const String s)
	{
		return strcmp(buf, s.buf) <= 0;
	}
	bool operator >= (const String s)
	{
		return strcmp(buf, s.buf) >= 0;
	}
	String operator + (const String s)
	{
		String plus(buf);
		return strcat(plus.buf,s.buf);	
	}
	String operator += (const String s)
	{
		return strcat(buf,s.buf);
	}
	void print(ostream & out)
	{
		cout << buf;
	}
	void read(istream & in)
	{	
		in.getline(buf, MAXLEN);
	}
	~String()
	{
	}
private:
	bool inBounds(int i)
	{
		return i >= 0 && i < strlen(buf);	
	}
	static int strlen(const char *s)
	{
		int len=0;
		for(int i=0; s[i] != '\0'; ++i)
			++len;
		return len;
	}
	static char * strcpy(char *dest, const char *src)
	{
		int i;
		for(i=0; src[i] != '\0'; ++i)
			dest[i] = src[i];
		dest[i] = src[i];
		return dest;
	}
	static char * strcat(char *dest, const char *src)
	{
		strcpy(dest + strlen(dest), src);
		return dest;
	}
	//Both strcmp not tested
	static int strcmp(const char *left, const char *right)
	{
		int count = 0;
		while(left[count]!= '\0')
		{
			if (left[count] != right[count])
				return left[count]-right[count];
			else
				++count;
		}
		return left[count] - right[count];
	}
	static int strncmp(const char *left, const char *right, int n)
	{
		int i;
		for(i=0; i<n; ++i)
		{
			if (left[i] != right[i])
				return left[i]-right[i];	
		}
		return left[i]-right[i]; 
	}
	static const char * strchr(const char *str, int c)
	{
		for(; *str != c; ++str)
			if(*str == 0)
				return 0;
		return str;	
	}
	static const char * strstr(const char *haystack, const char *needle)
	{
		int len = strlen(haystack);
		int nlen = strlen(needle);
		int match =0;
		for(int i=0; i<len; ++i)
		{
			if(match == nlen)
				return haystack;
			else if(*haystack == *needle)
			{
				*needle++;
				match++;
			}
			else
				*needle--;
			*haystack++;
		}
		return 0;
	}	
	char buf[MAXLEN];
};
ostream & operator << (ostream & out, String str)
{
	str.print(out);
	return out;
}
istream & operator >> (istream & in, String & str)
{
	str.read(in);
	return in;
}
