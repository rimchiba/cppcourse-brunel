#include "neurone.h" 

using namespace std ; 

///! Constructor 
/*! to fill out the buffer 
 * of D/h + 1 size with zeros 
 */
 
Neurone::Neurone (double j)
: V_(0),spikes_(0),J(j),buffer(16,0)
{
	for ( int i(0); i< (D/h)+1 ;++i) 
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

void Neurone::set_buffer (vector<int> buffer )  
{
	buffer = buffer ;
}

/* generating random values */
int Neurone::random_poisson (int r)
{
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution<> poisson(r);
	return poisson(gen) ;
}

// destructor
Neurone::~Neurone(){} 

///! updating a neuron in a time t 
/*! and return if it spikes 
 * if there is a spike the potential
 * is set to zero */
 
bool Neurone::update (int t) 
{
	bool spike = false ;
	double refractory (0.0);
	
	if( ( !times_.empty()) and (t*h - times_.back() < V_thr) ) 
	{
		V_ = 0.0 ;
	}
	else
	{
		J = buffer[t % ((int)(D/h) + 1)]  ;
		V_ = exp (-h/tau)*V_  + J + random_poisson(V_ext*C_ext*h*J); 
	     if (V_ > V_thr) 
		{
			++ spikes_ ;
			times_.push_back(t*h) ;
			spike = true ;
			V_ = 0.0 ;
			refractory = ( t/h ) ;
			cout << " SPIKE" << endl ;		
		}
	}
	 buffer[t % ((int)(D/h) + 1)] = 0 ;
	 return spike ;
	 cout <<" fin update " << endl ; 
}	

/*spikes will be received after a delay D */ 

void Neurone::receive (int t,double J)
{
	buffer[t % (int) (D/h)+1] += J ;
}
			
			
	











	
