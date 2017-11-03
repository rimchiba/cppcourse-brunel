#ifndef NETWORK_H
#define NETWORK_H
#include "neurone.h"
#include <random>
#include <vector>

using namespace std ;

class Network {
	
	private :
		vector<vector <int> > network ;
		//vector< vector<int> > network(taille,vector<int>(taille));
		std::vector<Neurone*> neurones ; 

		int temps  ; // temps global
		double b ; //stop time
		double t ; //start time
		double I1 ;
		double I2 ;
		double h = 0.1 ;
		double D = 1.5 ; //delay
		const double J_exi = 0.1 ;
		const double J_inh = - 0.5 ;
		const double N_inh = 2500 ; 
		const double N_exi = 10000;
		const double N_tot = N_inh + N_exi ;
		const double C_exi = 1000 ;
		const double C_inh = 250 ;
		const double C_tot = C_inh + C_exi ;
		

		
	public :
		Network () ;
		void interaction () ;
		~Network() ;
		int uniform (int a, int b) ;
} ;

#endif 	
