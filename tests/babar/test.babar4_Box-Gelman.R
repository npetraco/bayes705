setwd("/Users/npetraco/Desktop/marg_lik/nested_sampling/nsr_expts/")
source("nested_babar_mod1.R")
source("params2priors_babar_mod1.R")


# Box-Gelman Z with babar's implenetation of ns. Our's in ns.try4 is not behaving nicely... ns.try1 however is working OK
xbar.obs <- 0.001
sx.obs   <- 1.01
n.obs    <- 20

transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = GaussianPrior(params[1], 0, 20)
  tParams[2] = HalfCauchyPrior(params[2], 5)
  return(tParams)
}

llf <- function(params) {
  tParams = transform(params)
  mean = tParams[1]
  sigma = tParams[2]
  ll <- (-((-1 + n.obs)*sx.obs^2) - n.obs*(mean - xbar.obs)^2)/(2*sigma^2) - n.obs*log(sigma)
  return(ll)
}

prior.size <- 25
tol <- 0.3

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


# Our first implemention:
# [1] "Accum logZ*: -17.3232434061131"
# [1] "Last dlogZ : -39.6860736732817"
# [1] "logZ       : -17.323243405919"
ns.results$logevidence

# Mathematica semi-analytical result:
# logZ = -17.131
ns.results$logevidence
# Z = 3.63166*10^-8
exp(ns.results$logevidence)

plot(ns.results$posterior[,3], ns.results$posterior[,4])
hist(ns.results$posterior[,3])  
hist(ns.results$posterior[,4])  

ns.results$logZerror

