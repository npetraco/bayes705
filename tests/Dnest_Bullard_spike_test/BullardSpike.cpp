#include "Data.h"
#include "BullardSpike.h"
#include "DNest4.h"

using namespace std;
using namespace DNest4;

BullardSpike::BullardSpike()
{

}

void BullardSpike::from_prior(RNG& rng)
{

	// Priors
	alpha = 0. + 1.*rng.rand(); // alpha ~ Uniform(0,1)
	beta  = 0. + 1.*rng.rand(); // beta  ~ Uniform(0,1)

}

double BullardSpike::perturb(RNG& rng)
{

	// Proposals to explore the prior. cf. Spike slab example.
	int which = rng.rand_int(2);
	if(which == 0)
	{
		// proposal for alpha 
		alpha += 1.*rng.randh();
		wrap(alpha, 0., 1.);
	}
	else
	{
		// proposal beta
		beta += 1.*rng.randh();
		wrap(beta, 0., 1.);
	}

	return 0.; //  cf. Spike slab example. lnH??
}

double BullardSpike::log_likelihood() const
{
	// Grab the D
	const auto& DD = Data::get_instance().get_D();

	// Bullard spike log-likelihood function
	return DD[0]*(log(1 - alpha) + log(alpha) + log(1 - beta) + log(beta));
}

void BullardSpike::print(std::ostream& out) const
{
	out << alpha << ' ' << beta;
}

string BullardSpike::description() const
{
	return string("alpha, beta");
}
