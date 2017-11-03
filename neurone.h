#ifndef NEURONE_H
#define NEURONE_H
#include <iostream> 
#include <vector> 
#include <cmath> 
#include <random> 
#include <assert.h>

class Neurone {	
	private :
	
	double V_ ;
	int spikes_ ;
	std::vector<double> times_ ;
	const double V_thr = 20  ;
	const double tau = 20 ;
	const double c = 1 ;
	const double R = tau/c ;
	double J ;
	double Iext ;
	double h= 0.1 ;
	int t = 1 ;
	double D = 1.5 ; //delay
	std::vector<int> buffer ;
	//int n;  // nombre de pas
	const double C_ext = 1000 ;
	const double V_ext = 2 ;
	 
	public :
	
	// constructeur
	Neurone (double j);
	~Neurone();    
	
	double getV() const ;
	std::vector<double> get_times()  ;
	int get_spikes () const ;
	void setV (double v)  ;
	void set_times (std::vector<double> times);
	void set_spikes (int spikes) ; 
	bool update(double t, double I) ;
	void receive (int t,double j);
	double get_J() const ;
	void set_buffer (std::vector<int> buffer )  ;
	int random_poisson (int r) ;
} ;

#endif 	
	 
	  
