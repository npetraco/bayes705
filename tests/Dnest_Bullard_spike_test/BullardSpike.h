#ifndef DNest4_BullardSpike
#define DNest4_BullardSpike

#include "DNest4.h"
#include <valarray>
#include <ostream>

class BullardSpike
{
	private:
		// The Bullard Spike example problem parameters
		double alpha, beta;

	public:
		// Constructor
		BullardSpike();

		// Generate the point from the prior
		void from_prior(DNest4::RNG& rng);

		// Metropolis-Hastings proposals
		double perturb(DNest4::RNG& rng);

		// Likelihood function
		double log_likelihood() const;

		// Print to stream
		void print(std::ostream& out) const;

		// Return string with column information
		std::string description() const;
};

#endif

