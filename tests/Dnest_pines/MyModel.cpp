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
_sig1 = rng.rand();

a = 0 + (1000)*quantile(__boost_dist, _a);
b = 0 + (100)*quantile(__boost_dist, _b);
sig1 = 0 + (100000000.0 - (0))*_sig1;

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
_a += rng.randh();
DNest4::wrap(_a, 0.0, 1.0);
}
if(which == 1)
{
_b += rng.randh();
DNest4::wrap(_b, 0.0, 1.0);
}
if(which == 2)
{
_sig1 += rng.randh();
DNest4::wrap(_sig1, 0.0, 1.0);
}
}

a = 0 + (1000)*quantile(__boost_dist, _a);
b = 0 + (100)*quantile(__boost_dist, _b);
sig1 = 0 + (100000000.0 - (0))*_sig1;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y0) - (b*x0 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y1) - (b*x1 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y2) - (b*x2 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y3) - (b*x3 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y4) - (b*x4 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y5) - (b*x5 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y6) - (b*x6 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y7) - (b*x7 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y8) - (b*x8 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y9) - (b*x9 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y10) - (b*x10 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y11) - (b*x11 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y12) - (b*x12 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y13) - (b*x13 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y14) - (b*x14 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y15) - (b*x15 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y16) - (b*x16 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y17) - (b*x17 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y18) - (b*x18 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y19) - (b*x19 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y20) - (b*x20 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y21) - (b*x21 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y22) - (b*x22 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y23) - (b*x23 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y24) - (b*x24 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y25) - (b*x25 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y26) - (b*x26 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y27) - (b*x27 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y28) - (b*x28 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y29) - (b*x29 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y30) - (b*x30 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y31) - (b*x31 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y32) - (b*x32 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y33) - (b*x33 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y34) - (b*x34 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y35) - (b*x35 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y36) - (b*x36 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y37) - (b*x37 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y38) - (b*x38 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y39) - (b*x39 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y40) - (b*x40 + a))/(sig1), 2);
logp += -0.5*log(2*M_PI) - log(sig1) - 0.5*pow(((y41) - (b*x41 + a))/(sig1), 2);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<a<<' ';
out<<b<<' ';
out<<sig1<<' ';

}

string MyModel::description() const
{
return string("a, b, sig1");
}

