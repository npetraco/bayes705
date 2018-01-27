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
tol <- 0.01

ns.results <- nestedSampling(llf, numberOfParameters = 2, prior.size, transform, tolerance=tol, printQ=T)

logL       <- ns.results$logLstars                                         # logL* WITHOUT the last live set
num.iters  <- length(logL)                                                 # number of ns iterations used to reach tol
logdX      <- ns.results$log.widths                                        # log prior mass increments
X          <- exp(-(0:num.iters)/prior.size)                               # approx prior masses covered by above above logL*
logWt      <- ns.results$log.weight                                        # logWt = log(L dX) BUT extended with weights for last live set
logdX.last <- -num.iters/prior.size - log(prior.size)                      # log Remaining prior vol with respect to last live set
logL.last  <- ns.results$posterior[(num.iters+1):(num.iters+prior.size),2] # log Likelihoods of the last live set
logWt.last <- logdX.last + logL.last                                       # log Wts for last live set
logWt[(num.iters+1):(num.iters+prior.size)]                                # Same as above?? Should be.
logWt[(num.iters+1):(num.iters+prior.size)] ==  logWt.last                 # All true?? Should be.

# Plots:
logLstars <- c(-Inf, logL, logL.last)                              # ALL logL* inclucing those from the live set
Xstars    <- c(X, X[num.iters] - (1:prior.size) * exp(logdX.last)) # Corresponding X (I think....)
Z         <- exp(ns.results$logevidence)                           # marginal likelihood

# These should be the same:
length(logLstars)
length(Xstars)

# These should be the same:
sum(exp(logWt))
Z

plot(Xstars, logLstars, xlab="X", ylab="logL*")
plot(Xstars, exp(logLstars), xlab="X", ylab="L*", typ="p")
plot(log(Xstars), exp(logLstars), xlab="logX", ylab="L*", typ="p")
plot(log(Xstars), logLstars, xlab="logX", ylab="logL*")
plot(cumsum(exp(logWt)))
abline(Z,0)


