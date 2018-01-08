import math
import numpy as np
import dnest4.builder as bd

# Placeholder. data not needed
data = {"D": np.array([1.0])}

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("a", bd.Uniform(0, 10 * math.pi)))
model.add_node(bd.Node("b", bd.Uniform(0, 10 * math.pi)))

# Likelihood p(D|mu) place holder. Will have to enter egg-box likelihood by hand.
name = "D{index}".format(index=0)
model.add_node(bd.Node(name, bd.Normal("mu", 1), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z)                 = 235.85129744
# Feroz numerical integration result = 235.856
# Feroz Multinest result             = 235.835 and 235.839
# Mathematica result:                = 231.944