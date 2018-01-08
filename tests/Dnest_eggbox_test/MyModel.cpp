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
_a = rng.rand();
_b = rng.rand();

a = 0 + (31.41592653589793 - (0))*_a;
b = 0 + (31.41592653589793 - (0))*_b;

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
which = rng.rand_int(2);
if(which == 0)
{
_a += rng.randh();
DNest4::wrap(_a, 0.0, 1.0);
}
if(which == 1)
{
_b += rng.randh();
DNest4::wrap(_b, 0.0, 1.0);
}
}

a = 0 + (31.41592653589793 - (0))*_a;
b = 0 + (31.41592653589793 - (0))*_b;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

//logp += -0.5*log(2*M_PI) - log(1) - 0.5*pow(((D0) - (mu))/(1), 2);
logp += pow(2 + cos(a/2.)*cos(b/2.),5);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<a<<' ';
out<<b<<' ';

}

string MyModel::description() const
{
return string("a, b");
}

