#include <iostream> 
#include <vector> 
#ifndef NEURONE_H
#define NEURONE_H

using namespace std ;

class Neurone {	
	private :
	
	double V_ ;
	int spikes_ ;
	vector<double> times_ ;
	const double V_thr = 20  ;
	const double tau = 20 ;
	const double c = 1 ;
	const double R = tau/c ;
	double J = 0.2 ;
	double h= 0.1 ;
	int t = 1 ;
	double D = 1.5 ; //delay
	vector<int> buffer ;
	int n;  // nombre de pas
	 
	public :
	
	// constructeur
	Neurone ();   
	
	double getV() const ;
	vector<double> get_times()  ;
	int get_spikes () const ;
	void setV (double v)  ;
	void set_times (vector<double> times);
	void set_spikes (int spikes) ; 
	bool update(double t, double I,int n) ;
	void receive (int t);
	void set_buffer (vector<int> buffer )  ;
	//vector<double> get_potentiels()  const ;
} ;

#endif 	
	 
	  
