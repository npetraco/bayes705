#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _beta0, beta0;
double _beta1, beta1;
double _epsilon, epsilon;
static constexpr double x0 = 0.1716393;
static constexpr double x1 = 0.2905149;
static constexpr double x2 = 0.5521852;
static constexpr double x3 = 0.8684159;
static constexpr double x4 = 1.046752;
static constexpr double x5 = 1.279638;
static constexpr double y0 = 0.05;
static constexpr double y1 = 0.1;
static constexpr double y2 = 0.2;
static constexpr double y3 = 0.3;
static constexpr double y4 = 0.4;
static constexpr double y5 = 0.5;
static constexpr int N = 6;


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

