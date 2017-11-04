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
	int targets_exi (0) ;
	int targets_inh (0) ;
	
	// cibles excitatrices 
	for ( size_t i(0) ; i < 12500 ; ++i)
	{
		while ( targets_exi < C_exi ) 
		{
			for ( size_t j(0) ; j < N_exi ; ++j )
			{	
				network[i][j] = uniform (0,C_exi) ;
				if ( network [i][j] > 0 )
				{
					targets_exi += network[i][j]  ;
				} 
			}
		}
	// cibles inhibitrices 
		while ( targets_inh < C_inh )
		{
			for (size_t j(10000) ; j < 12500 ; ++j )
			{
				network[i][j] = uniform(0,C_inh) ;
				if ( network [i][j]  > 0 )
				{
					targets_inh += network[i][j] ;
				}
			}
		}
	}
	/// filling out the vector of pointers on neurones
	/// with 10000 excitators and
	/// 2500 inhibitors
		
	for(int i(0) ; i < 10000 ; ++i)
	neurones[i] = (new Neurone(J_exi) ) ; //10000 neurones excitateurs J= 0.1

	for (int i(10000) ;i< neurones.size() ; ++ i)
	neurones[i] = (new Neurone(J_inh)) ; // 2500 inhibiteurs J = -0.5
}

//! destructeur.
/*! delete all the neurons  to nullptr.
 */
        	  
        	 
Network::~Network()
{
	for(int i(0) ; i < 12500 ; ++i)
	{
		 delete  neurones[i]  ;
	}
	neurones.clear() ;
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
	
void Network::interaction()
{
	ofstream sortie("plot") ;
	int temps = 0 ;           /* clock */
	int t_final = 10000   ;    /* Time of stop */
	
	while ( temps < t_final) 
	{
		for (size_t n(0) ; n < 12500 ; n++ )
		{
			cout << " parcours des neurones " << endl ;
		    bool spike = neurones[n]->update(temps) ;
		    cout << " updater le neurone " << endl ;
		    
		    if (spike) 
			{
				for ( size_t i(0) ; i < 12500 ; ++ n )
				{
					if ( network [i][n] > 0 )
					{
						neurones[i]-> receive (temps,network [i][n]* J_exi);
						if (sortie)
						{
							sortie << temps << "   "<< n << endl; 	
							sortie.flush() ;
						}
						else cerr << " erreur" << endl ;						
					}	  
				}
		   
			    for ( size_t i (N_exi) ; i < 12500 ; ++ i )
			    {
					 
					if  ( network [i][n] > 0 )
					{	
					neurones[i]-> receive (temps, network [i][n] *J_inh);	
					cout << " if " << endl ;
					if (sortie)
						{
						sortie<< temps << "   " << n << endl;
						sortie.flush() ;
						}
					else cerr << "erreur " << endl ; 
				    }
				}
			}
		}	
	///incrementing the time 	
	++ temps ;
	cout << " fin while " << endl ;
	}
sortie.clear();
}
	
	
	
	
	
	
	
	
	
	
	/*for (size_t i(0) ; i < neurones.size() ; i++ )
	{
		neurones.get_cibles.push_back[uniform(1,10000)] += 1 ;
		
		
		for (size_t j(0) ; j < 1000 ; j++ )
		{
			connexion[i][uniform(1,10000)] += 1 ;
		}
		for ( size_t j(0) ; j < 250 ; j++ )
		{
			connexion[i][uniform(10001,12500)] += 1 ;
		}
	}
		
*/	
		
		
		
		
		
		/*if ( n1.update(t,I1,temps) ) 
		{
			cout << "le temps de spike de 1 est  " << temps << endl ;
			n2.receive(temps) ;	
			cout<< " update n1 " << endl ; 
		}
		if ( n2.update(t,I2,temps) )
		{
			cout << "le temps de spike de 2 est  " << temps << endl ;
			n1.receive(temps) ;	
			cout << " update n2" << endl;
		}
	
	temps ++ ;
		
	cout << "potentiel 1   " << n1.getV() <<endl;
	cout << "potentiel 2   " << n2.getV() <<endl; 
		
	}*/
	

	

	
