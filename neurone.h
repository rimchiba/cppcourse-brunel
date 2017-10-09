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

	 
	public :
	
	// constructeur
	Neurone ();
	
	double getV() const ;
	vector<double> get_times()  ;
	int get_spikes () const ;
	void setV (double v)  ;
	void set_times (vector<double> times);
	void set_spikes (int spikes) ; 
	void update(double t, double I , double h) ;
} ;

#endif 	
	 
	  
