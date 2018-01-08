post <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_bi-modal_lik_test/posterior_sample.txt", header = F )
head(post)
hist(post[,1])
dim(post)
