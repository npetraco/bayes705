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
_alpha_mu = rng.rand();
_beta_mu = rng.rand();
_tau_c = rng.rand();
_alpha_tau = rng.rand();
_beta_tau = rng.rand();
_n_alpha0 = rng.rand();
_n_beta0 = rng.rand();
_n_alpha1 = rng.rand();
_n_beta1 = rng.rand();
_n_alpha2 = rng.rand();
_n_beta2 = rng.rand();
_n_alpha3 = rng.rand();
_n_beta3 = rng.rand();
_n_alpha4 = rng.rand();
_n_beta4 = rng.rand();
_n_alpha5 = rng.rand();
_n_beta5 = rng.rand();
_n_alpha6 = rng.rand();
_n_beta6 = rng.rand();
_n_alpha7 = rng.rand();
_n_beta7 = rng.rand();
_n_alpha8 = rng.rand();
_n_beta8 = rng.rand();
_n_alpha9 = rng.rand();
_n_beta9 = rng.rand();
_n_alpha10 = rng.rand();
_n_beta10 = rng.rand();
_n_alpha11 = rng.rand();
_n_beta11 = rng.rand();
_n_alpha12 = rng.rand();
_n_beta12 = rng.rand();
_n_alpha13 = rng.rand();
_n_beta13 = rng.rand();
_n_alpha14 = rng.rand();
_n_beta14 = rng.rand();
_n_alpha15 = rng.rand();
_n_beta15 = rng.rand();
_n_alpha16 = rng.rand();
_n_beta16 = rng.rand();
_n_alpha17 = rng.rand();
_n_beta17 = rng.rand();
_n_alpha18 = rng.rand();
_n_beta18 = rng.rand();
_n_alpha19 = rng.rand();
_n_beta19 = rng.rand();
_n_alpha20 = rng.rand();
_n_beta20 = rng.rand();
_n_alpha21 = rng.rand();
_n_beta21 = rng.rand();
_n_alpha22 = rng.rand();
_n_beta22 = rng.rand();
_n_alpha23 = rng.rand();
_n_beta23 = rng.rand();
_n_alpha24 = rng.rand();
_n_beta24 = rng.rand();
_n_alpha25 = rng.rand();
_n_beta25 = rng.rand();
_n_alpha26 = rng.rand();
_n_beta26 = rng.rand();
_n_alpha27 = rng.rand();
_n_beta27 = rng.rand();
_n_alpha28 = rng.rand();
_n_beta28 = rng.rand();
_n_alpha29 = rng.rand();
_n_beta29 = rng.rand();

