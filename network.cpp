#include <iostream> 
#include "network.h" 
#include "neurone.h" 

using namespace std ; 

	double b ; //stop time
	double t ; //start time
	double I1 ;
	double I2 ;
	double h = 0.1 ;
	double D = 1.5 ; //delay

void network::interaction ()
{
	cout << "insert a start time" << endl ;
	cin >> temps ;

	cout <<"insert a stop time " << endl ; 
	cin >> b ;

	cout <<"insert external current 1" << endl ;
	cin >> I1 ;
	
	cout <<"insert external current 2" << endl ;
	cin >> I2 ;
	
	while ( temps * h < b )
	{
		if ( n1.update(t,I1,temps) ) 
		{
			n2.receive(temps) ;	
			cout<< " update n1 " << endl ; 
		}
		if ( n2.update(t,I2,temps) )
		{
			n1.receive(temps) ;	
			cout << " update n2" << endl;
		}
	
	temps ++ ;
		
	cout << "potentiel 1   " << n1.getV() <<endl;
	cout << "potentiel 2   " << n2.getV() <<endl; 
		
	}
} 	

	

	
