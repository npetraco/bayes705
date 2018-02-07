rt.dir <- "/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Kobe/model2/"

# Saved samples at which likelihood evaluations occured
d1 <- read.table(paste0(rt.dir,"sample.txt"), header = F )
head(d1)
hist(d1[,1])
hist(d1[,2])
plot(d1[,1], d1[,2])
dim(d1)

# Posterior sample
post <- read.table(paste0(rt.dir,"posterior_sample.txt"), header = F )
head(post)
hist(post[,1])
hist(post[,2])
plot(post[,1], post[,5])

# Likelihood values sampled and saved??
d4 <- read.table(paste0(rt.dir,"sample_info.txt"), header = F )
colnames(d4) <- c("level assignment", "log likelihood", "tiebreaker", "ID.")
head(d4)
dim(d4)

# Level info
level.info <- read.table(paste0(rt.dir,"levels.txt"), header = F )
colnames(level.info) <- c("log_X", "log_likelihood", "tiebreaker", "accepts", "tries", "exceeds", "visits")
plot(level.info[-1,1], level.info[-1,2])
level.info
cbind(0:max(d4[,1]), level.info[,1], exp(level.info[,1]),level.info[,2])
cbind(d4[,1], d4[,2])


wgts<- read.table(paste0(rt.dir,"weights.txt"), header = F )
dim(wgts)

# Generate intermediate logx values
# cf. ll. 96-124 classic.py in DNest4 python
all.levels <- 0:max(d4[,1])

lev <- 0
lev.idxs <- which(d4[,1]==lev)
#N = len(logl_samples_thisLevel)
lev.leng <- length(lev.idxs)

#logx_max = levels[i, 0]
logx.max <- level.info[lev+1,1]
#logx_min = levels[i+1, 0]
logx.min <- level.info[lev+2,1]
logx.min
#Umin = np.exp(logx_min - logx_max)
Umin <- exp(logx.min - logx.max)
Umin
#Umin + (1. - Umin)*np.random.rand(len(which))
U <- Umin  + (1-Umin) * runif(lev.leng,0,1)

#U = Umin + (1. - Umin)*np.linspace(1./(N+1), 1. - 1./(N+1), N)
U2 <- Umin  + (1-Umin) * seq(from=(1/(lev.leng+1)), to=(1 - 1/(lev.leng+1)), length.out = lev.leng)

#logx_samples_thisLevel = np.sort(logx_max + np.log(U))[::-1]
logx.samples.thisLevel <- sort(logx.max + log(U))

logx.samples.thisLevel2 <- sort(logx.max + log(U2))

cbind(logx.samples.thisLevel,logx.samples.thisLevel2)

c(logx.max, max(logx.samples.thisLevel), max(logx.samples.thisLevel2))
logx.max > max(logx.samples.thisLevel)
logx.max > max(logx.samples.thisLevel2)

c(logx.min, min(logx.samples.thisLevel), min(logx.samples.thisLevel2))
logx.min < min(logx.samples.thisLevel)
logx.min < min(logx.samples.thisLevel2)

level.info[lev+2,2]
sort(d4[lev.idxs, 2], decreasing = T)
level.info[lev+1,2]

d4[lev.idxs, 1]
