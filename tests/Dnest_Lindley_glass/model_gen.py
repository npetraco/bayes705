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
model.add_node(bd.Node("mucssp", bd.Normal(1.51, 0.01)))  # Hp
# model.add_node(bd.Node("mucs", bd.Normal(1.51, 0.01)))  # Hd
# model.add_node(bd.Node("musp", bd.Normal(1.51, 0.01)))  # Hd

# Likelihood
model.add_node(bd.Node("Xb", bd.Normal("mucssp", "sCS"), observed=True))  # Hp
model.add_node(bd.Node("Yb", bd.Normal("mucssp", "sSP"), observed=True))  # Hp
# model.add_node(bd.Node("Xb", bd.Normal("mucs", "sCS"), observed=True))  # Hd
# model.add_node(bd.Node("Yb", bd.Normal("musp", "sSP"), observed=True))  # Hd

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z) = XXXXX
# Hp: log(Z) = -4.29510326831  # Super Wide prior, mu = 0, sigma = 10000
# Hd: log(Z) = -20.2646307676

# Hp: log(Z) = 6.2838851384   Lindley 100-times prior
# Hd: log(Z) = 0.929623063405

# Hp: log(Z) = 8.54392798704  10-times prior
# Hd: log(Z) = 5.4633152605

# Hp: log(Z) = 9.23215345203  4-times prior
# Hd: log(Z) = 6.83558525858
