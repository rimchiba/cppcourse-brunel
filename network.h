#ifndef NETWORK_H
#define NETWORK_H
#include "neurone.h"
#include <random>
#include <vector>

using namespace std ;

///! Network class :
		/*! the network is a matrice, filled with the
		 * number of interactions between neurons 
		 * and we have a vector of neurons, if two neurons interacts 
		 * and one of them is spiking, the other receives J. */
		 

class Network {
	
	private :
		vector<vector <int> > network ;
		std::vector<Neurone*> neurones ; 

		int temps  ;      // global clock
		double h = 0.1 ;
		double D = 1.5 ;  //delay
		const double J_exi = 0.1 ;		 /* J of excitatory neurons */
		const double J_inh = - 0.5 ;     /* J of inhibitory neurons */
		const double N_inh = 2500 ;  	 /* number of neurons */ 
		const double N_exi = 10000;
		const double N_tot = N_inh + N_exi ;
		const double C_exi = 1000 ;		/* number of neuron targets */
		const double C_inh = 250 ;
		const double C_tot = C_inh + C_exi ;
		

		
	public :
		Network () ;
		void interaction () ;
		~Network() ;
		int uniform (int a, int b) ;
} ;

#endif 	
