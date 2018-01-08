library(reticulate)
use_python("/usr/local/bin/python3")
py_config()

levls      <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/levels.txt", header = F )
sampls     <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/sample.txt", header = F )
sampl.info <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/sample_info.txt", header = F )

colnames(levls)      <- c("log_X", "log_likelihood", "tiebreaker", "accepts", "tries", "exceeds", "visits")
colnames(sampls)     <- c("alpha", "beta")
colnames(sampl.info) <- c("level assignment", "log likelihood", "tiebreaker", "ID")

dim(levls)
dim(sampls)
dim(sampl.info)

logl_levels  <- levls[,c(2,3)]        # logl, tiebreaker
logl_samples <- sampl.info[,c(2,3,4)] # logl, tiebreaker, id

# Find sandwiching level for each sample
# sandwich = sample_info[:,0].copy().astype('int')
# for i in range(0, sample_info.shape[0]):
#   while sandwich[i] < levels_orig.shape[0]-1 and logl_samples[i] > logl_levels[sandwich[i] + 1]:
#   sandwich[i] += 1
sandwichh <- sampl.info[,1]
max.lev <- dim(levls)[1] - 1
for(i in 1:length(sandwichh)){
  while((sandwichh[i] < max.lev) & (logl_samples[i,1] > logl_levels[sandwichh[i]+1,1])){
    sandwichh[i] <- sandwichh[i] + 1
  }
}
plot(sampl.info[,1], sandwichh)

sfpy <- read.csv("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/csvfile2.csv",header = F)[,1]
head(sfpy)
#sum(sfpy - sampl.info[,1])
plot(sampl.info[,1], sfpy)

head(sandwichh-1)

sfpy - (sandwichh-1)

sandwichh[64]
logl_samples[64,1] > logl_levels[sandwichh[64]+1,1]

# Try to understand what Murry is doing in analysis.py
np <- import("numpy")
dn4 <- import("dnest4")
np$array(r_to_py(levls))
dn4$analysis$interpolate_samples(levels = r_to_py(levls),
                                 sample_info = r_to_py(sampl.info),
                                 resample = F)

os <- import("os")
os$getcwd()

backend <- dn4$backends$CSVBackend("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_Bullard_spike_test/")
backend$levels

head(levls)
head(sampl.info)
levls

py_run_file("tests/Dnest_Bullard_spike_test/analysis_expts1.py")
