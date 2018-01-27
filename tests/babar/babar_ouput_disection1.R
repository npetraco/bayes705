library(bayes705)

# Prior:
transform <- function(params) {
  tParams = numeric(length=length(params))
  tParams[1] = -3 + BetaPrior(params[1], 5, 1)*6
  tParams[2] = -3 + BetaPrior(params[2], 5, 1)*6
  return(tParams)
}

# Log-likelihood:
llf <- function(params) {
  tParams = transform(params)
  x = tParams[1]
  y = tParams[2]
  ll <- -(x^2/2) - y^2/2 - log(2*pi)
  return(ll)
}

prior.size <- 25
tol <- 0.1

ns.results <- nestedSampling(llf, numberOfParameters = 2, prior.size, transform, tolerance=tol, printQ=T)
logL       <- ns.results$logLstars
num.iters  <- length(logL)
logdX      <- ns.results$log.widths
#cbind( exp(logdX), -diff(exp(-(0:num.iters/prior.size)) )
logWt      <- ns.results$log.weight
num.iters  <- length(logL)
X          <- exp(-(0:num.iters)/prior.size)

plot(X, c(0,exp(logL)), xlab="X", ylab="L")

sum(exp(logdX)*exp(logL))       # Z?? missing last chunk from live set
sum(exp(ns.results$log.weight)) # Z
exp(ns.results$logevidence)     # Z
# Analytical Z 0.00763291

# Find last chunck from live set
num.iters
length(exp(logWt))
length(exp(logWt)) - num.iters
prior.size

exp(logWt)
cbind(exp(logdX)*exp(logL), exp(logWt[1:131])) # Wts the same up to last iteration

# Remaining prior vol
exp(-num.iters/prior.size)
# Assume each remaining live likelihood takes up this much of the remaining prior volume
exp(-num.iters/prior.size)/prior.size
exp(ns.results$posterior[132:156,2]) # Likelihoods of the last live set?? Yup
log(exp(ns.results$posterior[132:156,2])*exp(-num.iters/prior.size)/prior.size) # Remaing logWts?
logWt[132:156]


hist(-3 + rbeta(1000, 5, 1) * 6, probability = T)

DD <- seq(-3,3,length.out = 100)
plot(DD, 1/6 * dbeta((DD+3)/6, 5, 1))
