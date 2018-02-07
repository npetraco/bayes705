rt.dir <- "/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Kobe/model2/"

# Saved samples at which likelihood evaluations occured
samp.txt <- read.table(paste0(rt.dir,"sample.txt"), header = F )
colnames(samp.txt) <- paste0("ppi",0:14)

# Posterior sample
post.samp <- read.table(paste0(rt.dir,"posterior_sample.txt"), header = F )
colnames(post.samp) <- paste0("ppi",0:14)

# Likelihood values sampled and saved??
sample.info <- read.table(paste0(rt.dir,"sample_info.txt"), header = F )
colnames(sample.info) <- c("level assignment", "log likelihood", "tiebreaker", "ID.")

# Level info
level.info <- read.table(paste0(rt.dir,"levels.txt"), header = F )
colnames(level.info) <- c("log_X", "log_likelihood", "tiebreaker", "accepts", "tries", "exceeds", "visits")

junk <- process.dnest.info(sample.info, level.info)

head(junk)
dim(junk)
sort(sample.info[1:5, 2])
order(sample.info[1:5, 2])

tpe <- 1 # logX type 1 = eqsp, 2 = rand
plot(level.info[-1,1], level.info[-1,2], xlab="logX level", ylab="logL level")
plot(junk[-1, tpe], junk[-1,3], xlab="logX ??", ylab="logL??")
plot(exp(junk[-1, tpe]), exp(junk[-1,3]), xlab="X ??", ylab="L??")
plot(junk[-1, tpe], exp(junk[-1,3]), xlab="logX ??", ylab="L??")
plot(exp(junk[-1, tpe]), junk[-1,3], xlab="X ??", ylab="logL??")
points(level.info[-1,1], level.info[-1,2], col="green", pch=16)

tpe <- 1 # logX type 1 = eqsp, 2 = rand
logX <- junk[,tpe]
logdX <- log(-diff(exp(logX)))
logL <- junk[,3]
plot(exp(logX))
min(logdX)
length(logdX)

logdX2 <- array(NaN, length(logX)-1)
for(i in 2:(length(logX))){
  logdX2[i-1] <- logdiffexp(logX[i-1], logX[i])
}
logdX2[1]
logdX2[length(logdX2)]
logdX[1]
logdX[length(logdX)]

# For trapazoid:
logdX.trap <- array(NaN, length(logX)-2)
for(i in 2:(length(logX)-1)){
  logdX.trap[i-1] <- log(0.5) + logdiffexp(logX[i-1], logX[i+1])
}
plot(logdX.trap)
plot(logdX)
plot(logdX2)

cbind(logdX[which((logdX==logdX2) == F)], logdX2[which((logdX==logdX2) == F)])
max(logdX-logdX2)
max(logdX2-logdX.trap)
logdX.trap[length(logdX.trap)]

plot(logX[-1],logL[-1])


logZ2 <- -1e300
for(i in 2:(length(logL))) {
  logZ2 <- logsumexp(logZ2, logL[i] + logdX2[i-1])
}
logZ2

logZ2 <- -1e300
for(i in 2:(length(logL))) {
  logZ2 <- logsumexp(logZ2, logL[i] + logdX2[i-1])
}
logZ2

logZ.trap <- -1e300
for(i in 2:(length(logL)-1)) {
  print(i)
  logZ.trap <- logsumexp(logZ.trap, logL[i] + logdX.trap[i-1])
}
logZ.trap
logZ2
length(logL)

logL[2]

logdX.trap[3]
logsumexp(logZ.trap, logL[2] + logdX.trap[2-1])
