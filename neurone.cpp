#include <iostream> 
#include "neurone.h" 
#include <vector> 
#include <cmath>

using namespace std ; 

/*Neurone::Neurone (double V ,int spikes, vector<double> times) 
	: V_ (V), spikes_(spikes),times_(times)
{}*/


double Neurone::getV() const {
	return V_;
}

int Neurone::get_spikes () const {
	return spikes_ ;
}

vector<double> Neurone::get_times()  {
	return times_ ;
}

void Neurone::setV (double V) {
	V_ = V ;
}

void Neurone::set_spikes (int spikes) {
	spikes_ = spikes ;
}

void Neurone::set_times (vector<double> times )  {
	times_ = times ;
}

Neurone::Neurone ()
: V_(0),spikes_(0)
{}

/*vector<double> Neurone::get_potentiels() const {
	return potentiels ;
}*/

void Neurone::update (double t,double I, double h ) {
	
	double refractory(0.0);
	
	 if (V_ > V_thr) 
	 {
		 ++ spikes_ ;
		 times_.push_back(t) ;
		// potentiels.push_back(V_) ;	
		 V_ = 0.0 ;
		 refractory = ( t/h ) ;
	}
	 if ( t < refractory )
	 {
		 V_ = 0.0 ;	
		 refractory -= h ; 

	 } else {
		 V_ = exp (-h/tau)*V_ + I*R*(1-exp(-h/tau)) ; 
	 }
}
	
	
			
			
	











	
