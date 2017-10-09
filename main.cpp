#include <iostream>
#include "neurone.h"
#include "neurone.cpp" 
#include <string>
#include <fstream>

using namespace std ;


int main () 
{
	string const potentiels("potentiels");
	ofstream sortie(potentiels.c_str()) ;
	
	Neurone n ;
	Neurone n1;

    double b ; //stop time
	double t ; //start time
	double I ;
	double h = 0.1 ;
    

	cout << "insert a start time" << endl ;
	cin >> t ;

	cout <<"insert a stop time " << endl ; 
	cin >> b ;

	cout <<" insert external current" << endl ;
	cin >> I ;

	   
	while (t < b)  
	{
		n.update(t,I,h) ;
		t+=h ;
	
	if (sortie)
	sortie << n.getV() << endl;
	else cout <<"false" ;
	}
	 
/*while (t < b)  
	{
		n1.update(t,I,h) ;
		t+=h ;
	}
	
for (unsigned int i(0) ; i < n.get_potentiels::size() ; i++)
{
	cout << n1.get_potentiels[i] - n.get_potentiels[i] << endl;
}*/

sortie.close() ;	
return 0 ;
}


