library(bayes705)

# Di     ~ Exp(lambda)       # likelihood
# lambda ~ Uniform(1e-3, 1)  # lambda prior

# Data sets:
DA <- c(52, 49, 59, 29, 39, 11, 41)
DB <- c(32, 20, 7, 12, 30, 17, 10, 32, 29, 39, 11, 41)
DC <- c(3, 29, 20, 7, 12, 30, 17, 10, 32, 29, 39, 11, 9, 32)
DD <- DA

# Prior specifications:
transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = UniformPrior(params[1], 1e-3, 1)  # prior on lambda
  return(tParams)
}

# Log-likelihood
llf <- function(params) {
  tParams = transform(params)
  lambda = tParams[1]
  n <- length(DD)
  #ll <- n*kappa*log(lambda) - n*log(gamma(kappa)) + (kappa-1)*sum(log(DD)) - lambda*sum(DD)
  ll <- n*log(lambda) - lambda*sum(DD)
  return(ll)
}

prior.size <- 50
tol <- 0.005
log(tol)

ns.results <- nestedSampling(llf, numberOfParameters = 1, prior.size, transform, tolerance=tol, printQ=T)
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
c(exp(ns.results$logevidence - 3*ns.results$logZerror), exp(ns.results$logevidence + 3*ns.results$logZerror))

# Z:    1.37747e-16
# logZ: -36.52111

# Analytical (Mathematica)
# Z:    1.33537*10^-16
# logZ: -36.5522
tc <- 1
c(ns.results$logevidence - tc*ns.results$logZerror, ns.results$logevidence + tc*ns.results$logZerror)

