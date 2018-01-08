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
_m1 = rng.rand();
_m2 = rng.rand();

m1 = -6.0 + (6.0 - (-6.0))*_m1;
m2 = -6.0 + (6.0 - (-6.0))*_m2;

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
_m1 += rng.randh();
DNest4::wrap(_m1, 0.0, 1.0);
}
if(which == 1)
{
_m2 += rng.randh();
DNest4::wrap(_m2, 0.0, 1.0);
}
}

m1 = -6.0 + (6.0 - (-6.0))*_m1;
m2 = -6.0 + (6.0 - (-6.0))*_m2;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;
double a = 0.0;
double b = 0.0;

//logp += -0.5*log(2*M_PI) - log(1) - 0.5*pow(((D0) - (mu))/(1), 2);
a += 1.383646559789373 - 50.*pow(-2 + sqrt(pow(abs(-cx0 + m1),2) + pow(abs(-cy0 + m2),2)),2);
b += 1.383646559789373 - 50.*pow(-2 + sqrt(pow(abs(-cx1 + m1),2) + pow(abs(-cy1 + m2),2)),2);
logp += logsumexp(a, b); // log(e^a + e^b)
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<m1<<' ';
out<<m2<<' ';

}

string MyModel::description() const
{
return string("m1, m2");
}

