import math
import numpy as np
import dnest4.builder as bd

# Data, shell centers:
data = {"cx": np.array([3.5,-3.5]),
        "cy": np.array([0.0,0.0])}

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("m1", bd.Uniform(-6.0, 6.0)))
model.add_node(bd.Node("m2", bd.Uniform(-6.0, 6.0)))

# Likelihood p(D|mu) place holder. Will have to enter shell likelihood by hand.
name = "D{index}".format(index=0)
model.add_node(bd.Node(name, bd.Normal("mu", 1), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z)                  = -1.72298793735, -1.74864668478, -1.75171455818
# Feroz analytical integration result = −1.75
# Feroz Multinest result              = -1.61, -1.71, -1.72, -1.69 depending on control params
# Mathematica result:                 = 