alpha_mu = 0.0 + (100.0)*quantile(__boost_dist, _alpha_mu);
beta_mu = 0.0 + (100.0)*quantile(__boost_dist, _beta_mu);
boost::math::gamma_distribution<double> my_gamma_tau_c(0.001, 1000.0);
tau_c = quantile(my_gamma_tau_c, _tau_c);
boost::math::gamma_distribution<double> my_gamma_alpha_tau(0.001, 1000.0);
alpha_tau = quantile(my_gamma_alpha_tau, _alpha_tau);
boost::math::gamma_distribution<double> my_gamma_beta_tau(0.001, 1000.0);
beta_tau = quantile(my_gamma_beta_tau, _beta_tau);
alpha_sigma = 1.0/sqrt(alpha_tau);
beta_sigma = 1.0/sqrt(beta_tau);
sigma_c = 1.0/sqrt(tau_c);
a0 = alpha_mu - beta_mu*x_bar;
n_alpha0 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha0);
n_beta0 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta0);
alpha0 = alpha_mu + alpha_sigma*n_alpha0;
beta0 = beta_mu + beta_sigma*n_beta0;
n_alpha1 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha1);
n_beta1 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta1);
alpha1 = alpha_mu + alpha_sigma*n_alpha1;
beta1 = beta_mu + beta_sigma*n_beta1;
n_alpha2 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha2);
n_beta2 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta2);
alpha2 = alpha_mu + alpha_sigma*n_alpha2;
beta2 = beta_mu + beta_sigma*n_beta2;
n_alpha3 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha3);
n_beta3 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta3);
alpha3 = alpha_mu + alpha_sigma*n_alpha3;
beta3 = beta_mu + beta_sigma*n_beta3;
n_alpha4 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha4);
n_beta4 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta4);
alpha4 = alpha_mu + alpha_sigma*n_alpha4;
beta4 = beta_mu + beta_sigma*n_beta4;
n_alpha5 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha5);
n_beta5 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta5);
alpha5 = alpha_mu + alpha_sigma*n_alpha5;
beta5 = beta_mu + beta_sigma*n_beta5;
n_alpha6 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha6);
n_beta6 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta6);
alpha6 = alpha_mu + alpha_sigma*n_alpha6;
beta6 = beta_mu + beta_sigma*n_beta6;
n_alpha7 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha7);
n_beta7 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta7);
alpha7 = alpha_mu + alpha_sigma*n_alpha7;
beta7 = beta_mu + beta_sigma*n_beta7;
n_alpha8 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha8);
n_beta8 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta8);
alpha8 = alpha_mu + alpha_sigma*n_alpha8;
beta8 = beta_mu + beta_sigma*n_beta8;
n_alpha9 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha9);
n_beta9 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta9);
alpha9 = alpha_mu + alpha_sigma*n_alpha9;
beta9 = beta_mu + beta_sigma*n_beta9;
n_alpha10 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha10);
n_beta10 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta10);
alpha10 = alpha_mu + alpha_sigma*n_alpha10;
beta10 = beta_mu + beta_sigma*n_beta10;
n_alpha11 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha11);
n_beta11 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta11);
alpha11 = alpha_mu + alpha_sigma*n_alpha11;
beta11 = beta_mu + beta_sigma*n_beta11;
n_alpha12 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha12);
n_beta12 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta12);
alpha12 = alpha_mu + alpha_sigma*n_alpha12;
beta12 = beta_mu + beta_sigma*n_beta12;
n_alpha13 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha13);
n_beta13 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta13);
alpha13 = alpha_mu + alpha_sigma*n_alpha13;
beta13 = beta_mu + beta_sigma*n_beta13;
n_alpha14 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha14);
n_beta14 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta14);
alpha14 = alpha_mu + alpha_sigma*n_alpha14;
beta14 = beta_mu + beta_sigma*n_beta14;
n_alpha15 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha15);
n_beta15 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta15);
alpha15 = alpha_mu + alpha_sigma*n_alpha15;
beta15 = beta_mu + beta_sigma*n_beta15;
n_alpha16 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha16);
n_beta16 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta16);
alpha16 = alpha_mu + alpha_sigma*n_alpha16;
beta16 = beta_mu + beta_sigma*n_beta16;
n_alpha17 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha17);
n_beta17 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta17);
alpha17 = alpha_mu + alpha_sigma*n_alpha17;
beta17 = beta_mu + beta_sigma*n_beta17;
n_alpha18 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha18);
n_beta18 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta18);
alpha18 = alpha_mu + alpha_sigma*n_alpha18;
beta18 = beta_mu + beta_sigma*n_beta18;
n_alpha19 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha19);
n_beta19 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta19);
alpha19 = alpha_mu + alpha_sigma*n_alpha19;
beta19 = beta_mu + beta_sigma*n_beta19;
n_alpha20 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha20);
n_beta20 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta20);
alpha20 = alpha_mu + alpha_sigma*n_alpha20;
beta20 = beta_mu + beta_sigma*n_beta20;
n_alpha21 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha21);
n_beta21 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta21);
alpha21 = alpha_mu + alpha_sigma*n_alpha21;
beta21 = beta_mu + beta_sigma*n_beta21;
n_alpha22 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha22);
n_beta22 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta22);
alpha22 = alpha_mu + alpha_sigma*n_alpha22;
beta22 = beta_mu + beta_sigma*n_beta22;
n_alpha23 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha23);
n_beta23 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta23);
alpha23 = alpha_mu + alpha_sigma*n_alpha23;
beta23 = beta_mu + beta_sigma*n_beta23;
n_alpha24 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha24);
n_beta24 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta24);
alpha24 = alpha_mu + alpha_sigma*n_alpha24;
beta24 = beta_mu + beta_sigma*n_beta24;
n_alpha25 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha25);
n_beta25 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta25);
alpha25 = alpha_mu + alpha_sigma*n_alpha25;
beta25 = beta_mu + beta_sigma*n_beta25;
n_alpha26 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha26);
n_beta26 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta26);
alpha26 = alpha_mu + alpha_sigma*n_alpha26;
beta26 = beta_mu + beta_sigma*n_beta26;
n_alpha27 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha27);
n_beta27 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta27);
alpha27 = alpha_mu + alpha_sigma*n_alpha27;
beta27 = beta_mu + beta_sigma*n_beta27;
n_alpha28 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha28);
n_beta28 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta28);
alpha28 = alpha_mu + alpha_sigma*n_alpha28;
beta28 = beta_mu + beta_sigma*n_beta28;
n_alpha29 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha29);
n_beta29 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta29);
alpha29 = alpha_mu + alpha_sigma*n_alpha29;
beta29 = beta_mu + beta_sigma*n_beta29;

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
which = rng.rand_int(65);
if(which == 0)
{
_alpha_mu += rng.randh();
DNest4::wrap(_alpha_mu, 0.0, 1.0);
}
if(which == 1)
{
_beta_mu += rng.randh();
DNest4::wrap(_beta_mu, 0.0, 1.0);
}
if(which == 2)
{
_tau_c += rng.randh();
DNest4::wrap(_tau_c, 0.0, 1.0);
}
if(which == 3)
{
_alpha_tau += rng.randh();
DNest4::wrap(_alpha_tau, 0.0, 1.0);
}
if(which == 4)
{
_beta_tau += rng.randh();
DNest4::wrap(_beta_tau, 0.0, 1.0);
}
if(which == 5)
{
_n_alpha0 += rng.randh();
DNest4::wrap(_n_alpha0, 0.0, 1.0);
}
if(which == 6)
{
_n_beta0 += rng.randh();
DNest4::wrap(_n_beta0, 0.0, 1.0);
}
if(which == 7)
{
_n_alpha1 += rng.randh();
DNest4::wrap(_n_alpha1, 0.0, 1.0);
}
if(which == 8)
{
_n_beta1 += rng.randh();
DNest4::wrap(_n_beta1, 0.0, 1.0);
}
if(which == 9)
{
_n_alpha2 += rng.randh();
DNest4::wrap(_n_alpha2, 0.0, 1.0);
}
if(which == 10)
{
_n_beta2 += rng.randh();
DNest4::wrap(_n_beta2, 0.0, 1.0);
}
if(which == 11)
{
_n_alpha3 += rng.randh();
DNest4::wrap(_n_alpha3, 0.0, 1.0);
}
if(which == 12)
{
_n_beta3 += rng.randh();
DNest4::wrap(_n_beta3, 0.0, 1.0);
}
if(which == 13)
{
_n_alpha4 += rng.randh();
DNest4::wrap(_n_alpha4, 0.0, 1.0);
}
if(which == 14)
{
_n_beta4 += rng.randh();
DNest4::wrap(_n_beta4, 0.0, 1.0);
}
if(which == 15)
{
_n_alpha5 += rng.randh();
DNest4::wrap(_n_alpha5, 0.0, 1.0);
}
if(which == 16)
{
_n_beta5 += rng.randh();
DNest4::wrap(_n_beta5, 0.0, 1.0);
}
if(which == 17)
{
_n_alpha6 += rng.randh();
DNest4::wrap(_n_alpha6, 0.0, 1.0);
}
if(which == 18)
{
_n_beta6 += rng.randh();
DNest4::wrap(_n_beta6, 0.0, 1.0);
}
if(which == 19)
{
_n_alpha7 += rng.randh();
DNest4::wrap(_n_alpha7, 0.0, 1.0);
}
if(which == 20)
{
_n_beta7 += rng.randh();
DNest4::wrap(_n_beta7, 0.0, 1.0);
}
if(which == 21)
{
_n_alpha8 += rng.randh();
DNest4::wrap(_n_alpha8, 0.0, 1.0);
}
if(which == 22)
{
_n_beta8 += rng.randh();
DNest4::wrap(_n_beta8, 0.0, 1.0);
}
if(which == 23)
{
_n_alpha9 += rng.randh();
DNest4::wrap(_n_alpha9, 0.0, 1.0);
}
if(which == 24)
{
_n_beta9 += rng.randh();
DNest4::wrap(_n_beta9, 0.0, 1.0);
}
if(which == 25)
{
_n_alpha10 += rng.randh();
DNest4::wrap(_n_alpha10, 0.0, 1.0);
}
if(which == 26)
{
_n_beta10 += rng.randh();
DNest4::wrap(_n_beta10, 0.0, 1.0);
}
if(which == 27)
{
_n_alpha11 += rng.randh();
DNest4::wrap(_n_alpha11, 0.0, 1.0);
}
if(which == 28)
{
_n_beta11 += rng.randh();
DNest4::wrap(_n_beta11, 0.0, 1.0);
}
if(which == 29)
{
_n_alpha12 += rng.randh();
DNest4::wrap(_n_alpha12, 0.0, 1.0);
}
if(which == 30)
{
_n_beta12 += rng.randh();
DNest4::wrap(_n_beta12, 0.0, 1.0);
}
if(which == 31)
{
_n_alpha13 += rng.randh();
DNest4::wrap(_n_alpha13, 0.0, 1.0);
}
if(which == 32)
{
_n_beta13 += rng.randh();
DNest4::wrap(_n_beta13, 0.0, 1.0);
}
if(which == 33)
{
_n_alpha14 += rng.randh();
DNest4::wrap(_n_alpha14, 0.0, 1.0);
}
if(which == 34)
{
_n_beta14 += rng.randh();
DNest4::wrap(_n_beta14, 0.0, 1.0);
}
if(which == 35)
{
_n_alpha15 += rng.randh();
DNest4::wrap(_n_alpha15, 0.0, 1.0);
}
if(which == 36)
{
_n_beta15 += rng.randh();
DNest4::wrap(_n_beta15, 0.0, 1.0);
}
if(which == 37)
{
_n_alpha16 += rng.randh();
DNest4::wrap(_n_alpha16, 0.0, 1.0);
}
if(which == 38)
{
_n_beta16 += rng.randh();
DNest4::wrap(_n_beta16, 0.0, 1.0);
}
if(which == 39)
{
_n_alpha17 += rng.randh();
DNest4::wrap(_n_alpha17, 0.0, 1.0);
}
if(which == 40)
{
_n_beta17 += rng.randh();
DNest4::wrap(_n_beta17, 0.0, 1.0);
}
if(which == 41)
{
_n_alpha18 += rng.randh();
DNest4::wrap(_n_alpha18, 0.0, 1.0);
}
if(which == 42)
{
_n_beta18 += rng.randh();
DNest4::wrap(_n_beta18, 0.0, 1.0);
}
if(which == 43)
{
_n_alpha19 += rng.randh();
DNest4::wrap(_n_alpha19, 0.0, 1.0);
}
if(which == 44)
{
_n_beta19 += rng.randh();
DNest4::wrap(_n_beta19, 0.0, 1.0);
}
if(which == 45)
{
_n_alpha20 += rng.randh();
DNest4::wrap(_n_alpha20, 0.0, 1.0);
}
if(which == 46)
{
_n_beta20 += rng.randh();
DNest4::wrap(_n_beta20, 0.0, 1.0);
}
if(which == 47)
{
_n_alpha21 += rng.randh();
DNest4::wrap(_n_alpha21, 0.0, 1.0);
}
if(which == 48)
{
_n_beta21 += rng.randh();
DNest4::wrap(_n_beta21, 0.0, 1.0);
}
if(which == 49)
{
_n_alpha22 += rng.randh();
DNest4::wrap(_n_alpha22, 0.0, 1.0);
}
if(which == 50)
{
_n_beta22 += rng.randh();
DNest4::wrap(_n_beta22, 0.0, 1.0);
}
if(which == 51)
{
_n_alpha23 += rng.randh();
DNest4::wrap(_n_alpha23, 0.0, 1.0);
}
if(which == 52)
{
_n_beta23 += rng.randh();
DNest4::wrap(_n_beta23, 0.0, 1.0);
}
if(which == 53)
{
_n_alpha24 += rng.randh();
DNest4::wrap(_n_alpha24, 0.0, 1.0);
}
if(which == 54)
{
_n_beta24 += rng.randh();
DNest4::wrap(_n_beta24, 0.0, 1.0);
}
if(which == 55)
{
_n_alpha25 += rng.randh();
DNest4::wrap(_n_alpha25, 0.0, 1.0);
}
if(which == 56)
{
_n_beta25 += rng.randh();
DNest4::wrap(_n_beta25, 0.0, 1.0);
}
if(which == 57)
{
_n_alpha26 += rng.randh();
DNest4::wrap(_n_alpha26, 0.0, 1.0);
}
if(which == 58)
{
_n_beta26 += rng.randh();
DNest4::wrap(_n_beta26, 0.0, 1.0);
}
if(which == 59)
{
_n_alpha27 += rng.randh();
DNest4::wrap(_n_alpha27, 0.0, 1.0);
}
if(which == 60)
{
_n_beta27 += rng.randh();
DNest4::wrap(_n_beta27, 0.0, 1.0);
}
if(which == 61)
{
_n_alpha28 += rng.randh();
DNest4::wrap(_n_alpha28, 0.0, 1.0);
}
if(which == 62)
{
_n_beta28 += rng.randh();
DNest4::wrap(_n_beta28, 0.0, 1.0);
}
if(which == 63)
{
_n_alpha29 += rng.randh();
DNest4::wrap(_n_alpha29, 0.0, 1.0);
}
if(which == 64)
{
_n_beta29 += rng.randh();
DNest4::wrap(_n_beta29, 0.0, 1.0);
}
}

