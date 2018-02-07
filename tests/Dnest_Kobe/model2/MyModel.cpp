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
_ppi0 = rng.rand();
_ppi1 = rng.rand();
_ppi2 = rng.rand();
_ppi3 = rng.rand();
_ppi4 = rng.rand();
_ppi5 = rng.rand();
_ppi6 = rng.rand();
_ppi7 = rng.rand();
_ppi8 = rng.rand();
_ppi9 = rng.rand();
_ppi10 = rng.rand();
_ppi11 = rng.rand();
_ppi12 = rng.rand();
_ppi13 = rng.rand();
_ppi14 = rng.rand();

ppi0 = 0 + (1 - (0))*_ppi0;
ppi1 = 0 + (1 - (0))*_ppi1;
ppi2 = 0 + (1 - (0))*_ppi2;
ppi3 = 0 + (1 - (0))*_ppi3;
ppi4 = 0 + (1 - (0))*_ppi4;
ppi5 = 0 + (1 - (0))*_ppi5;
ppi6 = 0 + (1 - (0))*_ppi6;
ppi7 = 0 + (1 - (0))*_ppi7;
ppi8 = 0 + (1 - (0))*_ppi8;
ppi9 = 0 + (1 - (0))*_ppi9;
ppi10 = 0 + (1 - (0))*_ppi10;
ppi11 = 0 + (1 - (0))*_ppi11;
ppi12 = 0 + (1 - (0))*_ppi12;
ppi13 = 0 + (1 - (0))*_ppi13;
ppi14 = 0 + (1 - (0))*_ppi14;

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
which = rng.rand_int(15);
if(which == 0)
{
_ppi0 += rng.randh();
DNest4::wrap(_ppi0, 0.0, 1.0);
}
if(which == 1)
{
_ppi1 += rng.randh();
DNest4::wrap(_ppi1, 0.0, 1.0);
}
if(which == 2)
{
_ppi2 += rng.randh();
DNest4::wrap(_ppi2, 0.0, 1.0);
}
if(which == 3)
{
_ppi3 += rng.randh();
DNest4::wrap(_ppi3, 0.0, 1.0);
}
if(which == 4)
{
_ppi4 += rng.randh();
DNest4::wrap(_ppi4, 0.0, 1.0);
}
if(which == 5)
{
_ppi5 += rng.randh();
DNest4::wrap(_ppi5, 0.0, 1.0);
}
if(which == 6)
{
_ppi6 += rng.randh();
DNest4::wrap(_ppi6, 0.0, 1.0);
}
if(which == 7)
{
_ppi7 += rng.randh();
DNest4::wrap(_ppi7, 0.0, 1.0);
}
if(which == 8)
{
_ppi8 += rng.randh();
DNest4::wrap(_ppi8, 0.0, 1.0);
}
if(which == 9)
{
_ppi9 += rng.randh();
DNest4::wrap(_ppi9, 0.0, 1.0);
}
if(which == 10)
{
_ppi10 += rng.randh();
DNest4::wrap(_ppi10, 0.0, 1.0);
}
if(which == 11)
{
_ppi11 += rng.randh();
DNest4::wrap(_ppi11, 0.0, 1.0);
}
if(which == 12)
{
_ppi12 += rng.randh();
DNest4::wrap(_ppi12, 0.0, 1.0);
}
if(which == 13)
{
_ppi13 += rng.randh();
DNest4::wrap(_ppi13, 0.0, 1.0);
}
if(which == 14)
{
_ppi14 += rng.randh();
DNest4::wrap(_ppi14, 0.0, 1.0);
}
}

