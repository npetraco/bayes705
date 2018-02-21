import math
import numpy as np
import dnest4.builder as bd

# Placeholder. data not needed
data = {
    "Xb": 1.517116,
    "sCS": 0.0004726074,
    "Yb": 1.517456,
    "sSP": 0.001038594
}

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("mucssp", bd.Normal(1.5, 0.5)))

# Likelihood
model.add_node(bd.Node("Xb", bd.Normal("mucssp", "sCS"), observed=True))
model.add_node(bd.Node("Yb", bd.Normal("mucssp", "sSP"), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z) = XXXXX
