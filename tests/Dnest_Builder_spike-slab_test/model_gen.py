import math
import numpy as np
import dnest4.builder as bd

# Placeholder. data not needed
data = {"D": np.array([10.0]),
        "u": np.array([0.01]),
        "v": np.array([0.1])
        }

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("th", bd.Uniform(-0.5, 0.5)))

# Likelihood p(D|mu) place holder. Will have to enter egg-box likelihood by hand.
name = "D{index}".format(index=0)
model.add_node(bd.Node(name, bd.Normal("mu", 1), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z)                 = 0.684022078176
# Mathematica result:                = log(2) = 0.693147
