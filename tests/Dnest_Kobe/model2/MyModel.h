#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _ppi0, ppi0;
double _ppi1, ppi1;
double _ppi2, ppi2;
double _ppi3, ppi3;
double _ppi4, ppi4;
double _ppi5, ppi5;
double _ppi6, ppi6;
double _ppi7, ppi7;
double _ppi8, ppi8;
double _ppi9, ppi9;
double _ppi10, ppi10;
double _ppi11, ppi11;
double _ppi12, ppi12;
double _ppi13, ppi13;
double _ppi14, ppi14;
static constexpr int y0 = 176;
static constexpr int y1 = 391;
static constexpr int y2 = 362;
static constexpr int y3 = 554;
static constexpr int y4 = 701;
static constexpr int y5 = 749;
static constexpr int y6 = 868;
static constexpr int y7 = 516;
static constexpr int y8 = 573;
static constexpr int y9 = 978;
static constexpr int y10 = 813;
static constexpr int y11 = 775;
static constexpr int y12 = 800;
static constexpr int y13 = 716;
static constexpr int y14 = 740;
static constexpr int n0 = 422;
static constexpr int n1 = 913;
static constexpr int n2 = 779;
static constexpr int n3 = 1183;
static constexpr int n4 = 1510;
static constexpr int n5 = 1597;
static constexpr int n6 = 1924;
static constexpr int n7 = 1178;
static constexpr int n8 = 1324;
static constexpr int n9 = 2173;
static constexpr int n10 = 1757;
static constexpr int n11 = 1690;
static constexpr int n12 = 1712;
static constexpr int n13 = 1569;
static constexpr int n14 = 1639;
static constexpr int N = 15;


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

