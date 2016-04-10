
#include<iostream.h>
#include<conio.h>
#include<fstream.h>
#include<time.h>
#include<stdio.h>
#include<ctype.h>
#include<stdlib.h>

//  using namespace :: std;

typedef unsigned long long int lg;



ifstream Text;
ofstream Cip;
ofstream Com;


lg n,e,k;

ifstream f;


lg ModPow(lg base, lg exponent, lg mod)
{
	lg c=1, eprime=0;


	while( eprime < exponent )
	{
		++eprime;

		c = (base * c) % mod;

	}

    return c;

}


void getKeys()
{
	f.open("Keys.txt");

	f >> n;

	f >> e;

	f.close();

}

lg Encrypt(lg data)
{
	lg c=1,d;

	d = ModPow(data, e, n);

	cout << endl << " D : " << d << endl;

	return d;

}

void main()
{

	clrscr();

	Text.open("Ptext.txt");
	Cip.open("Cipher.txt");
	Com.open("ComKey.txt");


	lg b,ec,commonKey=0;
	char a;

	getKeys();

	cout << "\n N : " << n << " \n E :  " << e;

	cout<<"\n\n Got Keys\n";


	srand( (unsigned) time(NULL) );



	commonKey = ( rand() % 1000 +1 );

	cout << "\n Common Key :  " << commonKey;

	cout << "\n Encrypted Common Key : " << Encrypt(commonKey) << "\n";

	Cip << Encrypt(commonKey) << " ";

	while(Text.get(a))
	{
		cout << endl << a << endl;

		if(a ==' ')
		{   cout << " SPACE \n";
			Cip << "-1" << ' ';
		}

		else
		{
			b=a;

			cout << "\n Character \n" << b << endl;
			ec = b * commonKey;
			cout << endl << ec;
			Cip << ec << ' ';                                             // Check if it is going to the file.

		}

	    cout<<"\n";
	   getch();

	}

	getch();

}


