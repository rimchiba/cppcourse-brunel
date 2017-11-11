#include "network.h"
#include <string>
#include <fstream>

using namespace std ;

int main() 
{	
	int g ;
	double e ;
	
	cout << " entrer la valeur de g " << endl ; 
	cin >> g ;
	
	cout << " entrer la valeur de e " << endl; 
	cin >> e ;

	Network net(e,g) ;
	net.interaction() ;
	
return 0 ;
}
