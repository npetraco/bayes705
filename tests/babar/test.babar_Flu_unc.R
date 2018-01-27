library(babar)
library(doMC)


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


num.rep <- 1000
# logZs <- array(NA,num.rep)
# for(i in 1:num.rep) {
#   ns.results <- nestedSampling(llf, numberOfParameters = 1, prior.size, transform, tolerance=tol)
#   logZs[i] <- ns.results$logevidence
#   print(paste(i, "Log(Z)", ns.results$logevidence))
# }
# hist(logZs)

getDoParWorkers()
registerDoMC(8)
getDoParWorkers()

fv.mat<-NULL

t1<-Sys.time()
fv.mat <- foreach(i=1:num.rep, .combine="c") %dopar% {
  nestedSampling(llf, numberOfParameters = 1, prior.size, transform, tolerance=tol)$logevidence
}
t2<-Sys.time()
difftime(t2,t1)

hist(fv.mat)
mean(fv.mat)
median(fv.mat)
sd(fv.mat)

# > mean(fv.mat)
# [1] -36.58724
# > sd(fv.mat)
# [1] 0.2740446
