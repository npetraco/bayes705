library(reticulate)
use_python("/usr/local/bin/python3")
py_config()
os <- import("os")
dn4 <- import("dnest4.classic")

os$getcwd()
cinfo <- dn4$postprocess()
dim(cinfo[[3]])
plot(cinfo[[3]],typ="l") # What is this?

# posterior sample
dat <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/posterior_sample.txt", header = F)
head(dat)
colnames(dat)=c("alpha", "beta")
hist(dat[,1])
hist(dat[,2])

# constrained prior sample??
dat2 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/sample.txt", header = F)
head(dat2)
colnames(dat2)=c("alpha", "beta")
hist(dat2[,1])
hist(dat2[,2])

# logX and logLik
dat3 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/levels.txt", header = F )
colnames(dat3) <- c("log_X", "log_likelihood", "tiebreaker", "accepts", "tries", "exceeds", "visits")
head(dat3)
dim(dat3)
plot(dat3[-1,1],dat3[-1,2], xlab="logX",ylab="logL")
plot(exp(dat3[-1,1]),dat3[-1,2], xlab="X",ylab="logL")
plot(dat3[-1,1],exp(dat3[-1,2]), xlab="logX",ylab="L")
plot(c(1, exp(dat3[-1,1])), c(0,exp(dat3[-1,2])), xlab="X",ylab="L", typ="l")

# ??
dat4 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/sample_info.txt", header = F )
colnames(dat4) <- c("level assignment", "log likelihood", "tiebreaker", "ID")
head(dat4)
dim(dat4)

max(dat4[,1])

lev <- 24
hist(dat4[which(dat4[,1]==lev), 2])
#hist(exp(dat4[which(dat4[,1]==lev), 2]))

# Weights??
dat5 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/weights.txt", header = F )
head(dat5)
head(cbind(dat4[,c(1,2)], dat5))

lev <- 22
lev.idxs <- which(dat4[,1]==lev)
plot(dat4[lev.idxs,2], dat5[lev.idxs,1], main=paste("Level=",lev), ylab="Wt.", xlab="logL")

