#include "string.h"
#include <iostream>
using namespace std;

String :: String(const char* s)
	:buf(new_char_array(strlen(s)))
{	
	strcpy(buf, s);
}
String :: String(const String & s)
	:buf(new_char_array(strlen(s.buf)))
{
	strcpy(buf, s.buf);
}
String String :: operator = (const String &s)
{
	delete_char_array(buf);
	buf = new_char_array(strlen(s.buf));
	return strcpy(buf,s.buf); 

	//return strcpy(buf,s.buf);
}
char & String :: operator [] (int index)
{
	if(!inBounds(index))
	{
		error("Index out of bounds");
		return buf[0];
	}
	return buf[index];
}
int String :: size()
{
	return String :: strlen(buf);
}
String String :: reverse()
{
	int len = size();
	char temp[len];
	for(int i=0; i < len; ++i)
	{	
		temp[len-1-i] = buf[i];
	}
	String rever(temp);
	return rever;
}
int String :: indexOf(const char c)
{
	int count = 0;
	if(strchr(buf, c))
	{
		for(int i=0; i<size(); ++i)
		{
			if(buf[i] == c)
				return count;
			++count;
		}
		return count;	
	}	
	return 0;	
}
int String :: indexOf(const String pattern)
{
	int pat_len = strlen(pattern.buf);
	int len = size();
	char first = pattern.buf[0];
	int match = 0;
	int count = 0;
	int left;
	if(strchr(buf, pattern.buf[0]))
	{
		for(int i=0; i<len; ++i)
		{
			left = i;
			if(buf[i] == first)
			{
				++match;
				for(int i=1; i<pat_len; ++i)
				{
					if(buf[(i+left)]!=pattern.buf[i])
					{
						match = 0;
						break;
					}
					++match;
					if(match == pat_len)
						return count;
				}
			}	
			++count;		
		}
		return count;
	}
	return 0;
}
bool String :: operator == (const String s)
{
	return String::strcmp(buf, s.buf) == 0;
}
bool String :: operator != (const String s)
{
	return (strcmp(buf, s.buf)) ? true: false;
}
bool String :: operator > (const String s)
{
	return strcmp(buf, s.buf) > 0;
}
bool String :: operator < (const String s)
{	
	return strcmp(buf, s.buf) < 0;
}
bool String :: operator <= (const String s)
{
	return strcmp(buf, s.buf) <= 0;
}
bool String :: operator >= (const String s)
{
	return strcmp(buf, s.buf) >= 0;
}
String String :: operator + (const String s)
{
	int len = size() + strlen(s.buf);
	char * temp = new_char_array(len);
	for(int i=0; i<size() ; ++i)
		temp[i] = buf[i];
	for(int i=0; i<strlen(s.buf); ++i)
		temp[(i+size())] = s.buf[i];
	String added(temp);
	delete_char_array(temp);
	return added;

}
String String :: operator += (const String s)
{	
	int len = size() + strlen(s.buf);
	char buf1[size()];
	for(int i=0; i<size(); ++i)
		buf1[i] = buf[i];
	delete_char_array(buf);
	buf = new_char_array(len);
	//char * temp = new_char_array(len);
	for(int i=0; i<strlen(buf1) ; ++i)
		buf[i] = buf1[i];
	for(int i=0; i<strlen(s.buf); ++i)
		buf[(i+strlen(buf1)-1)] = s.buf[i];
	//buf = temp;
	//delete_char_array(temp);
	return buf;	
}
void String :: print(ostream & out)
{
	out << buf;
}
void String :: read(istream & in)
{
	in.getline(buf,256);
}
String :: ~String()
{
	String::delete_char_array(buf);
	//final_report_on_allocations();
}
void String :: final_report_on_allocations()
{
	if (String :: allocations > 0)
		String :: error("Memory Leak in class String");
	if (String :: allocations < 0) 
		String :: error("Too many delete[]s in class String");
	if (String :: allocations == 0)	
		cout << "Allocations & deallocations match\n";
}

////////////////////////////////////////////////////////////
////////////////////Private Members/////////////////////////
////////////////////////////////////////////////////////////

int String :: allocations = 0; 
char * String :: new_char_array(int n_bytes)
{
	++allocations;
	return new char[n_bytes];
}
void String :: delete_char_array(char *p)
{
	--allocations;
	if (allocations < 0) 
		error("More delete[] than new[]");
	delete [] p;
}
void String :: error(const char *p)
{
	cerr << "Error (class String): " << p << endl;
}
bool String :: inBounds(int i)
{
		return i >= 0 && i < strlen(buf);
}
int String :: strlen(const char *src)
{
	int len=0;
	for(int i=0; src[i] != '\0'; ++i)
		++len;
	return len;
}
char * String :: strcpy(char *dest, const char *src)
{
	int i;
	for(i=0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = src[i];
	return dest;
}
char * String :: strcat(char *dest, const char *src)
{
	strcpy(dest + strlen(dest), src);
	return dest;
}
int String :: strcmp(const char *left, const char *right)
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
int String :: strncmp(const char *left, const char *right, int n)
{
	int i;
	for(i=0; i<n; ++i)
	{
		if (left[i] != right[i])
			return left[i]-right[i];	
	}
	return left[i]-right[i]; 
}
const char * String :: strchr(const char *str, int c)
{
	for(; *str != c; ++str)
		if(*str == 0)
			return 0;
	return str;	
}
char * String :: strdup(const char *src)
{
	//String dup(src);
	//return dup;
}
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
