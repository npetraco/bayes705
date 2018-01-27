setwd("/Users/npetraco/Desktop/marg_lik/nested_sampling/nsr_expts/")
source("nested_babar_mod1.R")
source("params2priors_babar_mod1.R")

pow.D <- 30

transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = UniformPrior(params[1], lowerBound = 0, upperBound = 1) # alpha
  tParams[2] = UniformPrior(params[2], lowerBound = 0, upperBound = 1) # beta
  return(tParams)
}

llf <- function(params) {
  tParams = transform(params)
  alpha <- tParams[1]
  beta  <- tParams[2]
  ll <- pow.D*(log(1 - alpha) + log(alpha) + log(1 - beta) + log(beta))
  return(ll)
}

prior.size <- 1000 # num.particles
tol <- 0.01
num.params <- 2
ns.results <- nestedSampling(llf, numberOfParameters = num.params, prior.size, transform, tolerance=tol, printQ=T)
ns.results$logevidence
log(1.9215e-38) # Analytical answer
exp(ns.results$logevidence)
1.9215e-38 # Analytical answer

ns.results$logZerror
ns.results$entropy


num.iters <- length(ns.results$logLstars)
Xi <- exp(-(0:num.iters)/prior.size)
lnXi <- log(Xi)

length(Xi)
num.iters
plot(Xi, c(-Inf,ns.results$logLstars), ylab="logL*")
plot(Xi, c(0,exp(ns.results$logLstars)), ylab="L*", typ="p")
plot(log(Xi), c(0,exp(ns.results$logLstars)), ylab="L*", typ="p")
plot(log(Xi), c(-Inf,ns.results$logLstars), ylab="logL*")
plot(cumsum(exp(ns.results$log.weight)))


plot(ns.results$posterior[,3], ns.results$posterior[,4])
hist(ns.results$posterior[,3])  
hist(ns.results$posterior[,4])  
