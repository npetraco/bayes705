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
_r = rng.rand();
_th = rng.rand();
_ph = rng.rand();

r = 0.0 + (20.0 - (0.0))*_r;
th = 0.0 + (3.141592653589793 - (0.0))*_th;
ph = 0.0 + (6.283185307179586 - (0.0))*_ph;

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
_r += rng.randh();
DNest4::wrap(_r, 0.0, 1.0);
}
if(which == 1)
{
_th += rng.randh();
DNest4::wrap(_th, 0.0, 1.0);
}
if(which == 2)
{
_ph += rng.randh();
DNest4::wrap(_ph, 0.0, 1.0);
}
}

r = 0.0 + (20.0 - (0.0))*_r;
th = 0.0 + (3.141592653589793 - (0.0))*_th;
ph = 0.0 + (6.283185307179586 - (0.0))*_ph;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

// Atomic log densities in real form:
//logp += (-2*r)/3. + log(2) - log(6561*M_PI) + log(pow(-6 + r,2)*pow(r,4)*pow(cos(th),2)*sin(th)); // 3p0 = 2pz
//logp += (-2*r)/3. + log(2) - log(6561*M_PI) + log(pow(-6 + r,2)*pow(r,4)*pow(cos(ph),2)*pow(sin(th),3)); // 3px, need to be in real form. Why??
logp += (-2*r)/3. + log(2) - log(6561*M_PI) + log(pow(-6 + r,2)*pow(r,4)*pow(sin(ph),2)*pow(sin(th),3)); // 3py, need to be in real form. Why??
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<r<<' ';
out<<th<<' ';
out<<ph<<' ';

}

string MyModel::description() const
{
return string("r, th, ph");
}

