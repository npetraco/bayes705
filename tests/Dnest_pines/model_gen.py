import math
import numpy as np
import dnest4.builder as bd

# Placeholder. data not needed
data = {"y": np.array([
        0.05376191, -0.58339657, 0.69092039, 0.54560355, 0.91448477, -0.73989164, -1.33233725,
        0.13200944, 0.18790054, -0.76224808, 1.52928682, -1.24291150, 0.75798971, -1.39940656,
        -0.82931739, -0.38218863, 2.21115818, -0.41572329, -0.10273316, -1.47765410, -0.50514904,
        0.94801943, 0.90330656, 1.79756408, -1.22055506, -0.51632726, -0.08037672, 2.23351462,
        -1.47765410, 0.35557382, 0.51206889, 0.67974218, -0.15862425, -1.56707985, 0.86977190,
        0.95919765, -0.57221835, 0.64620752, -0.41572329, -1.23173328, 0.04258369, 0.04258369
        ]),
        #       "x": np.array([  # this is the x data, IE MODEL 1
        #           0.29824462, -0.70296734, 0.98796842, 0.76547687, 0.80997518, -0.74746565, -1.77092677,
        #           -0.12448932, -0.16898763, -0.85871142, 1.32170574, -1.41494029, 0.96571926, -1.19244874,
        #           -0.07999101, -0.50272495, 1.47744982, -0.36923002, -0.25798425, -1.50393691, -0.83646227,
        #           0.63198194, 1.07696504, 1.05471588, -1.28144536, -0.56947241, 0.65423110, 2.45641263,
        #           -1.28144536, 0.29824462, 0.49848701, 0.78772602, -0.25798425, -1.28144536, 0.54298532,
        #           0.92122095, -1.03670466, 0.54298532, 0.45398870, -1.57068437, 1.18821081, 0.07575307
        #       ]),
        "x": np.array([  # this is the z data, IE MODEL 2
            -0.29867323, -0.98720981, 1.16446699, 0.90626577, 0.88474901, -0.62142475, -1.63271284,
            0.08862859, -0.10502232, -0.62142475, 1.37963467, -1.24541102, 0.47593041, -1.03024334,
            -0.64294152, -0.32019000, 1.59480235, -0.23412293, -0.08350555, -1.46057870, -0.62142475,
            0.84171547, 1.25053406, 1.22901729, -1.28844456, -0.79355889, 0.64806456, 2.43395630,
            -1.18086072, 0.36834657, 0.51896395, 0.99233285, -0.19108939, -1.15934395, 0.64806456,
            0.82019870, -0.90114273, 0.75564840, -0.64294152, -1.80484699, 0.56199749, 0.30379627
        ]),
        "N": 42}

# Create the model
model = bd.Model()

# Prior p(m)
model.add_node(bd.Node("a", bd.Normal(0, 1000)))
model.add_node(bd.Node("b", bd.Normal(0, 100)))
# Need to modify C++ for Half-Cauchy on sigma_1
#model.add_node(bd.Node("sig1", bd.Cauchy(0, 5)))
model.add_node(bd.Node("sig1", bd.Uniform(0, 1e8)))

# Likelihood p(data | parameters)
for i in range(0, data["N"]):
    name = "y{index}".format(index=i)
    mean = "b*x{index} + a".format(index=i)
    model.add_node(bd.Node(name, bd.Normal(mean, "sig1"), observed=True))

# Create the C++ code
bd.generate_h(model, data)
bd.generate_cpp(model, data)

# Run result: log(Z)                 = -41.6702379243 for Model 1
# Run result: log(Z)                 = -33.7010828147 for Model 2

# Run result: log(Z)                 =  -44.6145721304 for Model 1 wide prior
# Run result: log(Z)                 =  -36.6713651172 for Model 2 wide prior

# Run result: log(Z)                 =  -39.2915391607 for Model 1 gelman prior
# Run result: log(Z)                 =  -31.3814191779 for Model 2 gelman prior

# Run result: log(Z)                 =  -46.5613022641 for Model 1 uniform prior
# Run result: log(Z)                 =  -38.6908041422 for Model 2 uniform prior

# Run result: log(Z)                 =  -55.7249075822 for Model 1 super wide uniform prior
# Run result: log(Z)                 =  -47.5930517935 for Model 2 super wide uniform prior


# Us:                             BF = 2890 (50)
# Us wider prior:                 BF = 2816 (1000)
# Us gelman prior:                BF = 2724 (5)
# Us uniform prior                BF = 2619 (10000)
# Us uniform prior                BF = 3400 (1e8)
# Speigelhalter:                  BF = 3389
# Carlin, Chib:                   BF = 4420
