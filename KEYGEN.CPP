
#include<iostream.h>
#include<conio.h>
#include<stdlib.h>
#include<time.h>
#include<fstream.h>
#include<process.h>


// using namespace :: std;


ofstream SecretKeys;
ofstream PublicKeys;

typedef unsigned long long lg;

lg  n,c,d,totient,e;

int isPrime(lg r)
{
	int i;

	for(i=2;i<=r-1;i++)
	{
		if(r%i==0)
			return 0;

	}

	return 1;

}


lg randomPrime(lg p)
{
	lg r=6;

	int flag=0;
	++p;

	srand( (unsigned) time(NULL) );

	while(!isPrime(r))
	{
		r= rand() % 100 + p;
	}


    return r;

}



lg randomPrime()
{

	lg r=6;

	int flag=0;

	srand( (unsigned) time(NULL) );

	while(!isPrime(r))
	{
		r= rand() % 10;
	}


    if( r== 1)
	{
		r=randomPrime();
	}

	return r;

}

lg GenE(lg n)
{

	lg r;

	srand( (unsigned) time(NULL) );

	do
	{
	     r = rand() % 10 + 2;

	}	while( n%r==0);

	if( r >= totient )
	{
		r = GenE(n);
	}

	cout << endl << endl << r << endl;

	return r;

}

void KeyGen()
{
	lg p=0,q=0;


		p = randomPrime();

		q = randomPrime(p);

		cout << p << endl;
		cout << q << endl;

		getch();

		n = p*q;

	    cout<<"\n"<<n;


	totient = (p-1)*(q-1);

	cout << "\t" << totient;


	e = GenE(n);



	int k=2;
	double test;


	do
	{
			d = ((k * totient) + 1)/e;
			test = ((k * totient) + 1);

			test /= e;

			cout << "D " << d << " test " << test << " k " << k << endl;



			if ( k >= 10)
			{ e = GenE(n); k=2; }


			++k;

	}while((test-d) != 0 || d>500 );

	cout << endl << d;

	cout << " \n\n Final Values ";

	cout << "\n N : " << n;
	cout << "\n Totient : " << totient;
	cout << "\n e : " << e;
	cout << "\n d : " << d;





}


void main()
{

	clrscr();

	cout<<"enter Keygen\n";

	KeyGen();

	cout<<"\nexit Keygen\n";

	SecretKeys.open("Secret.txt");
	PublicKeys.open("Keys.txt");

	SecretKeys << n << " " << d;
	PublicKeys << n << " " << e;


	getch();

}

