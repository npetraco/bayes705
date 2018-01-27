library(bayes705)

# Di     ~ Gamma(kappa, lambda)   # likelihood
# kappa  ~ Exp(1/4)               # kappa prior
# lambda ~ Uniform(1e-3, 1)       # lambda prior

# Data sets:
DA <- c(52, 49, 59, 29, 39, 11, 41)
DB <- c(32, 20, 7, 12, 30, 17, 10, 32, 29, 39, 11, 41)
DC <- c(3, 29, 20, 7, 12, 30, 17, 10, 32, 29, 39, 11, 9, 32)
DD <- DB

# Prior specifications:
transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = ExponentialPrior(params[1], 0.25) # prior on kappa
  tParams[2] = UniformPrior(params[2], 1e-3, 1)  # prior on lambda
  return(tParams)
}

# Log-likelihood
llf <- function(params) {
  tParams = transform(params)
  kappa = tParams[1]
  lambda = tParams[2]
  n <- length(DD)
  #\kappa \log(\lambda) - \log(\Gamma(\kappa)) + \sum_{i=1}^n(\kappa-1)\log(D_i) - \lambda D_i
  ll <- n*kappa*log(lambda) - n*log(gamma(kappa)) + (kappa-1)*sum(log(DD)) - lambda*sum(DD)
  return(ll)
}

prior.size <- 50
tol <- 0.005
log(tol)

ns.results <- nestedSampling(llf, numberOfParameters = 2, prior.size, transform, tolerance=tol, printQ=T)
ns.results$logevidence
ns.results$logZerror
ns.results$entropy

num.iters <- length(ns.results$logLstars)
Xi <- exp(-(0:num.iters)/prior.size)
lnXi <- log(Xi)

length(Xi)
plot(Xi, c(-Inf,ns.results$logLstars), ylab="logL*")
plot(Xi, c(0,exp(ns.results$logLstars)), ylab="L*", typ="p")
plot(log(Xi), c(0,exp(ns.results$logLstars)), ylab="L*", typ="p")
plot(log(Xi), c(-Inf,ns.results$logLstars), ylab="logL*")
plot(cumsum(exp(ns.results$log.weight)))

# Z:
exp(ns.results$logevidence)
tc <- 3
c(exp(ns.results$logevidence - tc*ns.results$logZerror), exp(ns.results$logevidence + tc*ns.results$logZerror))

# Z:    1.328927e-15
# logZ: -34.2544

# Assuming 50/50 prior odds, this is the post prob for this model
BF/(1+BF)

# Semi-analytical:
#logZ : -34.0074

# Bayes factor between this model vs random model
BF <- exp(-34.0074 - -36.5522)
BF

pri.O <- 0.5/0.5
post.O <- BF*pri.O

# Posterior prob for model:
post.O/(post.O + 1)
