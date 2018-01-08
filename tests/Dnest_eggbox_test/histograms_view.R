library(rgl)

d1 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_eggbox_test/sample.txt", header = F )
head(d1)
hist(d1[,1])
hist(d1[,2])
plot(d1[,1], d1[,2])

d2 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_eggbox_test/sample_info.txt", header = F )
head(d2)
hist(d2[,2])
hist(d2[,3])
plot(d2[,2], d2[,3])


d3 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_eggbox_test/posterior_sample.txt", header = F )
head(d3)
hist(d3[,1])
hist(d3[,2])
plot(d3[,1], d3[,2])

d4 <- read.table("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_eggbox_test/sample_info.txt", header = F )
head(d4)

# Show compression:
max.levl <- max(d4[,1])
for(i in 1:max.levl){
  levl <- i
  levl.idxs <- which(d4[,1]==levl)
  print(paste("Level:", i, length(levl.idxs)))
  plot(d1[levl.idxs,1], d1[levl.idxs,2])
  Sys.sleep(0.5)
}

for(i in 1:max.levl){
  levl <- i
  levl.idxs <- which(d4[,1]==levl)
  print(paste("Level:", i, length(levl.idxs)))
  plot3d(d1[levl.idxs,1], d1[levl.idxs,2], d4[levl.idxs,2], typ="p", xlim=c(0,30),ylim=c(0,30),zlim=c(0,245))
  Sys.sleep(0.5)
  clear3d()
}


# Are the "tiebreakers" just uniform rv's assigned to samples with the same likelihood??
levl <- 0
levl.idxs <- which(d4[,1]==levl)
plot(1:length(levl.idxs), d4[levl.idxs,2])        # Huh??
hist(d4[levl.idxs,2])                             # Weird...
as.character(d4[levl.idxs,2])                     # Reveals that there is more precision
unique(as.numeric(as.character(d4[levl.idxs,2]))) # Nope, doesn't fix it...
unique(round(d4[levl.idxs,2],1))                  # This does though.

# Look at the numbers assigned as "tiebreakers"
plot(d4[levl.idxs,3])
cbind(as.character(d4[levl.idxs,2]), d4[levl.idxs,3])
order(d4[levl.idxs,3])
plot(sort(d4[levl.idxs,3])) # Looks like every likelihood is just assigned a uniform rv
                            # incase there is a tie. cf. level = 0 where there are few ties.
hist(d4[levl.idxs,3])
