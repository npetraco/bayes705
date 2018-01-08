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
_m = rng.rand();
_b = rng.rand();
_log_sigma = rng.rand();

m = -100.0 + (100.0 - (-100.0))*_m;
b = -100.0 + (100.0 - (-100.0))*_b;
log_sigma = -10.0 + (10.0 - (-10.0))*_log_sigma;
sigma = exp(log_sigma);

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
which = rng.rand_int(3);
if(which == 0)
{
_m += rng.randh();
DNest4::wrap(_m, 0.0, 1.0);
}
if(which == 1)
{
_b += rng.randh();
DNest4::wrap(_b, 0.0, 1.0);
}
if(which == 2)
{
_log_sigma += rng.randh();
DNest4::wrap(_log_sigma, 0.0, 1.0);
}
}

m = -100.0 + (100.0 - (-100.0))*_m;
b = -100.0 + (100.0 - (-100.0))*_b;
log_sigma = -10.0 + (10.0 - (-10.0))*_log_sigma;
sigma = exp(log_sigma);

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += -0.5*log(2*M_PI) - log(sigma) - 0.5*pow(((y0) - (m*x0 + b))/(sigma), 2);
logp += -0.5*log(2*M_PI) - log(sigma) - 0.5*pow(((y1) - (m*x1 + b))/(sigma), 2);
logp += -0.5*log(2*M_PI) - log(sigma) - 0.5*pow(((y2) - (m*x2 + b))/(sigma), 2);
logp += -0.5*log(2*M_PI) - log(sigma) - 0.5*pow(((y3) - (m*x3 + b))/(sigma), 2);
logp += -0.5*log(2*M_PI) - log(sigma) - 0.5*pow(((y4) - (m*x4 + b))/(sigma), 2);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<m<<' ';
out<<b<<' ';
out<<log_sigma<<' ';
out<<sigma<<' ';

}

string MyModel::description() const
{
return string("m, b, log_sigma, sigma");
}

