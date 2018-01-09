import math
import numpy as np
import dnest4.builder as bd

# Placeholder. data not needed
data = {"D": np.array([1.0])}

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("r", bd.Uniform(0.0, 20.0)))
model.add_node(bd.Node("th", bd.Uniform(0.0, math.pi)))
model.add_node(bd.Node("ph", bd.Uniform(0.0, 2.0 * math.pi)))

# Likelihood p(D|mu) place holder. Will have to enter likelihood by hand.
name = "D{index}".format(index=0)
model.add_node(bd.Node(name, bd.Normal("mu", 1), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z)                 = about -6.0....
