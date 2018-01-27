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
_th = rng.rand();

th = -0.5 + (0.5 - (-0.5))*_th;

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
_th += rng.randh();
DNest4::wrap(_th, 0.0, 1.0);
}
}

th = -0.5 + (0.5 - (-0.5))*_th;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;
double a = 0.0;
double b = 0.0;

//logp += -0.5*log(2*M_PI) - log(1) - 0.5*pow(((D0) - (mu))/(1), 2);
a += -pow(th,2)/(2.*pow(u0,2)) + log(D0/(sqrt(2*M_PI)*sqrt(u0)));
b += -pow(th,2)/(2.*pow(v0,2)) - log(sqrt(2*M_PI)*sqrt(u0));
logp += logsumexp(a, b); // log(e^a + e^b)
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<th<<' ';

}

string MyModel::description() const
{
return string("th");
}

