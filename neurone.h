#ifndef NEURONE_H
#define NEURONE_H
#include <iostream> 
#include <vector> 
#include <cmath> 
#include <random> 
#include <assert.h>

///! Neurone class 
   /*! Class representing one neuron 
    */
       
class Neurone 
{	
	private :
	
	 double V_ ;                   /* membrane potential */
	 int spikes_ ;                 /* number of spikes */
	 std::vector<double> times_ ;  /* record of the time when there is a spike */ 
	 const double V_thr = 20  ;    /* potential threshold */ 
	 const double tau = 20 ;
	 const double c = 1 ;
	 const double R = tau/c ;
	 double J ;
	 double h= 0.1 ;
	 double D = 1.5 ;              //delay
	 std::vector<int> buffer ;     /* ring buffer to save a spike after  a delay D */
	 const double C_ext = 1000 ;   /* number of targets from the brain */
	 const double V_ext = 2 ;
	 
	public :
	
	// constructor and destructor
	Neurone (double j);
	~Neurone();    
	
	
	/*    Getters    */
	double getV() const ;
	std::vector<double> get_times()  ;
	int get_spikes () const ;
	double get_J() const ;
	
	/*    Setters    */
	void setV (double v)  ;
	void set_times (std::vector<double> times);
	void set_spikes (int spikes) ; 
	void set_buffer (std::vector<int> buffer )  ;
	
	//! update function
	/*! Update the membrane potential and 
	 * returns if there is a spike or not */
	bool update(int t) ;
	
	
	//! Receive function
	/*! a neuron receives a signal from another neuron 
	 * by using the ring buffer */
	void receive (int t,double j);
	
	/* poisson destribution to geneate random connectivity between neurons */ 
	int random_poisson (int r) ;
} ;

#endif 	
	 
	  
