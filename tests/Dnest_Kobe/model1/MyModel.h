#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _p, p;
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