ppi0 = 0 + (1 - (0))*_ppi0;
ppi1 = 0 + (1 - (0))*_ppi1;
ppi2 = 0 + (1 - (0))*_ppi2;
ppi3 = 0 + (1 - (0))*_ppi3;
ppi4 = 0 + (1 - (0))*_ppi4;
ppi5 = 0 + (1 - (0))*_ppi5;
ppi6 = 0 + (1 - (0))*_ppi6;
ppi7 = 0 + (1 - (0))*_ppi7;
ppi8 = 0 + (1 - (0))*_ppi8;
ppi9 = 0 + (1 - (0))*_ppi9;
ppi10 = 0 + (1 - (0))*_ppi10;
ppi11 = 0 + (1 - (0))*_ppi11;
ppi12 = 0 + (1 - (0))*_ppi12;
ppi13 = 0 + (1 - (0))*_ppi13;
ppi14 = 0 + (1 - (0))*_ppi14;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += boost::math::lgamma<double>(n0 + 1);
logp -= boost::math::lgamma<double>(y0 + 1);
logp -= boost::math::lgamma<double>(n0 - (y0) + 1);
logp += (y0)*log(ppi0) + (n0 - (y0))*log(1.0 - (ppi0));
logp += boost::math::lgamma<double>(n1 + 1);
logp -= boost::math::lgamma<double>(y1 + 1);
logp -= boost::math::lgamma<double>(n1 - (y1) + 1);
logp += (y1)*log(ppi1) + (n1 - (y1))*log(1.0 - (ppi1));
logp += boost::math::lgamma<double>(n2 + 1);
logp -= boost::math::lgamma<double>(y2 + 1);
logp -= boost::math::lgamma<double>(n2 - (y2) + 1);
logp += (y2)*log(ppi2) + (n2 - (y2))*log(1.0 - (ppi2));
logp += boost::math::lgamma<double>(n3 + 1);
logp -= boost::math::lgamma<double>(y3 + 1);
logp -= boost::math::lgamma<double>(n3 - (y3) + 1);
logp += (y3)*log(ppi3) + (n3 - (y3))*log(1.0 - (ppi3));
logp += boost::math::lgamma<double>(n4 + 1);
logp -= boost::math::lgamma<double>(y4 + 1);
logp -= boost::math::lgamma<double>(n4 - (y4) + 1);
logp += (y4)*log(ppi4) + (n4 - (y4))*log(1.0 - (ppi4));
logp += boost::math::lgamma<double>(n5 + 1);
logp -= boost::math::lgamma<double>(y5 + 1);
logp -= boost::math::lgamma<double>(n5 - (y5) + 1);
logp += (y5)*log(ppi5) + (n5 - (y5))*log(1.0 - (ppi5));
logp += boost::math::lgamma<double>(n6 + 1);
logp -= boost::math::lgamma<double>(y6 + 1);
logp -= boost::math::lgamma<double>(n6 - (y6) + 1);
logp += (y6)*log(ppi6) + (n6 - (y6))*log(1.0 - (ppi6));
logp += boost::math::lgamma<double>(n7 + 1);
logp -= boost::math::lgamma<double>(y7 + 1);
logp -= boost::math::lgamma<double>(n7 - (y7) + 1);
logp += (y7)*log(ppi7) + (n7 - (y7))*log(1.0 - (ppi7));
logp += boost::math::lgamma<double>(n8 + 1);
logp -= boost::math::lgamma<double>(y8 + 1);
logp -= boost::math::lgamma<double>(n8 - (y8) + 1);
logp += (y8)*log(ppi8) + (n8 - (y8))*log(1.0 - (ppi8));
logp += boost::math::lgamma<double>(n9 + 1);
logp -= boost::math::lgamma<double>(y9 + 1);
logp -= boost::math::lgamma<double>(n9 - (y9) + 1);
logp += (y9)*log(ppi9) + (n9 - (y9))*log(1.0 - (ppi9));
logp += boost::math::lgamma<double>(n10 + 1);
logp -= boost::math::lgamma<double>(y10 + 1);
logp -= boost::math::lgamma<double>(n10 - (y10) + 1);
logp += (y10)*log(ppi10) + (n10 - (y10))*log(1.0 - (ppi10));
logp += boost::math::lgamma<double>(n11 + 1);
logp -= boost::math::lgamma<double>(y11 + 1);
logp -= boost::math::lgamma<double>(n11 - (y11) + 1);
logp += (y11)*log(ppi11) + (n11 - (y11))*log(1.0 - (ppi11));
logp += boost::math::lgamma<double>(n12 + 1);
logp -= boost::math::lgamma<double>(y12 + 1);
logp -= boost::math::lgamma<double>(n12 - (y12) + 1);
logp += (y12)*log(ppi12) + (n12 - (y12))*log(1.0 - (ppi12));
logp += boost::math::lgamma<double>(n13 + 1);
logp -= boost::math::lgamma<double>(y13 + 1);
logp -= boost::math::lgamma<double>(n13 - (y13) + 1);
logp += (y13)*log(ppi13) + (n13 - (y13))*log(1.0 - (ppi13));
logp += boost::math::lgamma<double>(n14 + 1);
logp -= boost::math::lgamma<double>(y14 + 1);
logp -= boost::math::lgamma<double>(n14 - (y14) + 1);
logp += (y14)*log(ppi14) + (n14 - (y14))*log(1.0 - (ppi14));
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<ppi0<<' ';
out<<ppi1<<' ';
out<<ppi2<<' ';
out<<ppi3<<' ';
out<<ppi4<<' ';
out<<ppi5<<' ';
out<<ppi6<<' ';
out<<ppi7<<' ';
out<<ppi8<<' ';
out<<ppi9<<' ';
out<<ppi10<<' ';
out<<ppi11<<' ';
out<<ppi12<<' ';
out<<ppi13<<' ';
out<<ppi14<<' ';

}

string MyModel::description() const
{
return string("ppi0, ppi1, ppi2, ppi3, ppi4, ppi5, ppi6, ppi7, ppi8, ppi9, ppi10, ppi11, ppi12, ppi13, ppi14");
}

