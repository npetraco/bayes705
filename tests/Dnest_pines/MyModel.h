#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _a, a;
double _b, b;
double _sig1, sig1;
static constexpr double y0 = 0.05376191;
static constexpr double y1 = -0.58339657;
static constexpr double y2 = 0.69092039;
static constexpr double y3 = 0.54560355;
static constexpr double y4 = 0.91448477;
static constexpr double y5 = -0.73989164;
static constexpr double y6 = -1.33233725;
static constexpr double y7 = 0.13200944;
static constexpr double y8 = 0.18790054;
static constexpr double y9 = -0.76224808;
static constexpr double y10 = 1.52928682;
static constexpr double y11 = -1.2429115;
static constexpr double y12 = 0.75798971;
static constexpr double y13 = -1.39940656;
static constexpr double y14 = -0.82931739;
static constexpr double y15 = -0.38218863;
static constexpr double y16 = 2.21115818;
static constexpr double y17 = -0.41572329;
static constexpr double y18 = -0.10273316;
static constexpr double y19 = -1.4776541;
static constexpr double y20 = -0.50514904;
static constexpr double y21 = 0.94801943;
static constexpr double y22 = 0.90330656;
static constexpr double y23 = 1.79756408;
static constexpr double y24 = -1.22055506;
static constexpr double y25 = -0.51632726;
static constexpr double y26 = -0.08037672;
static constexpr double y27 = 2.23351462;
static constexpr double y28 = -1.4776541;
static constexpr double y29 = 0.35557382;
static constexpr double y30 = 0.51206889;
static constexpr double y31 = 0.67974218;
static constexpr double y32 = -0.15862425;
static constexpr double y33 = -1.56707985;
static constexpr double y34 = 0.8697719;
static constexpr double y35 = 0.95919765;
static constexpr double y36 = -0.57221835;
static constexpr double y37 = 0.64620752;
static constexpr double y38 = -0.41572329;
static constexpr double y39 = -1.23173328;
static constexpr double y40 = 0.04258369;
static constexpr double y41 = 0.04258369;
static constexpr double x0 = -0.29867323;
static constexpr double x1 = -0.98720981;
static constexpr double x2 = 1.16446699;
static constexpr double x3 = 0.90626577;
static constexpr double x4 = 0.88474901;
static constexpr double x5 = -0.62142475;
static constexpr double x6 = -1.63271284;
static constexpr double x7 = 0.08862859;
static constexpr double x8 = -0.10502232;
static constexpr double x9 = -0.62142475;
static constexpr double x10 = 1.37963467;
static constexpr double x11 = -1.24541102;
static constexpr double x12 = 0.47593041;
static constexpr double x13 = -1.03024334;
static constexpr double x14 = -0.64294152;
static constexpr double x15 = -0.32019;
static constexpr double x16 = 1.59480235;
static constexpr double x17 = -0.23412293;
static constexpr double x18 = -0.08350555;
static constexpr double x19 = -1.4605787;
static constexpr double x20 = -0.62142475;
static constexpr double x21 = 0.84171547;
static constexpr double x22 = 1.25053406;
static constexpr double x23 = 1.22901729;
static constexpr double x24 = -1.28844456;
static constexpr double x25 = -0.79355889;
static constexpr double x26 = 0.64806456;
static constexpr double x27 = 2.4339563;
static constexpr double x28 = -1.18086072;
static constexpr double x29 = 0.36834657;
static constexpr double x30 = 0.51896395;
static constexpr double x31 = 0.99233285;
static constexpr double x32 = -0.19108939;
static constexpr double x33 = -1.15934395;
static constexpr double x34 = 0.64806456;
static constexpr double x35 = 0.8201987;
static constexpr double x36 = -0.90114273;
static constexpr double x37 = 0.7556484;
static constexpr double x38 = -0.64294152;
static constexpr double x39 = -1.80484699;
static constexpr double x40 = 0.56199749;
static constexpr double x41 = 0.30379627;
static constexpr int N = 42;


    public:
        // Constructor only gives size of params
        MyModel();

        // Generate the point from the prior
        void from_prior(DNest4::RNG& rng);

        // Metropolis-Hastings proposals
        double perturb(DNest4::RNG& rng);

        // Likelihood function
        double log_likelihood() const;

        // Print to stream
        void print(std::ostream& out) const;

        // Return string with column information
        std::string description() const;
};

#endif

