#include "network.h" 

#include <fstream>
#include <iostream>

using namespace std ; 

//! constructor
/*!filling out the matrice  
 *  with 0 or 1
 *  the neurons with 1 are the targets 
 */
 
 Network:: Network()
 :neurones(12500), network ( 12500 ,vector<int>(12500) ) 
{
	// double n_ext = eta * C_ext * (Vteta / C_ext * 0.1 * tau);
	// J_inh = -g*J_exi ;

	for ( size_t i(0) ; i < 12500 ; ++ i)
	{
		for (int j(0) ; j < C_exi ; ++j )
		{
			network[i][uniform(0,9999)] += 1 ;
		}
		
		for ( int j(0) ; j < C_inh ; ++ j)
		{
			network[i][uniform(10000,12499)] += 1 ;
		}
	}		
			
	/// filling out the vector of pointers on neurones
	/// with 10000 excitators and
	/// 2500 inhibitors
		
	for(int i(0) ; i < N_exi ; ++ i)
	{ neurones[i] = (new Neurone(J_exi) ) ;  }//10000 neurones excitateurs J= 0.1

	for (int i(N_exi) ;i< N_tot ; ++ i)
	{ neurones[i] = (new Neurone(J_inh)) ; } //2500 inhibiteurs J = -0.5
}


void Network::interaction()
{	
	ofstream sortie("plot") ;
	int temps = 0 ;            /* clock */
	int t_final = 10000   ;    /* Time of stop */
	
	while ( temps < t_final )
   {
		for (size_t n(0) ; n < neurones.size() ; ++ n )
		{
		    if (neurones[n]->update(temps) ) 
			{	

				for (size_t j(0) ; j < neurones.size() ; ++ j)
				    {
						if ( network[j][n] > 0)
						{   cout << " if " << endl; 
							neurones[j]-> receive (temps+15, network [j][n] * neurones[n]->get_J());
							cout << temps << "  " << n << endl ;
							if (sortie)
							{
								sortie << temps << "   "<< n << endl; 	
								sortie.flush() ;
							}
						else cerr << " erreur" << endl ;
						}
					}
			}
		}
	++ temps ;
   }	
}
			


/// method uniform to choose random integer

int Network::uniform(int a, int b)
{
	static random_device rd; 
	static mt19937 gen (rd()) ;
	static uniform_int_distribution<> dis(a,b) ;
	return dis(gen) ;
}


/// in each step, update all neurons
/// and for each neuron see if it is spiking 
/// and if it has targets
/// than they receive the spike after a certain delay
/// write the time and the neuron spiking in plot 

	
//! destructeur.
/*! delete all the neurons  to nullptr.
 */
        	  
        	 
Network::~Network()
{
	for(int i(0) ; i < 12500 ; ++i)
	{
		 delete  neurones[i]  ;
		 neurones[i] = nullptr ;
	}
	neurones.clear() ;
}
	
	
	

	
