#include "network.h" 

#include <fstream>
#include <iostream>

using namespace std ; 

//! In this class we create a network of many neurons with pointers
/*! and we create a matrice of integers to represent the targets of each neuron
 * the constructor :
 * filling out the matrice  
 *  with integers.
 *  the neurons with a number different of zero are the targets 
 * 
 * the constructor has 2 parameters 
 * e to determinate V_ext
 * and g to determinate J inhibiteur
 */
 
 Network:: Network(double e,int g)
 :neurones(12500), network ( 12500 ,vector<int>(12500) ) 
{
	J_inh = -g*J_exi ;
	V_ext = e*C_ext*V_thr/(J_exi*C_exi*tau);
	
	static random_device rd; 
	static mt19937 gen (rd()) ;
	static uniform_int_distribution<> dis_exi(0,9999) ;
	static uniform_int_distribution<> dis_inh(10000,12499) ;


	for ( size_t i(0) ; i < 12500 ; ++ i)
	{
		for (int j(0) ; j < C_exi ; ++j )
		{
			network[i][dis_exi(gen)] += 1 ;
		}
		
		for ( int j(0) ; j < C_inh ; ++ j)
		{
			network[i][dis_inh(gen)] += 1 ;
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


//! interaction method
/*! We go throught all the neurons, for each neuron we see if it has targets
 *  if it spikes, all its targets receive its J
 *  after the delay D 
 *  write the time and the neuron spiking in "plot"
 */

void Network::interaction()
{	
	
	ofstream sortie("plot") ;
	int temps = 0 ;            /* clock */
	int t_final = 1000   ;    /* Time of stop */
	
	while ( temps < t_final )
   {
		for (size_t n(0) ; n < neurones.size() ; ++ n )
		{
		    bool spike = neurones[n]->update(temps) ;
		    if (spike)
			{	
				/*if (sortie)
				{
					sortie << temps << "   "<< n << endl;
				    sortie.flush() ;
				}
				else cerr << " erreur" << endl ;*/
				
				for (size_t j(0) ; j < neurones.size() ; ++ j)
				{	
					if ( network[j][n] > 0)
					{   
						neurones[j]-> receive (temps+15, network [j][n] * neurones[n]->get_J());
							
					}
				}
			}
		}
	++ temps ;
   }	
}

	
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
	
	
	

	
