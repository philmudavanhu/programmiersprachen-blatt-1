#define CATCH_CONFIG_RUNNER
#include "catch.hpp"
#include <cmath>

using namespace std;


double Mile = 0;
double Kilo = 1.60934;

float Pi = 3.14159265;
int Two = 2;

int gcd(int a, int b) 
	{
		return b == 0 ? a : gcd(b, a % b);
	}
 
int checksum(int a)
{
	int sum = 0;
    while (a != 0)
    {
        sum = sum + a % 10;
        a = a / 10;
    }
    return sum;
}

int sumMultiples(int a, int b)
{
	int sum = 0;
	for( int i = 1; i <= 1000; i = i + 1 )
		{			       
			if (i%a==0 && i%b==0 )
			   	{
			   	   	sum = sum + i;
			   	}
		 }

	 return sum;
}

float Volume(int r, int h)
	{
	float Volume = (Pi * (r * r) * h);
		return Volume;
	}


float Area(int r, int h)
	{
		float Area = (Two * Pi * r * h) + (Two * Pi * (r * r));
		return Area;
	}

double mileToKilometer(double Mile)
	{
		double Kilometer = Mile * Kilo;
		return  Kilometer;
	}







TEST_CASE("describe_gcd", "[gcd]")
	{
		REQUIRE(gcd(2,4) ==  2);
		REQUIRE(gcd(6,9) ==  3);
		REQUIRE(gcd(3,7) ==  1);
	}

TEST_CASE("checksum","[checksum]")
	{
		REQUIRE( checksum(112601) == 11 );
		REQUIRE( checksum(123456) == 21 );
		REQUIRE( checksum(101010) == 3 );
	}


TEST_CASE("sumMultiples","[sumMultiples]")
	{
		REQUIRE( sumMultiples (3,5) == 33165);
		REQUIRE( sumMultiples (1,5) == 100500);
		REQUIRE( sumMultiples (1,3) == 166833);
	}

TEST_CASE("Volume","[Volume]")
	{
		REQUIRE( Volume (3,5) == 141.37167f);
		REQUIRE( Volume (4,6) == 301.5929f);
		REQUIRE( Volume (9,2) == 508.93802f);
	}


TEST_CASE("Area","[Area]")
	{
		REQUIRE( Area (7,5) == 527.7876f);
		REQUIRE( Area (2,5) == 87.9646f);
		REQUIRE( Area (8,3) == 552.92029f);
	}

TEST_CASE("mileToKilometer ","[mileToKilometer]")
	{
		REQUIRE( mileToKilometer(1) == 1.60934 );
		REQUIRE( mileToKilometer(10) == 16.0934 );
		REQUIRE( mileToKilometer(100) == 160.934 );
	}




int main(int argc, char const *argv[])
{
	double Mile = 0;
	cout<< "________________________Convert Miles to Kilometers__________________________" << endl;
	cout<< "Please give the Number of Miles you want to convert to Kilometers : ";
	 
	 	cin >> Mile;
	 	if (Mile >= 0.0000000)
	 {
	 	cout << Mile << "mi(s) = " << mileToKilometer(Mile) << "km(s)" <<endl;
	 	cout<< "_____________________________________________________________________________" << endl;
	 }
		

	return Catch::Session().run( argc, argv);
}