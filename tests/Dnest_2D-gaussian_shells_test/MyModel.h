#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _m1, m1;
double _m2, m2;
static constexpr double cx0 = 3.5;
static constexpr double cx1 = -3.5;
static constexpr double cy0 = 0.0;
static constexpr double cy1 = 0.0;


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