alpha_mu = 0.0 + (100.0)*quantile(__boost_dist, _alpha_mu);
beta_mu = 0.0 + (100.0)*quantile(__boost_dist, _beta_mu);
boost::math::gamma_distribution<double> my_gamma_tau_c(0.001, 1000.0);
tau_c = quantile(my_gamma_tau_c, _tau_c);
boost::math::gamma_distribution<double> my_gamma_alpha_tau(0.001, 1000.0);
alpha_tau = quantile(my_gamma_alpha_tau, _alpha_tau);
boost::math::gamma_distribution<double> my_gamma_beta_tau(0.001, 1000.0);
beta_tau = quantile(my_gamma_beta_tau, _beta_tau);
alpha_sigma = 1.0/sqrt(alpha_tau);
beta_sigma = 1.0/sqrt(beta_tau);
sigma_c = 1.0/sqrt(tau_c);
a0 = alpha_mu - beta_mu*x_bar;
n_alpha0 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha0);
n_beta0 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta0);
alpha0 = alpha_mu + alpha_sigma*n_alpha0;
beta0 = beta_mu + beta_sigma*n_beta0;
n_alpha1 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha1);
n_beta1 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta1);
alpha1 = alpha_mu + alpha_sigma*n_alpha1;
beta1 = beta_mu + beta_sigma*n_beta1;
n_alpha2 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha2);
n_beta2 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta2);
alpha2 = alpha_mu + alpha_sigma*n_alpha2;
beta2 = beta_mu + beta_sigma*n_beta2;
n_alpha3 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha3);
n_beta3 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta3);
alpha3 = alpha_mu + alpha_sigma*n_alpha3;
beta3 = beta_mu + beta_sigma*n_beta3;
n_alpha4 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha4);
n_beta4 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta4);
alpha4 = alpha_mu + alpha_sigma*n_alpha4;
beta4 = beta_mu + beta_sigma*n_beta4;
n_alpha5 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha5);
n_beta5 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta5);
alpha5 = alpha_mu + alpha_sigma*n_alpha5;
beta5 = beta_mu + beta_sigma*n_beta5;
n_alpha6 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha6);
n_beta6 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta6);
alpha6 = alpha_mu + alpha_sigma*n_alpha6;
beta6 = beta_mu + beta_sigma*n_beta6;
n_alpha7 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha7);
n_beta7 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta7);
alpha7 = alpha_mu + alpha_sigma*n_alpha7;
beta7 = beta_mu + beta_sigma*n_beta7;
n_alpha8 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha8);
n_beta8 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta8);
alpha8 = alpha_mu + alpha_sigma*n_alpha8;
beta8 = beta_mu + beta_sigma*n_beta8;
n_alpha9 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha9);
n_beta9 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta9);
alpha9 = alpha_mu + alpha_sigma*n_alpha9;
beta9 = beta_mu + beta_sigma*n_beta9;
n_alpha10 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha10);
n_beta10 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta10);
alpha10 = alpha_mu + alpha_sigma*n_alpha10;
beta10 = beta_mu + beta_sigma*n_beta10;
n_alpha11 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha11);
n_beta11 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta11);
alpha11 = alpha_mu + alpha_sigma*n_alpha11;
beta11 = beta_mu + beta_sigma*n_beta11;
n_alpha12 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha12);
n_beta12 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta12);
alpha12 = alpha_mu + alpha_sigma*n_alpha12;
beta12 = beta_mu + beta_sigma*n_beta12;
n_alpha13 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha13);
n_beta13 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta13);
alpha13 = alpha_mu + alpha_sigma*n_alpha13;
beta13 = beta_mu + beta_sigma*n_beta13;
n_alpha14 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha14);
n_beta14 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta14);
alpha14 = alpha_mu + alpha_sigma*n_alpha14;
beta14 = beta_mu + beta_sigma*n_beta14;
n_alpha15 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha15);
n_beta15 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta15);
alpha15 = alpha_mu + alpha_sigma*n_alpha15;
beta15 = beta_mu + beta_sigma*n_beta15;
n_alpha16 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha16);
n_beta16 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta16);
alpha16 = alpha_mu + alpha_sigma*n_alpha16;
beta16 = beta_mu + beta_sigma*n_beta16;
n_alpha17 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha17);
n_beta17 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta17);
alpha17 = alpha_mu + alpha_sigma*n_alpha17;
beta17 = beta_mu + beta_sigma*n_beta17;
n_alpha18 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha18);
n_beta18 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta18);
alpha18 = alpha_mu + alpha_sigma*n_alpha18;
beta18 = beta_mu + beta_sigma*n_beta18;
n_alpha19 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha19);
n_beta19 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta19);
alpha19 = alpha_mu + alpha_sigma*n_alpha19;
beta19 = beta_mu + beta_sigma*n_beta19;
n_alpha20 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha20);
n_beta20 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta20);
alpha20 = alpha_mu + alpha_sigma*n_alpha20;
beta20 = beta_mu + beta_sigma*n_beta20;
n_alpha21 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha21);
n_beta21 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta21);
alpha21 = alpha_mu + alpha_sigma*n_alpha21;
beta21 = beta_mu + beta_sigma*n_beta21;
n_alpha22 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha22);
n_beta22 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta22);
alpha22 = alpha_mu + alpha_sigma*n_alpha22;
beta22 = beta_mu + beta_sigma*n_beta22;
n_alpha23 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha23);
n_beta23 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta23);
alpha23 = alpha_mu + alpha_sigma*n_alpha23;
beta23 = beta_mu + beta_sigma*n_beta23;
n_alpha24 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha24);
n_beta24 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta24);
alpha24 = alpha_mu + alpha_sigma*n_alpha24;
beta24 = beta_mu + beta_sigma*n_beta24;
n_alpha25 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha25);
n_beta25 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta25);
alpha25 = alpha_mu + alpha_sigma*n_alpha25;
beta25 = beta_mu + beta_sigma*n_beta25;
n_alpha26 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha26);
n_beta26 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta26);
alpha26 = alpha_mu + alpha_sigma*n_alpha26;
beta26 = beta_mu + beta_sigma*n_beta26;
n_alpha27 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha27);
n_beta27 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta27);
alpha27 = alpha_mu + alpha_sigma*n_alpha27;
beta27 = beta_mu + beta_sigma*n_beta27;
n_alpha28 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha28);
n_beta28 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta28);
alpha28 = alpha_mu + alpha_sigma*n_alpha28;
beta28 = beta_mu + beta_sigma*n_beta28;
n_alpha29 = 0.0 + (1.0)*quantile(__boost_dist, _n_alpha29);
n_beta29 = 0.0 + (1.0)*quantile(__boost_dist, _n_beta29);
alpha29 = alpha_mu + alpha_sigma*n_alpha29;
beta29 = beta_mu + beta_sigma*n_beta29;

