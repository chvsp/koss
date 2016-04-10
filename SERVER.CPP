
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>

// using namespace :: std;


ofstream Decry;
ifstream Cip;
ifstream SecretKeys;



typedef unsigned long long lg;

lg  n,c,d,totient,e,commonKey;

char z;


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


lg Decrypt(lg data)
{
	lg c=1,dtemp;

	dtemp = ModPow(data, d, n);


	return dtemp;

}



void main()
{
	clrscr();

	lg k,dec,temp;


	SecretKeys.open("Secret.txt");
	Decry.open("Decpt.txt");
	Cip.open("Cipher.txt");


	SecretKeys >> n;
	SecretKeys >> d;

	Cip >> temp;



	commonKey= Decrypt(temp);

	cout << n << endl << d << endl << temp << endl << commonKey;

	char a;

	long int input;

	while(Cip >> input)
	{
		cout <<"\nInput : " << input;


		if(input == -1)
		 {
		 cout<< endl << " Entered if";

		    Decry << " ";
		   continue;
		 }

		dec = input/commonKey;

		z=dec;

		cout << endl << dec << endl << z << endl;

		Decry << z;

		getch();


	}


	getch();


}




