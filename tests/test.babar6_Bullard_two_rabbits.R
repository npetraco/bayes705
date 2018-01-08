setwd("/Users/npetraco/Desktop/marg_lik/nested_sampling/nsr_expts/")
source("nested_babar_mod2.R")
source("params2priors_babar_mod1.R")

obs.D <- c(12,32)

# Model 1 prior
transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = ExponentialPrior(params[1], rate = 0.1) # lambda
  return(tParams)
}

# Model 1 log-likelihood
llf <- function(params) {
  tParams = transform(params)
  lambda = tParams[1]
  ll <- dpois(obs.D[1], lambda = lambda, log = T) + dpois(obs.D[2], lambda = lambda, log = T)
  return(ll)
}

# Model 2 prior
transform2 <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = ExponentialPrior(params[1], rate = 0.1) # lambda1
  tParams[2] = ExponentialPrior(params[2], rate = 0.1) # lambda2
  return(tParams)
}

# Model 2 log-likelihood
llf2 <- function(params) {
  tParams = transform2(params) # REMEMBER TO CHANGE NAME!!!!!!!!!
  lambda1 = tParams[1]
  lambda2 = tParams[2]
  ll <- dpois(obs.D[1], lambda = lambda1, log = T) + dpois(obs.D[2], lambda = lambda2, log = T)
  return(ll)
}

# Model 1
prior.size <- 5000 # num.particles
tol <- 0.01
num.params.M1 <- 1
ns.results.M1 <- nestedSampling(llFun = llf, numberOfParameters = num.params.M1, prior.size, transformParams = transform, tolerance=tol, printQ=T)
ns.results.M1$logevidence
log(6.67e-6) # Analytical result
exp(ns.results.M1$logevidence)

# Model 2
prior.size <- 5000 # num.particles
tol <- 0.01
num.params.M2 <- 2
ns.results.M2 <- nestedSampling(llFun = llf2, numberOfParameters = num.params.M2, prior.size = prior.size, transformParams = transform2, tolerance=tol, printQ=T)
ns.results.M2$logevidence
log(1.25e-4) # Analytical result
exp(ns.results.M2$logevidence)

# Bayes Factor in favor of model 1
bayes.factor <- exp(ns.results.M1$logevidence - ns.results.M2$logevidence)
bayes.factor
#> bayes.factor
#[1] 0.0527538
# Division uncertainty!
# Improve storage allocation!