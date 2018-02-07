import math
import numpy as np
import dnest4.builder as bd

# Data
# Ntz original data:
#data = {"y": np.array([554, 701, 749, 868, 516, 573, 978, 399]),
#        "n": np.array([1183, 1510, 1597, 1924, 1178, 1324, 2173, 845]),
#        "N": 8}
# Kobe Bryant's whole field goal record from NBA records:
data = {"y": np.array([176, 391, 362, 554, 701, 749, 868, 516, 573, 978, 813, 775, 800, 716, 740]),
        "n": np.array([422, 913, 779, 1183, 1510, 1597, 1924, 1178, 1324, 2173, 1757, 1690, 1712, 1569, 1639]),
        "N": 15}

# Create the model
model = bd.Model()

# Prior p(m)
for i in range(0, data["N"]):
    ppi = "ppi{index}".format(index=i)
    model.add_node(bd.Node(ppi, bd.Uniform(0, 1)))

# Likelihood p(D|n,p) place holder.
for i in range(0, data["N"]):
    suc = "y{index}".format(index=i)
    atp = "n{index}".format(index=i)
    ppi = "ppi{index}".format(index=i)
    model.add_node(bd.Node(suc, bd.Binomial(atp, ppi), observed=True))


# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# take1      log(Z) = -58.0551362482 with Ntz original data
# take2      log(Z) = -57.9893885883  with Ntz original data
# take3      log(Z) = -57.9826848935  with Ntz original data
# Analytical log(Z) = -58.0228

# take1      log(Z) = -107.89689068 with whole record
# take2      log(Z) = -107.99314548 with whole record
# Analytical log(Z) = -107.919
