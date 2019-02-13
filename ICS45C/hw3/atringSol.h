#define MAXLEN 128
class String
{
public:
	String( const char * s = "");
	String( const String & s);
	String operator = ( const String & s);
	char & operator [] (int index);
	int size();
	String reverse();
	int indexOf( const char c);
	int indexOf(const String pattern);
	bool operator == ( const String s);
	bool operator != ( const String s);
	bool operator > ( const String s);
	bool operator < ( const String s);
	bool operator <= ( const String s);
	bool operator >= ( const String s);
	String operator + ( const String s);
	String operator += ( const String s);
	void print( ostream & out);
	void read( istream & in);
	~String();
private:
	bool inBounds( int i)
	{
			return i >= 0 && i < strlen(buf);
	}
	static int strlen( const String * s);
	static char * strcpy( char *dest, const char * src);
	static char * strcat(char *dest, const char * src);
	static int strcmp( const char *left, const char *right);
	static int strncmp( const char *left, const char *right, int n);
	static char * strchr( const char *str, int c);
	static char * strstr( const char *haystack, const char *needle );
	char buf[MAXLEN];
};
ostream & operator << ( ostream & out, String str);
istream & operator >> ( istream & in, String & str);	

//===============================
//definition:
//===============================
static int strlen(const char *s)
{
	int len=0;
	for(int i=0; s[i] != '\0' ; ++1)
		++len;
	return len;
	
	/////////////////////////
	
	int len =0;
	for(const char *p = s; *p != '\0'; ++p)
		++len;
	return len;
	
	
	//////////////////////////
	
	int len=0;
	while(s[len] != '\0')
		++len;
	return len;
	
	
	/////////recursion/////////
	
	if ( *s == '\0')
		return 0;
	else
		return 1 + strlen(s+1);
	
	////////klefstad's way///////

	return !*s ? 0; 1 + strlen(s+1);

}


static char * strcpy( char *dest, const char *src)
{
	int i;
	for (i=0; src[i] != '\0'; ++i)
		dest[i] = src[i];
	dest[i] = src[i];	
	return dest;
	
	///////klefstad's way///////////
	
	char *d = dest;
	while( *d++ = *src++) 
		;
	return dest;
}

static char *strcat (char *dest, const char *src)
{
	strcpy(dest + strlen(dest). src);
	return dest;
	
}

static int strcmp( const char *left, const char *right)
{
///while len are equal
///when not, subtract ascii
}

static int strncmp( const char *left, const char *right, int n)
{
///n limits how many characters we look into
}

static const char * strchr( const char *str, int c)
{
///// searches for c in str and return pointer to it
	for(; *str ~= c; ++str)
		if(*str == 0)
			return nullptr;//cpp 11 correct nullptr
	return str;
}

static char * strstr(const char *haystack, const char *needle)
{
//need a top level loop to keep it going
//if fail search s+1, look for another 
// it will call
//strchar() strncmp() n=strlen(needle)
//look for first letter, then search for length of str
}


//
//constructors
//strcpy some array of char into this buf 
//both 1 liners
//

String (const char * s = "")
{
	strcpy(buf, s);
}

String( const String & s) // copy constructor

operator = : strcpy
must return string type (this/itself)
if it points to it == pointer
*this returns what this points to


operator [] (index) 
call inbounds to check if it is in bounds


size return strlen of buf

reverse makes a reversed copy

indexof --- strchr
indexof ---- strstr

operator == --- >= strstr

operator +, += adds on to this char, strcat

print using inserter 

read call getline and put all araray in buf
//
//quiz 3 
//new static method 
//new class method
//new main method
//remember hw 3 functions/methods
//