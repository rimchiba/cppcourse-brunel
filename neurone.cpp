#include "neurone.h" 

using namespace std ; 

///! Constructor 
/*! to fill out the buffer 
 * of D/h + 1 size with zeros 
 * and caracterize the neuron
 * if it is inhibitory or excitatory
 */
 
Neurone::Neurone (double j)
: V_(0),spikes_(0),J(j),buffer(16,0)
{
	for ( int i(0); i< d+1 ;++i) 
	{
		buffer.push_back(0) ;
	}
	
}

/* Getters */ 

double Neurone::getV() const 
{	
	return V_;
}

int Neurone::get_spikes () const 
{
	return spikes_ ;
}

double Neurone::get_J () const 
{
	return J ;
}

vector<double> Neurone::get_times()  
{
	return times_ ;
}

/* Setters  */
void Neurone::setV (double V) 
{
	V_ = V ;
}

void Neurone::set_spikes (int spikes) 
{
	spikes_ = spikes ;
}

void Neurone::set_times (vector<double> times )  
{
	times_ = times ;
}

void Neurone::set_buffer (vector<double> buffer )  
{
	buffer = buffer ;
}


// destructor
Neurone::~Neurone(){} 
 
int Neurone::random_poisson (int r) //to generate random values for the potential
{
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution<> poisson(r);
	return poisson(gen) ;
} 

///! updating a neuron in a time t 
/*! and return if it spikes 
 * if there is a spike the potential
 * is set to zero */
bool Neurone::update (int t) 
{
	bool spike = false ;
	
	if( ( !times_.empty()) and (t*h - times_.back() < 2) )   // if the membrane is refractory
	{
		V_ = 0.0 ;
	}
	else
	{
		 V_ = exp (-h/tau)*V_  +  buffer[t % (d + 1)] + random_poisson(0.2*h*C_ext)*J;	       
		
		if (V_ > V_thr)              // if it spikes
			{
				spike = true ;
				V_ = 0.0 ;
				++ spikes_ ;
				times_.push_back(t*h) ;	
			}
	}		
	
	buffer[t % (d + 1)] = 0 ;   // empty the buffer after using the value inside
	return spike ;
}	

/*spikes will be received after a delay D */ 

void Neurone::receive (int t,double J)
{
	buffer[ (t+d) % (d+1)] += J ;
}
			
			
	











	
