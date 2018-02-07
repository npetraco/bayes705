import math
import numpy as np
import dnest4.builder as bd

# Daniel Azevedo GC-Ethanol Data:
data = {"x": np.array([0.1716393, 0.2905149, 0.5521852, 0.8684159, 1.046752, 1.279638]),  # AreaRatio
        "y": np.array([0.05, 0.1, 0.2, 0.3, 0.4, 0.5]),                                  # Concentration
        "N": 6}


# Create the model
model = bd.Model()

# Prior p(m). Need to modify C++ for Half-Cauchy
model.add_node(bd.Node("beta0", bd.Cauchy(0, 1)))
model.add_node(bd.Node("beta1", bd.Cauchy(0, 5)))  # Should be Half-Cauchy
model.add_node(bd.Node("epsilon", bd.Normal(0, 1)))

# Likelihood p(data | parameters)
for i in range(0, data["N"]):
    name = "y{index}".format(index=i)
    mean = "beta1*x{index} + beta0".format(index=i)
    model.add_node(bd.Node(name, bd.Normal(mean, "epsilon"), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z)                 = XXXX
# Mathematica result:                = XXXX
