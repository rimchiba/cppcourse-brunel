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

    double b ; //stop time
	double t ; //start time
	double I ;
	double h = 0.1 ;
    //

	cout << "insert a start time" << endl ;
	cin >> t ;

	cout <<"insert a stop time " << endl ; 
	cin >> b ;

	cout <<" insert external current" << endl ;
	cin >> I ;

	   
	while ( t < b)   {
		
	 if (!n.get_times().empty() and t-n.get_times().back() > 0.1  ) 
	 {
		 //cout<< "1" << endl ;
		 n.update(t,I,h) ;
		 t+=h ;
		 
	 } else
	
		{
		// cout<<"2" << endl ;
		 t+=h ; 
		 n.update(t,I,h);
		 
		}
	
	if (sortie)
	sortie << n.getV() << endl;
	else cout <<"false" ;
	
	}
	 
sortie.close() ;	
return 0 ;
}


