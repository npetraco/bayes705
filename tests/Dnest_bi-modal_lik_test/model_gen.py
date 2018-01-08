import numpy as np
import dnest4.builder as bd

data = {"D": np.array([10.0])}

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("mu", bd.Cauchy(10, 10)))

# Likelihood p(D|mu)
name = "D{index}".format(index=0)
model.add_node(bd.Node(name, bd.Normal("mu", 0.15), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)
