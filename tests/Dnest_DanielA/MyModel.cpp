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
_beta0 = rng.rand();
_beta1 = rng.rand();
_epsilon = rng.rand();

beta0 = 0 + 1*tan(M_PI*(_beta0 - 0.5));
beta1 = 0 + 5*tan(M_PI*(_beta1/2.0));
epsilon = 0 + (1)*quantile(__boost_dist, _epsilon);

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
_beta0 += rng.randh();
DNest4::wrap(_beta0, 0.0, 1.0);
}
if(which == 1)
{
_beta1 += rng.randh();
DNest4::wrap(_beta1, 0.0, 1.0);
}
if(which == 2)
{
_epsilon += rng.randh();
DNest4::wrap(_epsilon, 0.0, 1.0);
}
}

beta0 = 0 + 1*tan(M_PI*(_beta0 - 0.5));
beta1 = 0 + 5*tan(M_PI*(_beta1/2.0));
epsilon = 0 + (1)*quantile(__boost_dist, _epsilon);

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += -0.5*log(2*M_PI) - log(epsilon) - 0.5*pow(((y0) - (beta1*x0 + beta0))/(epsilon), 2);
logp += -0.5*log(2*M_PI) - log(epsilon) - 0.5*pow(((y1) - (beta1*x1 + beta0))/(epsilon), 2);
logp += -0.5*log(2*M_PI) - log(epsilon) - 0.5*pow(((y2) - (beta1*x2 + beta0))/(epsilon), 2);
logp += -0.5*log(2*M_PI) - log(epsilon) - 0.5*pow(((y3) - (beta1*x3 + beta0))/(epsilon), 2);
logp += -0.5*log(2*M_PI) - log(epsilon) - 0.5*pow(((y4) - (beta1*x4 + beta0))/(epsilon), 2);
logp += -0.5*log(2*M_PI) - log(epsilon) - 0.5*pow(((y5) - (beta1*x5 + beta0))/(epsilon), 2);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<beta0<<' ';
out<<beta1<<' ';
out<<epsilon<<' ';

}

string MyModel::description() const
{
return string("beta0, beta1, epsilon");
}

