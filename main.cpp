#include "network.h"
#include <string>
#include <fstream>

using namespace std ;

int main() 
{	
	cout<< " main " << endl ;
	Network net ;
	net.interaction() ;
return 0 ;
}
/*
int main () 
{
	string const potentiels("potentiels");
	ofstream sortie(potentiels.c_str()) ;
	
	Neurone n ;

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
	 
sortie.close() ;

	
return 0 ;
}
*/

