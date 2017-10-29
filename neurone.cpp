#include <iostream> 
#include "neurone.h" 
#include <vector> 
#include <cmath>

using namespace std ; 


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
{
	for ( int i(0); i< (D/h)+1 ;++i) 
	{
		buffer.push_back(0) ;
	}
}

void Neurone::set_buffer (vector<int> buffer )  {
	buffer = buffer ;
}

bool Neurone::update (double t,double I,int n) {
	
	double refractory (0.0);
	bool spike ;
	
	 if (V_ > V_thr) 
	 {
		 cout << " if 1 update " << endl ;
		 ++ spikes_ ;
		 times_.push_back(t*h) ;
		 spike = true ;
		 V_ = 0.0 ;
		 refractory = ( t/h ) ;
		
	}
	 if ( t < refractory )
	 {
		 cout << " if 2 update " << endl; 
		 V_ = 0.0 ;	
		 refractory -= h ; 
		 spike = false ;

	 } else {
		 cout << " if 3 update " << endl ;
		 J = buffer[n % ((int)(D/h) + 1)]  ;
		 buffer[n % ((int)(D/h) + 1)] = 0 ;
		 V_ = exp (-h/tau)*V_ + I*R*(1-exp(-h/tau)) + J ; 
		 spike = false ;
	 }
	 return spike ;
	 ++n  ;
	 cout <<" fin update " << endl ; 
}
	
		
void Neurone::receive (int t)
{
	buffer[t+ (int)(D/h) % (int) (D/h)+1] += J ;
}
			
			
	











	
