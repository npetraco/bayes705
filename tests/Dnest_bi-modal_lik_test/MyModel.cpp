#include "MyModel.h"
#include "DNest4.h"
#include <boost/math/distributions/normal.hpp>
#include <boost/math/distributions/gamma.hpp>
#include <boost/math/special_functions/gamma.hpp>
#include <iomanip>

boost::math::normal __boost_dist(0.0, 1.0);

using namespace std;
using namespace DNest4;



MyModel::MyModel()
{

}

void MyModel::from_prior(RNG& rng)
{
_mu = rng.rand();

mu = 0.3 + 10*tan(M_PI*(_mu - 0.5));

}

double MyModel::perturb(RNG& rng)
{
double logH = 0.0;

int which;
int reps = 1;
if(rng.rand() <= 0.5)
    reps = (int)pow(10.0, 2*rng.rand());
for(int i=0; i<reps; ++i)
{
which = rng.rand_int(1);
if(which == 0)
{
_mu += rng.randh();
DNest4::wrap(_mu, 0.0, 1.0);
}
}

mu = 0.3 + 10*tan(M_PI*(_mu - 0.5));

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

//logp += -0.5*log(2*M_PI) - log(0.5) - 0.5*pow(((D0) - (mu))/(0.5), 2);
//logp += log(1/(2.*exp(pow(D0 - mu,2)/2.)*sqrt(2*M_PI)) +  1/(2.*exp(pow(D0 + mu,2)/2.)*sqrt(2*M_PI)));
logp += log(0.3989422804014327/exp(2.*pow(D0 - mu,2)) + (0.3989422804014327/exp(2.*pow(D0 + mu,2))));
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<mu<<' ';

}

string MyModel::description() const
{
return string("mu");
}