return logH;


}

double MyModel::log_likelihood() const
{
double logp = 0.0;

logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y0) - (alpha0 + beta0*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y30) - (alpha0 + beta0*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y60) - (alpha0 + beta0*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y90) - (alpha0 + beta0*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y120) - (alpha0 + beta0*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y1) - (alpha1 + beta1*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y31) - (alpha1 + beta1*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y61) - (alpha1 + beta1*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y91) - (alpha1 + beta1*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y121) - (alpha1 + beta1*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y2) - (alpha2 + beta2*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y32) - (alpha2 + beta2*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y62) - (alpha2 + beta2*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y92) - (alpha2 + beta2*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y122) - (alpha2 + beta2*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y3) - (alpha3 + beta3*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y33) - (alpha3 + beta3*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y63) - (alpha3 + beta3*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y93) - (alpha3 + beta3*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y123) - (alpha3 + beta3*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y4) - (alpha4 + beta4*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y34) - (alpha4 + beta4*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y64) - (alpha4 + beta4*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y94) - (alpha4 + beta4*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y124) - (alpha4 + beta4*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y5) - (alpha5 + beta5*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y35) - (alpha5 + beta5*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y65) - (alpha5 + beta5*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y95) - (alpha5 + beta5*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y125) - (alpha5 + beta5*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y6) - (alpha6 + beta6*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y36) - (alpha6 + beta6*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y66) - (alpha6 + beta6*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y96) - (alpha6 + beta6*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y126) - (alpha6 + beta6*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y7) - (alpha7 + beta7*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y37) - (alpha7 + beta7*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y67) - (alpha7 + beta7*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y97) - (alpha7 + beta7*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y127) - (alpha7 + beta7*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y8) - (alpha8 + beta8*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y38) - (alpha8 + beta8*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y68) - (alpha8 + beta8*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y98) - (alpha8 + beta8*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y128) - (alpha8 + beta8*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y9) - (alpha9 + beta9*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y39) - (alpha9 + beta9*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y69) - (alpha9 + beta9*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y99) - (alpha9 + beta9*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y129) - (alpha9 + beta9*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y10) - (alpha10 + beta10*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y40) - (alpha10 + beta10*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y70) - (alpha10 + beta10*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y100) - (alpha10 + beta10*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y130) - (alpha10 + beta10*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y11) - (alpha11 + beta11*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y41) - (alpha11 + beta11*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y71) - (alpha11 + beta11*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y101) - (alpha11 + beta11*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y131) - (alpha11 + beta11*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y12) - (alpha12 + beta12*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y42) - (alpha12 + beta12*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y72) - (alpha12 + beta12*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y102) - (alpha12 + beta12*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y132) - (alpha12 + beta12*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y13) - (alpha13 + beta13*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y43) - (alpha13 + beta13*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y73) - (alpha13 + beta13*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y103) - (alpha13 + beta13*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y133) - (alpha13 + beta13*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y14) - (alpha14 + beta14*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y44) - (alpha14 + beta14*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y74) - (alpha14 + beta14*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y104) - (alpha14 + beta14*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y134) - (alpha14 + beta14*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y15) - (alpha15 + beta15*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y45) - (alpha15 + beta15*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y75) - (alpha15 + beta15*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y105) - (alpha15 + beta15*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y135) - (alpha15 + beta15*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y16) - (alpha16 + beta16*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y46) - (alpha16 + beta16*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y76) - (alpha16 + beta16*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y106) - (alpha16 + beta16*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y136) - (alpha16 + beta16*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y17) - (alpha17 + beta17*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y47) - (alpha17 + beta17*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y77) - (alpha17 + beta17*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y107) - (alpha17 + beta17*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y137) - (alpha17 + beta17*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y18) - (alpha18 + beta18*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y48) - (alpha18 + beta18*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y78) - (alpha18 + beta18*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y108) - (alpha18 + beta18*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y138) - (alpha18 + beta18*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y19) - (alpha19 + beta19*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y49) - (alpha19 + beta19*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y79) - (alpha19 + beta19*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y109) - (alpha19 + beta19*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y139) - (alpha19 + beta19*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y20) - (alpha20 + beta20*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y50) - (alpha20 + beta20*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y80) - (alpha20 + beta20*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y110) - (alpha20 + beta20*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y140) - (alpha20 + beta20*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y21) - (alpha21 + beta21*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y51) - (alpha21 + beta21*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y81) - (alpha21 + beta21*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y111) - (alpha21 + beta21*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y141) - (alpha21 + beta21*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y22) - (alpha22 + beta22*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y52) - (alpha22 + beta22*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y82) - (alpha22 + beta22*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y112) - (alpha22 + beta22*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y142) - (alpha22 + beta22*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y23) - (alpha23 + beta23*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y53) - (alpha23 + beta23*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y83) - (alpha23 + beta23*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y113) - (alpha23 + beta23*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y143) - (alpha23 + beta23*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y24) - (alpha24 + beta24*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y54) - (alpha24 + beta24*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y84) - (alpha24 + beta24*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y114) - (alpha24 + beta24*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y144) - (alpha24 + beta24*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y25) - (alpha25 + beta25*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y55) - (alpha25 + beta25*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y85) - (alpha25 + beta25*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y115) - (alpha25 + beta25*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y145) - (alpha25 + beta25*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y26) - (alpha26 + beta26*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y56) - (alpha26 + beta26*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y86) - (alpha26 + beta26*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y116) - (alpha26 + beta26*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y146) - (alpha26 + beta26*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y27) - (alpha27 + beta27*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y57) - (alpha27 + beta27*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y87) - (alpha27 + beta27*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y117) - (alpha27 + beta27*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y147) - (alpha27 + beta27*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y28) - (alpha28 + beta28*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y58) - (alpha28 + beta28*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y88) - (alpha28 + beta28*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y118) - (alpha28 + beta28*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y148) - (alpha28 + beta28*(x4 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y29) - (alpha29 + beta29*(x0 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y59) - (alpha29 + beta29*(x1 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y89) - (alpha29 + beta29*(x2 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y119) - (alpha29 + beta29*(x3 - x_bar)))/(sigma_c), 2);
logp += -0.5*log(2*M_PI) - log(sigma_c) - 0.5*pow(((Y149) - (alpha29 + beta29*(x4 - x_bar)))/(sigma_c), 2);
if(std::isnan(logp) || std::isinf(logp))
    logp = -1E300;

return logp;

}

void MyModel::print(std::ostream& out) const
{
out<<setprecision(12);
out<<alpha_mu<<' ';
out<<beta_mu<<' ';
out<<tau_c<<' ';
out<<alpha_tau<<' ';
out<<beta_tau<<' ';
out<<alpha_sigma<<' ';
out<<beta_sigma<<' ';
out<<sigma_c<<' ';
out<<a0<<' ';
out<<n_alpha0<<' ';
out<<n_beta0<<' ';
out<<alpha0<<' ';
out<<beta0<<' ';
out<<n_alpha1<<' ';
out<<n_beta1<<' ';
out<<alpha1<<' ';
out<<beta1<<' ';
out<<n_alpha2<<' ';
out<<n_beta2<<' ';
out<<alpha2<<' ';
out<<beta2<<' ';
out<<n_alpha3<<' ';
out<<n_beta3<<' ';
out<<alpha3<<' ';
out<<beta3<<' ';
out<<n_alpha4<<' ';
out<<n_beta4<<' ';
out<<alpha4<<' ';
out<<beta4<<' ';
out<<n_alpha5<<' ';
out<<n_beta5<<' ';
out<<alpha5<<' ';
out<<beta5<<' ';
out<<n_alpha6<<' ';
out<<n_beta6<<' ';
out<<alpha6<<' ';
out<<beta6<<' ';
out<<n_alpha7<<' ';
out<<n_beta7<<' ';
out<<alpha7<<' ';
out<<beta7<<' ';
out<<n_alpha8<<' ';
out<<n_beta8<<' ';
out<<alpha8<<' ';
out<<beta8<<' ';
out<<n_alpha9<<' ';
out<<n_beta9<<' ';
out<<alpha9<<' ';
out<<beta9<<' ';
out<<n_alpha10<<' ';
out<<n_beta10<<' ';
out<<alpha10<<' ';
out<<beta10<<' ';
out<<n_alpha11<<' ';
out<<n_beta11<<' ';
out<<alpha11<<' ';
out<<beta11<<' ';
out<<n_alpha12<<' ';
out<<n_beta12<<' ';
out<<alpha12<<' ';
out<<beta12<<' ';
out<<n_alpha13<<' ';
out<<n_beta13<<' ';
out<<alpha13<<' ';
out<<beta13<<' ';
out<<n_alpha14<<' ';
out<<n_beta14<<' ';
out<<alpha14<<' ';
out<<beta14<<' ';
out<<n_alpha15<<' ';
out<<n_beta15<<' ';
out<<alpha15<<' ';
out<<beta15<<' ';
out<<n_alpha16<<' ';
out<<n_beta16<<' ';
out<<alpha16<<' ';
out<<beta16<<' ';
out<<n_alpha17<<' ';
out<<n_beta17<<' ';
out<<alpha17<<' ';
out<<beta17<<' ';
out<<n_alpha18<<' ';
out<<n_beta18<<' ';
out<<alpha18<<' ';
out<<beta18<<' ';
out<<n_alpha19<<' ';
out<<n_beta19<<' ';
out<<alpha19<<' ';
out<<beta19<<' ';
out<<n_alpha20<<' ';
out<<n_beta20<<' ';
out<<alpha20<<' ';
out<<beta20<<' ';
out<<n_alpha21<<' ';
out<<n_beta21<<' ';
out<<alpha21<<' ';
out<<beta21<<' ';
out<<n_alpha22<<' ';
out<<n_beta22<<' ';
out<<alpha22<<' ';
out<<beta22<<' ';
out<<n_alpha23<<' ';
out<<n_beta23<<' ';
out<<alpha23<<' ';
out<<beta23<<' ';
out<<n_alpha24<<' ';
out<<n_beta24<<' ';
out<<alpha24<<' ';
out<<beta24<<' ';
out<<n_alpha25<<' ';
out<<n_beta25<<' ';
out<<alpha25<<' ';
out<<beta25<<' ';
out<<n_alpha26<<' ';
out<<n_beta26<<' ';
out<<alpha26<<' ';
out<<beta26<<' ';
out<<n_alpha27<<' ';
out<<n_beta27<<' ';
out<<alpha27<<' ';
out<<beta27<<' ';
out<<n_alpha28<<' ';
out<<n_beta28<<' ';
out<<alpha28<<' ';
out<<beta28<<' ';
out<<n_alpha29<<' ';
out<<n_beta29<<' ';
out<<alpha29<<' ';
out<<beta29<<' ';

}

string MyModel::description() const
{
return string("alpha_mu, beta_mu, tau_c, alpha_tau, beta_tau, alpha_sigma, beta_sigma, sigma_c, a0, n_alpha0, n_beta0, alpha0, beta0, n_alpha1, n_beta1, alpha1, beta1, n_alpha2, n_beta2, alpha2, beta2, n_alpha3, n_beta3, alpha3, beta3, n_alpha4, n_beta4, alpha4, beta4, n_alpha5, n_beta5, alpha5, beta5, n_alpha6, n_beta6, alpha6, beta6, n_alpha7, n_beta7, alpha7, beta7, n_alpha8, n_beta8, alpha8, beta8, n_alpha9, n_beta9, alpha9, beta9, n_alpha10, n_beta10, alpha10, beta10, n_alpha11, n_beta11, alpha11, beta11, n_alpha12, n_beta12, alpha12, beta12, n_alpha13, n_beta13, alpha13, beta13, n_alpha14, n_beta14, alpha14, beta14, n_alpha15, n_beta15, alpha15, beta15, n_alpha16, n_beta16, alpha16, beta16, n_alpha17, n_beta17, alpha17, beta17, n_alpha18, n_beta18, alpha18, beta18, n_alpha19, n_beta19, alpha19, beta19, n_alpha20, n_beta20, alpha20, beta20, n_alpha21, n_beta21, alpha21, beta21, n_alpha22, n_beta22, alpha22, beta22, n_alpha23, n_beta23, alpha23, beta23, n_alpha24, n_beta24, alpha24, beta24, n_alpha25, n_beta25, alpha25, beta25, n_alpha26, n_beta26, alpha26, beta26, n_alpha27, n_beta27, alpha27, beta27, n_alpha28, n_beta28, alpha28, beta28, n_alpha29, n_beta29, alpha29, beta29");
}

