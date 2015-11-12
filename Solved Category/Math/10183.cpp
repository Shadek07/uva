#include<iostream>
#include<cstring>


using namespace std;

int compare(char first[1000],char second[1000])
{
	int i,l1,l2;
	l1=strlen(first);
	l2=strlen(second);
	if(l1>l2)
		return 1;
	if(l2>l1)
		return 0;

	for(i=0;i<l1;i++)
	{
		if((first[i]-48) > (second[i]-48))
			return 1;
		if((first[i]-48) < (second[i]-48))
			return 0;
	}

	return 2;
} 

class BigInteger
{
public:

	BigInteger();

	int setbychar(const char *num);

	int add(BigInteger &a1,BigInteger &a2);

	const char*print();

	~BigInteger();

private:

	int size;
	
	char *content;

};

BigInteger :: BigInteger() : size(0),content(0){}

int BigInteger::setbychar(const char *num)
{
	size = strlen(num);

	content = new char[size+1];

	strcpy(content,num);

	return 0;

}

int BigInteger::add(BigInteger &a1, BigInteger &a2)
{
	char *temp;
	int i,j,k,c,t;

	size = a1.size > a2.size ? a1.size: a2.size;
	size++;

	temp = new char [size+1];

	memset(temp,32,sizeof(temp));

	i = a1.size -1;

	j = a2.size - 1;

	k = size - 1;

	temp[size] = '\0';

	c = 0;

	while( i>= 0 || j >= 0 || c != 0)
	{
		t = c;
		c = 0;
		if( i >= 0)
		{
			t += a1.content[i] - 48;
			i--;
		}
		if( j >= 0 )
		{
			t += a2.content[j] - 48;
			j--;
		}
		c = t/10;
		t = t%10;
		temp[k--] = t + 48;
	}

	if( k >= 0)
	{
		strcpy(temp,temp+k+1);
	}

	size -= (k+1);
	if( content != NULL)
		delete content;
	content = temp;

	return 0;
}


const char *BigInteger::print()
{
	return content;
}

BigInteger::~BigInteger()
{
	if( content != NULL)
	{
		delete content;
	}
}



int main(void)
{

    int i,n,count;

	char in1[110],in2[110];

	char out[5000];
	int a1,b1;
   

	BigInteger a[5001];

	a[0].setbychar("1");
	a[1].setbychar("2");

	for(i = 2; i <= 100; i++)

		a[i].add(a[i-1],a[i-2]);
    
    while(1)
    {
		cin >> in1 >> in2;
		if( (strlen(in1) == 1 && in1[0] == '0') && ((strlen(in2) == 1 && in2[0] == '0')))
			break;

		count = 0;

		for( i = 2; i <= 100; i++)
		{
			strcpy(out,a[i].print());
            int a1 = compare(out,in1);
			int b1 = compare(out,in2);
			if( a1 >= 1 && b1 <= 0)
				count++;
		}
        
		cout << count << endl;
           
    }
    



	return 0;
}