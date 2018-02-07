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




# logl_levels = [(levels_orig[i,1], levels_orig[i, 2]) for i in range(0, levels_orig.shape[0])] # logl, tiebreaker
logL.levels <- level.info[,c(2,3)]
# logl_samples = [(sample_info[i, 1], sample_info[i, 2], i) for i in range(0, sample_info.shape[0])] # logl, tiebreaker, id
logL.samples <- sample.info[,c(2,3)]
head(logL.samples)

# Find sandwiching level for each sample
# sandwich = sample_info[:,0].copy().astype('int')
sandwch <- sample.info[,1]
sandwch
# for i in range(0, sample_info.shape[0]):
#   while sandwich[i] < levels_orig.shape[0]-1 and logl_samples[i] > logl_levels[sandwich[i] + 1]:
#   sandwich[i] += 1
for(i in 1:nrow(sample.info)) {
  while((sandwch[i] < nrow(level.info) - 1) & (logL.samples[i,1] > (logL.levels[sandwch[i] + 2,1])) ) {
    sandwch[i] <- sandwch[i] + 1
  }
}
sandwch == sample.info[,1]



all.levels <- 0:(nrow(level.info)-1)
lev <- 70
lev.idxs <- which(sample.info[,1]==lev)
#head(level.info[,2])
#cbind(all.levels, level.info[,2])

cbind(sandwch[lev.idxs], sample.info[lev.idxs,c(1,2)], level.info[1 + sandwch[lev.idxs], 2])
#
plot(sample.info[lev.idxs, 2], level.info[1 + sandwch[lev.idxs], 2])
plot(sample.info[-lev.idxs, 2], level.info[1 + sandwch[-lev.idxs], 2])

#
# Should just be 1 + sandwch[lev.idxs]
#cbind(1 + sandwch[lev.idxs], sapply(1:length(lev.idxs), function(xx){which(all.levels==sandwch[lev.idxs][xx])}))

lev.idxs2 <- which(sandwch==lev)
#N = len(logl_samples_thisLevel)
lev.leng <- length(lev.idxs2)
lev.leng
plot(sample.info[lev.idxs2, 2], level.info[1 + sandwch[lev.idxs2], 2])
cbind(sandwch[lev.idxs2], 
      sample.info[lev.idxs2, c(1,2)], 
      level.info[1 + sandwch[lev.idxs2], 2])
sample.info[lev.idxs2, 2] > level.info[1 + sandwch[lev.idxs2], 2]


#logx_max = levels[i, 0]
logx.max <- level.info[lev+1,1]
logx.max

# PROBLEM BELOW 
#logx_min = levels[i+1, 0]
logx.min <- level.info[lev+2,1]
logx.min
logx.min <- -1e300 # FOR TOP LEVEL log(0)

#Umin = np.exp(logx_min - logx_max)
Umin <- exp(logx.min - logx.max)
Umin
#Umin + (1. - Umin)*np.random.rand(len(which))
U <- Umin  + (1-Umin) * runif(lev.leng,0,1)

#U = Umin + (1. - Umin)*np.linspace(1./(N+1), 1. - 1./(N+1), N)
U2 <- Umin  + (1-Umin) * seq(from=(1/(lev.leng+1)), to=(1 - 1/(lev.leng+1)), length.out = lev.leng)

#logx_samples_thisLevel = np.sort(logx_max + np.log(U))[::-1]
logx.samples.thisLevel <- sort(logx.max + log(U), decreasing = T)

logx.samples.thisLevel2 <- sort(logx.max + log(U2), decreasing = T)

cbind(logx.samples.thisLevel,logx.samples.thisLevel2)

c(logx.max, max(logx.samples.thisLevel), max(logx.samples.thisLevel2))
logx.max > max(logx.samples.thisLevel)
logx.max > max(logx.samples.thisLevel2)

c(logx.min, min(logx.samples.thisLevel), min(logx.samples.thisLevel2))
logx.min < min(logx.samples.thisLevel)
logx.min < min(logx.samples.thisLevel2)

# logLs for level:
logLs.lev <- sort(sample.info[lev.idxs2, 2])
level.info[lev+1,2] < logLs.lev[1]                  #
logLs.lev[length(lev.idxs2)] < level.info[lev+2,2]  # nothing above for TOP level

level.info[lev+1,]
logLs.lev <- c(level.info[lev+1,2],logLs.lev,level.info[lev+2,2])
logLs.lev <- c(level.info[lev+1,2],logLs.lev) # For the TOP level, no right cap
logLs.lev

# logXs for level
level.info[lev+1,1] > logx.samples.thisLevel[1]
logx.samples.thisLevel[length(lev.idxs2)] > level.info[lev+2,1] # nothing below for TOP level

logx.samples.thisLevel <- c(level.info[lev+1,1],  logx.samples.thisLevel, level.info[lev+2,1])
logx.samples.thisLevel2 <- c(level.info[lev+1,1],  logx.samples.thisLevel2, level.info[lev+2,1])
logx.samples.thisLevel <- c(level.info[lev+1,1],  logx.samples.thisLevel)   # for TOP level
logx.samples.thisLevel2 <- c(level.info[lev+1,1],  logx.samples.thisLevel2) # for TOP level


cbind(logx.samples.thisLevel2,logLs.lev)
plot(logx.samples.thisLevel,logLs.lev)
plot(logx.samples.thisLevel2,logLs.lev)
