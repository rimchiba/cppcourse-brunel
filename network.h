#include <iostream> 
#include <vector> 
#include "neurone.h"
#ifndef NETWORK_H
#define NETWORK_H

using namespace std ;

class network {
	
	private :
		Neurone n1 ;
		Neurone n2 ;
		int temps ; // temps global
		
	public :
		void interaction () ;
} ;

#endif 	
