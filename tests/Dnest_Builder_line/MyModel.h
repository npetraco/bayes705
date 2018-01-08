#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _m, m;
double _b, b;
double _log_sigma, log_sigma;
double sigma;
static constexpr double x0 = 1.0;
static constexpr double x1 = 2.0;
static constexpr double x2 = 3.0;
static constexpr double x3 = 4.0;
static constexpr double x4 = 5.0;
static constexpr double y0 = 1.0;
static constexpr double y1 = 2.0;
static constexpr double y2 = 3.0;
static constexpr double y3 = 3.9;
static constexpr double y4 = 5.1;
static constexpr int N = 5;


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

