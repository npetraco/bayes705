library(doMC)
library(babar)
library(bayes705)

# Di     ~ Gamma(kappa, lambda)   # likelihood
# kappa  ~ Uniform(0, 25)         # kappa prior
# lambda ~ Uniform(1e-3, 1)       # lambda prior

# Data sets:
DA <- c(52, 49, 59, 29, 39, 11, 41)
DB <- c(32, 20, 7, 12, 30, 17, 10, 32, 29, 39, 11, 41)
DC <- c(3, 29, 20, 7, 12, 30, 17, 10, 32, 29, 39, 11, 9, 32)
DD <- DA

# Prior specifications:
transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = UniformPrior(params[1], 0, 25)    # prior on kappa
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

getDoParWorkers()
registerDoMC(8)
getDoParWorkers()

fv.mat<-NULL

num.rep <- 1000

t1<-Sys.time()
fv.mat <- foreach(i=1:num.rep, .combine="c") %dopar% {
  nestedSampling(llf, numberOfParameters = 2, prior.size, transform, tolerance=tol)$logevidence
}
t2<-Sys.time()
difftime(t2,t1)

hist(fv.mat)
mean(fv.mat)
median(fv.mat)
sd(fv.mat)

# > mean(fv.mat)
# [1] -34.01794
# > median(fv.mat)
# [1] -34.02146
# > sd(fv.mat)
# [1] 0.2481248
# >
