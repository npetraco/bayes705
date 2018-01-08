#ifndef DNest4_Builder_MyModel
#define DNest4_Builder_MyModel

#include "DNest4.h"
#include <ostream>
#include <vector>

class MyModel
{
    private:
double _log_mu1, log_mu1;
double _diff, diff;
double log_mu2;
double mu1;
double mu2;
double _change_year, change_year;
double _L, L;
static constexpr double t0 = 1851.0;
static constexpr double t1 = 1852.0;
static constexpr double t2 = 1853.0;
static constexpr double t3 = 1854.0;
static constexpr double t4 = 1855.0;
static constexpr double t5 = 1856.0;
static constexpr double t6 = 1857.0;
static constexpr double t7 = 1858.0;
static constexpr double t8 = 1859.0;
static constexpr double t9 = 1860.0;
static constexpr double t10 = 1861.0;
static constexpr double t11 = 1862.0;
static constexpr double t12 = 1863.0;
static constexpr double t13 = 1864.0;
static constexpr double t14 = 1865.0;
static constexpr double t15 = 1866.0;
static constexpr double t16 = 1867.0;
static constexpr double t17 = 1868.0;
static constexpr double t18 = 1869.0;
static constexpr double t19 = 1870.0;
static constexpr double t20 = 1871.0;
static constexpr double t21 = 1872.0;
static constexpr double t22 = 1873.0;
static constexpr double t23 = 1874.0;
static constexpr double t24 = 1875.0;
static constexpr double t25 = 1876.0;
static constexpr double t26 = 1877.0;
static constexpr double t27 = 1878.0;
static constexpr double t28 = 1879.0;
static constexpr double t29 = 1880.0;
static constexpr double t30 = 1881.0;
static constexpr double t31 = 1882.0;
static constexpr double t32 = 1883.0;
static constexpr double t33 = 1884.0;
static constexpr double t34 = 1885.0;
static constexpr double t35 = 1886.0;
static constexpr double t36 = 1887.0;
static constexpr double t37 = 1888.0;
static constexpr double t38 = 1889.0;
static constexpr double t39 = 1890.0;
static constexpr double t40 = 1891.0;
static constexpr double t41 = 1892.0;
static constexpr double t42 = 1893.0;
static constexpr double t43 = 1894.0;
static constexpr double t44 = 1895.0;
static constexpr double t45 = 1896.0;
static constexpr double t46 = 1897.0;
static constexpr double t47 = 1898.0;
static constexpr double t48 = 1899.0;
static constexpr double t49 = 1900.0;
static constexpr double t50 = 1901.0;
static constexpr double t51 = 1902.0;
static constexpr double t52 = 1903.0;
static constexpr double t53 = 1904.0;
static constexpr double t54 = 1905.0;
static constexpr double t55 = 1906.0;
static constexpr double t56 = 1907.0;
static constexpr double t57 = 1908.0;
static constexpr double t58 = 1909.0;
static constexpr double t59 = 1910.0;
static constexpr double t60 = 1911.0;
static constexpr double t61 = 1912.0;
static constexpr double t62 = 1913.0;
static constexpr double t63 = 1914.0;
static constexpr double t64 = 1915.0;
static constexpr double t65 = 1916.0;
static constexpr double t66 = 1917.0;
static constexpr double t67 = 1918.0;
static constexpr double t68 = 1919.0;
static constexpr double t69 = 1920.0;
static constexpr double t70 = 1921.0;
static constexpr double t71 = 1922.0;
static constexpr double t72 = 1923.0;
static constexpr double t73 = 1924.0;
static constexpr double t74 = 1925.0;
static constexpr double t75 = 1926.0;
static constexpr double t76 = 1927.0;
static constexpr double t77 = 1928.0;
static constexpr double t78 = 1929.0;
static constexpr double t79 = 1930.0;
static constexpr double t80 = 1931.0;
static constexpr double t81 = 1932.0;
static constexpr double t82 = 1933.0;
static constexpr double t83 = 1934.0;
static constexpr double t84 = 1935.0;
static constexpr double t85 = 1936.0;
static constexpr double t86 = 1937.0;
static constexpr double t87 = 1938.0;
static constexpr double t88 = 1939.0;
static constexpr double t89 = 1940.0;
static constexpr double t90 = 1941.0;
static constexpr double t91 = 1942.0;
static constexpr double t92 = 1943.0;
static constexpr double t93 = 1944.0;
static constexpr double t94 = 1945.0;
static constexpr double t95 = 1946.0;
static constexpr double t96 = 1947.0;
static constexpr double t97 = 1948.0;
static constexpr double t98 = 1949.0;
static constexpr double t99 = 1950.0;
static constexpr double t100 = 1951.0;
static constexpr double t101 = 1952.0;
static constexpr double t102 = 1953.0;
static constexpr double t103 = 1954.0;
static constexpr double t104 = 1955.0;
static constexpr double t105 = 1956.0;
static constexpr double t106 = 1957.0;
static constexpr double t107 = 1958.0;
static constexpr double t108 = 1959.0;
static constexpr double t109 = 1960.0;
static constexpr double t110 = 1961.0;
static constexpr double t111 = 1962.0;
static constexpr double y0 = 4.0;
static constexpr double y1 = 5.0;
static constexpr double y2 = 4.0;
static constexpr double y3 = 1.0;
static constexpr double y4 = 0.0;
static constexpr double y5 = 4.0;
static constexpr double y6 = 3.0;
static constexpr double y7 = 4.0;
static constexpr double y8 = 0.0;
static constexpr double y9 = 6.0;
static constexpr double y10 = 3.0;
static constexpr double y11 = 3.0;
static constexpr double y12 = 4.0;
static constexpr double y13 = 0.0;
static constexpr double y14 = 2.0;
static constexpr double y15 = 6.0;
static constexpr double y16 = 3.0;
static constexpr double y17 = 3.0;
static constexpr double y18 = 5.0;
static constexpr double y19 = 4.0;
static constexpr double y20 = 5.0;
static constexpr double y21 = 3.0;
static constexpr double y22 = 1.0;
static constexpr double y23 = 4.0;
static constexpr double y24 = 4.0;
static constexpr double y25 = 1.0;
static constexpr double y26 = 5.0;
static constexpr double y27 = 5.0;
static constexpr double y28 = 3.0;
static constexpr double y29 = 4.0;
static constexpr double y30 = 2.0;
static constexpr double y31 = 5.0;
static constexpr double y32 = 2.0;
static constexpr double y33 = 2.0;
static constexpr double y34 = 3.0;
static constexpr double y35 = 4.0;
static constexpr double y36 = 2.0;
static constexpr double y37 = 1.0;
static constexpr double y38 = 3.0;
static constexpr double y39 = 2.0;
static constexpr double y40 = 2.0;
static constexpr double y41 = 1.0;
static constexpr double y42 = 1.0;
static constexpr double y43 = 1.0;
static constexpr double y44 = 1.0;
static constexpr double y45 = 3.0;
static constexpr double y46 = 0.0;
static constexpr double y47 = 0.0;
static constexpr double y48 = 1.0;
static constexpr double y49 = 0.0;
static constexpr double y50 = 1.0;
static constexpr double y51 = 1.0;
static constexpr double y52 = 0.0;
static constexpr double y53 = 0.0;
static constexpr double y54 = 3.0;
static constexpr double y55 = 1.0;
static constexpr double y56 = 0.0;
static constexpr double y57 = 3.0;
static constexpr double y58 = 2.0;
static constexpr double y59 = 2.0;
static constexpr double y60 = 0.0;
static constexpr double y61 = 1.0;
static constexpr double y62 = 1.0;
static constexpr double y63 = 1.0;
static constexpr double y64 = 0.0;
static constexpr double y65 = 1.0;
static constexpr double y66 = 0.0;
static constexpr double y67 = 1.0;
static constexpr double y68 = 0.0;
static constexpr double y69 = 0.0;
static constexpr double y70 = 0.0;
static constexpr double y71 = 2.0;
static constexpr double y72 = 1.0;
static constexpr double y73 = 0.0;
static constexpr double y74 = 0.0;
static constexpr double y75 = 0.0;
static constexpr double y76 = 1.0;
static constexpr double y77 = 1.0;
static constexpr double y78 = 0.0;
static constexpr double y79 = 2.0;
static constexpr double y80 = 3.0;
static constexpr double y81 = 3.0;
static constexpr double y82 = 1.0;
static constexpr double y83 = 1.0;
static constexpr double y84 = 2.0;
static constexpr double y85 = 1.0;
static constexpr double y86 = 1.0;
static constexpr double y87 = 1.0;
static constexpr double y88 = 1.0;
static constexpr double y89 = 2.0;
static constexpr double y90 = 4.0;
static constexpr double y91 = 2.0;
static constexpr double y92 = 0.0;
static constexpr double y93 = 0.0;
static constexpr double y94 = 0.0;
static constexpr double y95 = 1.0;
static constexpr double y96 = 4.0;
static constexpr double y97 = 0.0;
static constexpr double y98 = 0.0;
static constexpr double y99 = 0.0;
static constexpr double y100 = 1.0;
static constexpr double y101 = 0.0;
static constexpr double y102 = 0.0;
static constexpr double y103 = 0.0;
static constexpr double y104 = 0.0;
static constexpr double y105 = 0.0;
static constexpr double y106 = 1.0;
static constexpr double y107 = 0.0;
static constexpr double y108 = 0.0;
static constexpr double y109 = 1.0;
static constexpr double y110 = 0.0;
static constexpr double y111 = 1.0;
static constexpr int N = 112;


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

