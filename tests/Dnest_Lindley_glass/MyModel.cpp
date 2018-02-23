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
_mucssp = rng.rand();

mucssp = 1.51 + (0.01)*quantile(__boost_dist, _mucssp);

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
_mucssp += rng.randh();
DNest4::wrap(_mucssp, 0.0, 1.0);
}
}

mucssp = 1.51 + (0.01)*quantile(__boost_dist, _mucssp);

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += -0.5*log(2*M_PI) - log(sCS) - 0.5*pow(((Xb) - (mucssp))/(sCS), 2);
logp += -0.5*log(2*M_PI) - log(sSP) - 0.5*pow(((Yb) - (mucssp))/(sSP), 2);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<mucssp<<' ';

}

string MyModel::description() const
{
return string("mucssp");
}

