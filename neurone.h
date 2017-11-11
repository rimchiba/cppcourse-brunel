#ifndef NEURONE_H
#define NEURONE_H
#include <iostream> 
#include <vector> 
#include <cmath> 
#include <random> 
#include <assert.h>

///! Neurone class 
   /*! Class representing one neuron 
    * each time step, the potential of the neuron is updated
    * each neuron is caracterised by its J
    * the buffer save the value of J for a neuron target to receive it
    */
    
       
class Neurone 
{	
	private :
	
	 double V_ = 0.0 ;                   /* membrane potential */
	 int spikes_ ;                 /* number of spikes */
	 std::vector<double> times_ ;  /* record of the time when there is a spike */ 
	 static constexpr double V_thr = 20  ;    /* potential threshold */ 
	 static constexpr double tau = 20 ;
	 static constexpr double c = 1 ;
	 double n_thr = 2  ;
	 static constexpr double R = tau/c ;
	 static constexpr double h= 0.1 ;
	 int d = 15 ;   
	 double J = 0.1;            //delay
	 double n_ext ;
	 std::vector<double> buffer ;     /* ring buffer to save a spike after  a delay D */
	 static constexpr double C_ext = 1000 ;   /* number of targets from the brain */
	
	 
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
	void set_buffer (std::vector<double> buffer )  ;
	
	//! update function
	/*! Update the membrane potential of 1 neuron
	 * returns if there is a spike or not */
	bool update(int t) ;
	int random_poisson (int r);
	
	
	//! Receive function
	/*! a neuron receives a signal from another neuron 
	 * by using the ring buffer */
	void receive (int t,double j);

} ;

#endif 	
	 
	  
