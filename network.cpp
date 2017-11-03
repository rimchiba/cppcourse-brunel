#include "network.h" 

using namespace std ; 

 Network:: Network() 
 :network ( 12500 ,vector<int>(12500) ) ,neurones(12500)
{
	cout << " debut constructeur " << endl ;
	int targets_exi (0) ;
	int targets_inh (0) ;
	for (size_t i(0) ; i <= 12500 ; ++i )
	{
		while ( targets_exi < C_exi ) 
		{
			for ( size_t j(0) ; j < N_exi ; ++j )
			{	
				network[i][j] = uniform (0,1) ;
				if ( network [i][j] == 1 )
				{
					targets_exi += 1  ;
				} 
			}
		}
	
		while ( targets_inh < C_inh )
		{
			cout << " dkhal while 2" << endl ;
			for (size_t j(10000) ; j < 12500 ; ++j )
			{
				network[i][j] = uniform(0,1) ;
				if ( network [i][j]  == 1 )
				{
					targets_inh += 1 ;
				}
			}
		}
		cout << " khraj mel while 2 " << endl ;
	}

	for(int i(0) ; i < 10000 ; ++i)
	neurones[i] = (new Neurone(0.1)) ; // 10000 neurones excitateurs J= 0.1

	for (int i(10000) ; i < neurones.size() ; ++ i)
	neurones[i] = (new Neurone(-0.5)) ; // 2500 inhibiteurs J = -0.5

/*	for ( size_t i(0) ; i <= 12500 ; ++i)
	{
	    	  Neurone* n; 
        	  neurones.push_back(n);
    }*/
}
        	  
Network::~Network()
{
	for(int i(0) ; i < 12500 ; ++i)
	{
		 delete  neurones[i]  ;
	}
}
	


int Network::uniform (int a, int b)
{
	static random_device rd; 
	static mt19937 gen (rd()) ;
	static uniform_int_distribution<> dis(a,b) ;
	return dis(gen) ;
}

	
void Network::interaction ()
{
	cout << "insert a start time" << endl ;
	cin >> temps ;

	cout <<"insert a stop time " << endl ; 
	cin >> b ;

	/*cout <<"insert external current 1" << endl ;
	cin >> I1 ;
	
	cout <<"insert external current 2" << endl ;
	cin >> I2 ;
	
/*	for (size_t i(0) ; i < neurones.size() ; i++ )
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
	
	while ( temps * h < b )
	{
		cerr<<" dkhal fel while  "<< endl ;
		for (size_t i(0) ; i < 12500 ; i++ )
		{
			cout <<" for 1 " << endl;
			for ( size_t n(0) ; n < N_exi ; ++ n )
			{
				cout <<" for 2 " << endl;
				if ( network [i][n] == 1 )
				{	
					if ( neurones[n]->update(temps,0) )
					 {  
						neurones[i]-> receive (temps, J_exi);					
					 }	  
				}
			}
		cout <<  " khraj mel for thenia " << endl ;
			for ( size_t n (N_exi) ; n < 12500 ; ++ n )
			{
				cout <<" for 3 " << endl;
				if ( ( neurones[n]->update (temps,0) ) and ( network [i][n] == 1 ) )
				{
					neurones[i]-> receive (temps, J_inh);	
				}
			}
		}			
	++ temps ;
	}
	
}	
		
		
		
		
		
		
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
	

	

	
