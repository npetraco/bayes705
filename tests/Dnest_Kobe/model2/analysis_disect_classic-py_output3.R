library(bayes705)

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

