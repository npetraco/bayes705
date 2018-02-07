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
_p = rng.rand();

p = 0 + (1 - (0))*_p;

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
_p += rng.randh();
DNest4::wrap(_p, 0.0, 1.0);
}
}

p = 0 + (1 - (0))*_p;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += boost::math::lgamma<double>(n0 + 1);
logp -= boost::math::lgamma<double>(y0 + 1);
logp -= boost::math::lgamma<double>(n0 - (y0) + 1);
logp += (y0)*log(p) + (n0 - (y0))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n1 + 1);
logp -= boost::math::lgamma<double>(y1 + 1);
logp -= boost::math::lgamma<double>(n1 - (y1) + 1);
logp += (y1)*log(p) + (n1 - (y1))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n2 + 1);
logp -= boost::math::lgamma<double>(y2 + 1);
logp -= boost::math::lgamma<double>(n2 - (y2) + 1);
logp += (y2)*log(p) + (n2 - (y2))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n3 + 1);
logp -= boost::math::lgamma<double>(y3 + 1);
logp -= boost::math::lgamma<double>(n3 - (y3) + 1);
logp += (y3)*log(p) + (n3 - (y3))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n4 + 1);
logp -= boost::math::lgamma<double>(y4 + 1);
logp -= boost::math::lgamma<double>(n4 - (y4) + 1);
logp += (y4)*log(p) + (n4 - (y4))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n5 + 1);
logp -= boost::math::lgamma<double>(y5 + 1);
logp -= boost::math::lgamma<double>(n5 - (y5) + 1);
logp += (y5)*log(p) + (n5 - (y5))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n6 + 1);
logp -= boost::math::lgamma<double>(y6 + 1);
logp -= boost::math::lgamma<double>(n6 - (y6) + 1);
logp += (y6)*log(p) + (n6 - (y6))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n7 + 1);
logp -= boost::math::lgamma<double>(y7 + 1);
logp -= boost::math::lgamma<double>(n7 - (y7) + 1);
logp += (y7)*log(p) + (n7 - (y7))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n8 + 1);
logp -= boost::math::lgamma<double>(y8 + 1);
logp -= boost::math::lgamma<double>(n8 - (y8) + 1);
logp += (y8)*log(p) + (n8 - (y8))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n9 + 1);
logp -= boost::math::lgamma<double>(y9 + 1);
logp -= boost::math::lgamma<double>(n9 - (y9) + 1);
logp += (y9)*log(p) + (n9 - (y9))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n10 + 1);
logp -= boost::math::lgamma<double>(y10 + 1);
logp -= boost::math::lgamma<double>(n10 - (y10) + 1);
logp += (y10)*log(p) + (n10 - (y10))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n11 + 1);
logp -= boost::math::lgamma<double>(y11 + 1);
logp -= boost::math::lgamma<double>(n11 - (y11) + 1);
logp += (y11)*log(p) + (n11 - (y11))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n12 + 1);
logp -= boost::math::lgamma<double>(y12 + 1);
logp -= boost::math::lgamma<double>(n12 - (y12) + 1);
logp += (y12)*log(p) + (n12 - (y12))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n13 + 1);
logp -= boost::math::lgamma<double>(y13 + 1);
logp -= boost::math::lgamma<double>(n13 - (y13) + 1);
logp += (y13)*log(p) + (n13 - (y13))*log(1.0 - (p));
logp += boost::math::lgamma<double>(n14 + 1);
logp -= boost::math::lgamma<double>(y14 + 1);
logp -= boost::math::lgamma<double>(n14 - (y14) + 1);
logp += (y14)*log(p) + (n14 - (y14))*log(1.0 - (p));
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<p<<' ';

}

string MyModel::description() const
{
return string("p");
}

