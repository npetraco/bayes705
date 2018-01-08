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
_log_mu1 = rng.rand();
_diff = rng.rand();
_change_year = rng.rand();
_L = rng.rand();

log_mu1 = 0.0 + 5.0*tan(M_PI*(_log_mu1 - 0.5));
diff = 0.0 + 1.0*tan(M_PI*(_diff - 0.5));
log_mu2 = log_mu1 + diff;
mu1 = exp(log_mu1);
mu2 = exp(log_mu2);
change_year = 1851.0 + (1962.0 - (1851.0))*_change_year;
L = exp(log(0.01) + log((100.0)/(0.01))*_L);

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
which = rng.rand_int(4);
if(which == 0)
{
_log_mu1 += rng.randh();
DNest4::wrap(_log_mu1, 0.0, 1.0);
}
if(which == 1)
{
_diff += rng.randh();
DNest4::wrap(_diff, 0.0, 1.0);
}
if(which == 2)
{
_change_year += rng.randh();
DNest4::wrap(_change_year, 0.0, 1.0);
}
if(which == 3)
{
_L += rng.randh();
DNest4::wrap(_L, 0.0, 1.0);
}
}

log_mu1 = 0.0 + 5.0*tan(M_PI*(_log_mu1 - 0.5));
diff = 0.0 + 1.0*tan(M_PI*(_diff - 0.5));
log_mu2 = log_mu1 + diff;
mu1 = exp(log_mu1);
mu2 = exp(log_mu2);
change_year = 1851.0 + (1962.0 - (1851.0))*_change_year;
L = exp(log(0.01) + log((100.0)/(0.01))*_L);

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += y0*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t0 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t0 - change_year)/L)));
logp -= boost::math::lgamma<double>(y0 + 1);
logp += y1*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t1 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t1 - change_year)/L)));
logp -= boost::math::lgamma<double>(y1 + 1);
logp += y2*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t2 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t2 - change_year)/L)));
logp -= boost::math::lgamma<double>(y2 + 1);
logp += y3*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t3 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t3 - change_year)/L)));
logp -= boost::math::lgamma<double>(y3 + 1);
logp += y4*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t4 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t4 - change_year)/L)));
logp -= boost::math::lgamma<double>(y4 + 1);
logp += y5*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t5 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t5 - change_year)/L)));
logp -= boost::math::lgamma<double>(y5 + 1);
logp += y6*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t6 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t6 - change_year)/L)));
logp -= boost::math::lgamma<double>(y6 + 1);
logp += y7*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t7 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t7 - change_year)/L)));
logp -= boost::math::lgamma<double>(y7 + 1);
logp += y8*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t8 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t8 - change_year)/L)));
logp -= boost::math::lgamma<double>(y8 + 1);
logp += y9*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t9 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t9 - change_year)/L)));
logp -= boost::math::lgamma<double>(y9 + 1);
logp += y10*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t10 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t10 - change_year)/L)));
logp -= boost::math::lgamma<double>(y10 + 1);
logp += y11*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t11 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t11 - change_year)/L)));
logp -= boost::math::lgamma<double>(y11 + 1);
logp += y12*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t12 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t12 - change_year)/L)));
logp -= boost::math::lgamma<double>(y12 + 1);
logp += y13*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t13 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t13 - change_year)/L)));
logp -= boost::math::lgamma<double>(y13 + 1);
logp += y14*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t14 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t14 - change_year)/L)));
logp -= boost::math::lgamma<double>(y14 + 1);
logp += y15*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t15 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t15 - change_year)/L)));
logp -= boost::math::lgamma<double>(y15 + 1);
logp += y16*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t16 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t16 - change_year)/L)));
logp -= boost::math::lgamma<double>(y16 + 1);
logp += y17*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t17 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t17 - change_year)/L)));
logp -= boost::math::lgamma<double>(y17 + 1);
logp += y18*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t18 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t18 - change_year)/L)));
logp -= boost::math::lgamma<double>(y18 + 1);
logp += y19*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t19 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t19 - change_year)/L)));
logp -= boost::math::lgamma<double>(y19 + 1);
logp += y20*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t20 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t20 - change_year)/L)));
logp -= boost::math::lgamma<double>(y20 + 1);
logp += y21*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t21 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t21 - change_year)/L)));
logp -= boost::math::lgamma<double>(y21 + 1);
logp += y22*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t22 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t22 - change_year)/L)));
logp -= boost::math::lgamma<double>(y22 + 1);
logp += y23*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t23 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t23 - change_year)/L)));
logp -= boost::math::lgamma<double>(y23 + 1);
logp += y24*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t24 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t24 - change_year)/L)));
logp -= boost::math::lgamma<double>(y24 + 1);
logp += y25*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t25 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t25 - change_year)/L)));
logp -= boost::math::lgamma<double>(y25 + 1);
logp += y26*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t26 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t26 - change_year)/L)));
logp -= boost::math::lgamma<double>(y26 + 1);
logp += y27*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t27 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t27 - change_year)/L)));
logp -= boost::math::lgamma<double>(y27 + 1);
logp += y28*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t28 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t28 - change_year)/L)));
logp -= boost::math::lgamma<double>(y28 + 1);
logp += y29*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t29 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t29 - change_year)/L)));
logp -= boost::math::lgamma<double>(y29 + 1);
logp += y30*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t30 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t30 - change_year)/L)));
logp -= boost::math::lgamma<double>(y30 + 1);
logp += y31*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t31 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t31 - change_year)/L)));
logp -= boost::math::lgamma<double>(y31 + 1);
logp += y32*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t32 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t32 - change_year)/L)));
logp -= boost::math::lgamma<double>(y32 + 1);
logp += y33*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t33 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t33 - change_year)/L)));
logp -= boost::math::lgamma<double>(y33 + 1);
logp += y34*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t34 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t34 - change_year)/L)));
logp -= boost::math::lgamma<double>(y34 + 1);
logp += y35*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t35 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t35 - change_year)/L)));
logp -= boost::math::lgamma<double>(y35 + 1);
logp += y36*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t36 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t36 - change_year)/L)));
logp -= boost::math::lgamma<double>(y36 + 1);
logp += y37*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t37 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t37 - change_year)/L)));
logp -= boost::math::lgamma<double>(y37 + 1);
logp += y38*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t38 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t38 - change_year)/L)));
logp -= boost::math::lgamma<double>(y38 + 1);
logp += y39*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t39 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t39 - change_year)/L)));
logp -= boost::math::lgamma<double>(y39 + 1);
logp += y40*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t40 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t40 - change_year)/L)));
logp -= boost::math::lgamma<double>(y40 + 1);
logp += y41*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t41 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t41 - change_year)/L)));
logp -= boost::math::lgamma<double>(y41 + 1);
logp += y42*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t42 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t42 - change_year)/L)));
logp -= boost::math::lgamma<double>(y42 + 1);
logp += y43*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t43 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t43 - change_year)/L)));
logp -= boost::math::lgamma<double>(y43 + 1);
logp += y44*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t44 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t44 - change_year)/L)));
logp -= boost::math::lgamma<double>(y44 + 1);
logp += y45*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t45 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t45 - change_year)/L)));
logp -= boost::math::lgamma<double>(y45 + 1);
logp += y46*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t46 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t46 - change_year)/L)));
logp -= boost::math::lgamma<double>(y46 + 1);
logp += y47*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t47 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t47 - change_year)/L)));
logp -= boost::math::lgamma<double>(y47 + 1);
logp += y48*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t48 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t48 - change_year)/L)));
logp -= boost::math::lgamma<double>(y48 + 1);
logp += y49*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t49 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t49 - change_year)/L)));
logp -= boost::math::lgamma<double>(y49 + 1);
logp += y50*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t50 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t50 - change_year)/L)));
logp -= boost::math::lgamma<double>(y50 + 1);
logp += y51*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t51 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t51 - change_year)/L)));
logp -= boost::math::lgamma<double>(y51 + 1);
logp += y52*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t52 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t52 - change_year)/L)));
logp -= boost::math::lgamma<double>(y52 + 1);
logp += y53*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t53 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t53 - change_year)/L)));
logp -= boost::math::lgamma<double>(y53 + 1);
logp += y54*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t54 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t54 - change_year)/L)));
logp -= boost::math::lgamma<double>(y54 + 1);
logp += y55*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t55 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t55 - change_year)/L)));
logp -= boost::math::lgamma<double>(y55 + 1);
logp += y56*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t56 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t56 - change_year)/L)));
logp -= boost::math::lgamma<double>(y56 + 1);
logp += y57*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t57 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t57 - change_year)/L)));
logp -= boost::math::lgamma<double>(y57 + 1);
logp += y58*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t58 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t58 - change_year)/L)));
logp -= boost::math::lgamma<double>(y58 + 1);
logp += y59*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t59 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t59 - change_year)/L)));
logp -= boost::math::lgamma<double>(y59 + 1);
logp += y60*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t60 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t60 - change_year)/L)));
logp -= boost::math::lgamma<double>(y60 + 1);
logp += y61*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t61 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t61 - change_year)/L)));
logp -= boost::math::lgamma<double>(y61 + 1);
logp += y62*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t62 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t62 - change_year)/L)));
logp -= boost::math::lgamma<double>(y62 + 1);
logp += y63*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t63 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t63 - change_year)/L)));
logp -= boost::math::lgamma<double>(y63 + 1);
logp += y64*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t64 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t64 - change_year)/L)));
logp -= boost::math::lgamma<double>(y64 + 1);
logp += y65*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t65 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t65 - change_year)/L)));
logp -= boost::math::lgamma<double>(y65 + 1);
logp += y66*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t66 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t66 - change_year)/L)));
logp -= boost::math::lgamma<double>(y66 + 1);
logp += y67*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t67 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t67 - change_year)/L)));
logp -= boost::math::lgamma<double>(y67 + 1);
logp += y68*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t68 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t68 - change_year)/L)));
logp -= boost::math::lgamma<double>(y68 + 1);
logp += y69*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t69 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t69 - change_year)/L)));
logp -= boost::math::lgamma<double>(y69 + 1);
logp += y70*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t70 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t70 - change_year)/L)));
logp -= boost::math::lgamma<double>(y70 + 1);
logp += y71*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t71 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t71 - change_year)/L)));
logp -= boost::math::lgamma<double>(y71 + 1);
logp += y72*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t72 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t72 - change_year)/L)));
logp -= boost::math::lgamma<double>(y72 + 1);
logp += y73*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t73 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t73 - change_year)/L)));
logp -= boost::math::lgamma<double>(y73 + 1);
logp += y74*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t74 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t74 - change_year)/L)));
logp -= boost::math::lgamma<double>(y74 + 1);
logp += y75*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t75 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t75 - change_year)/L)));
logp -= boost::math::lgamma<double>(y75 + 1);
logp += y76*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t76 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t76 - change_year)/L)));
logp -= boost::math::lgamma<double>(y76 + 1);
logp += y77*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t77 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t77 - change_year)/L)));
logp -= boost::math::lgamma<double>(y77 + 1);
logp += y78*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t78 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t78 - change_year)/L)));
logp -= boost::math::lgamma<double>(y78 + 1);
logp += y79*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t79 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t79 - change_year)/L)));
logp -= boost::math::lgamma<double>(y79 + 1);
logp += y80*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t80 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t80 - change_year)/L)));
logp -= boost::math::lgamma<double>(y80 + 1);
logp += y81*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t81 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t81 - change_year)/L)));
logp -= boost::math::lgamma<double>(y81 + 1);
logp += y82*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t82 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t82 - change_year)/L)));
logp -= boost::math::lgamma<double>(y82 + 1);
logp += y83*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t83 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t83 - change_year)/L)));
logp -= boost::math::lgamma<double>(y83 + 1);
logp += y84*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t84 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t84 - change_year)/L)));
logp -= boost::math::lgamma<double>(y84 + 1);
logp += y85*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t85 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t85 - change_year)/L)));
logp -= boost::math::lgamma<double>(y85 + 1);
logp += y86*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t86 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t86 - change_year)/L)));
logp -= boost::math::lgamma<double>(y86 + 1);
logp += y87*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t87 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t87 - change_year)/L)));
logp -= boost::math::lgamma<double>(y87 + 1);
logp += y88*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t88 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t88 - change_year)/L)));
logp -= boost::math::lgamma<double>(y88 + 1);
logp += y89*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t89 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t89 - change_year)/L)));
logp -= boost::math::lgamma<double>(y89 + 1);
logp += y90*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t90 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t90 - change_year)/L)));
logp -= boost::math::lgamma<double>(y90 + 1);
logp += y91*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t91 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t91 - change_year)/L)));
logp -= boost::math::lgamma<double>(y91 + 1);
logp += y92*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t92 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t92 - change_year)/L)));
logp -= boost::math::lgamma<double>(y92 + 1);
logp += y93*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t93 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t93 - change_year)/L)));
logp -= boost::math::lgamma<double>(y93 + 1);
logp += y94*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t94 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t94 - change_year)/L)));
logp -= boost::math::lgamma<double>(y94 + 1);
logp += y95*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t95 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t95 - change_year)/L)));
logp -= boost::math::lgamma<double>(y95 + 1);
logp += y96*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t96 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t96 - change_year)/L)));
logp -= boost::math::lgamma<double>(y96 + 1);
logp += y97*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t97 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t97 - change_year)/L)));
logp -= boost::math::lgamma<double>(y97 + 1);
logp += y98*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t98 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t98 - change_year)/L)));
logp -= boost::math::lgamma<double>(y98 + 1);
logp += y99*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t99 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t99 - change_year)/L)));
logp -= boost::math::lgamma<double>(y99 + 1);
logp += y100*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t100 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t100 - change_year)/L)));
logp -= boost::math::lgamma<double>(y100 + 1);
logp += y101*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t101 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t101 - change_year)/L)));
logp -= boost::math::lgamma<double>(y101 + 1);
logp += y102*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t102 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t102 - change_year)/L)));
logp -= boost::math::lgamma<double>(y102 + 1);
logp += y103*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t103 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t103 - change_year)/L)));
logp -= boost::math::lgamma<double>(y103 + 1);
logp += y104*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t104 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t104 - change_year)/L)));
logp -= boost::math::lgamma<double>(y104 + 1);
logp += y105*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t105 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t105 - change_year)/L)));
logp -= boost::math::lgamma<double>(y105 + 1);
logp += y106*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t106 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t106 - change_year)/L)));
logp -= boost::math::lgamma<double>(y106 + 1);
logp += y107*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t107 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t107 - change_year)/L)));
logp -= boost::math::lgamma<double>(y107 + 1);
logp += y108*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t108 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t108 - change_year)/L)));
logp -= boost::math::lgamma<double>(y108 + 1);
logp += y109*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t109 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t109 - change_year)/L)));
logp -= boost::math::lgamma<double>(y109 + 1);
logp += y110*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t110 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t110 - change_year)/L)));
logp -= boost::math::lgamma<double>(y110 + 1);
logp += y111*log(mu1 + (mu2 - mu1)/(1.0 + exp(-(t111 - change_year)/L))) - (mu1 + (mu2 - mu1)/(1.0 + exp(-(t111 - change_year)/L)));
logp -= boost::math::lgamma<double>(y111 + 1);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<log_mu1<<' ';
out<<diff<<' ';
out<<log_mu2<<' ';
out<<mu1<<' ';
out<<mu2<<' ';
out<<change_year<<' ';
out<<L<<' ';

}

string MyModel::description() const
{
return string("log_mu1, diff, log_mu2, mu1, mu2, change_year, L");
}

