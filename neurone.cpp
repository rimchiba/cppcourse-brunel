#include "neurone.h" 

using namespace std ; 

int Neurone::random_poisson (int r)
{
	random_device rd;
	mt19937 gen(rd());
	poisson_distribution<> poisson(r);
	return poisson(gen) ;
}

double Neurone::getV() const {	
	return V_;
}

int Neurone::get_spikes () const {
	return spikes_ ;
}

double Neurone::get_J () const {
	return J ;
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

Neurone::Neurone (double j)
: V_(0),spikes_(0),J(j)
{
	for ( int i(0); i< (D/h)+1 ;++i) 
	{
		buffer.push_back(0) ;
	}
}

Neurone::~Neurone(){} 

void Neurone::set_buffer (vector<int> buffer )  {
	buffer = buffer ;
}

bool Neurone::update (double t,double I) {
	
	int n(0);
	double refractory (0.0);
	bool spike ;
	
	 if (V_ > V_thr) 
	 {
		 ++ spikes_ ;
		 times_.push_back(t*h) ;
		 spike = true ;
		 V_ = 0.0 ;
		 refractory = ( t/h ) ;
		 cout << " if 1 update " << endl ;		
	}
	 if ( t < refractory )
	 { 
		 V_ = 0.0 ;	
		 refractory -= h ; 
		 spike = false ;
		 cout << " if 2 update " << endl;

	 } else {
		 J = buffer[n % ((int)(D/h) + 1)]  ;
		 buffer[n % ((int)(D/h) + 1)] = 0 ;
		 V_ = exp (-h/tau)*V_ + I*R*(1-exp(-h/tau)) + J + random_poisson(V_ext*C_ext*h*J); 
		 spike = false ;
		 cout << " if 3 update " << endl ;
	 }
	 return spike ;
	 ++n  ;
	 cout <<" fin update " << endl ; 
}
	
		
void Neurone::receive (int t,double J)
{
	buffer[t+ (int)(D/h) % (int) (D/h)+1] += J ;
}
			
			
	











	
