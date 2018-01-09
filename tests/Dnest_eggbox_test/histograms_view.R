library(rgl)

rt.dir <- "/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_eggbox_test/"

# Saved samples at which likelihood evaluations occured??
d1 <- read.table(paste0(rt.dir,"sample.txt"), header = F )
head(d1)
hist(d1[,1])
hist(d1[,2])
plot(d1[,1], d1[,2])
dim(d1)

# Posterior sample
d3 <- read.table(paste0(rt.dir,"posterior_sample.txt"), header = F )
head(d3)
hist(d3[,1])
hist(d3[,2])
plot(d3[,1], d3[,2])


# Likelihood values samplesd and saved??
d4 <- read.table(paste0(rt.dir,"sample_info.txt"), header = F )
colnames(d4) <- c("level assignment", "log likelihood", "tiebreaker", "ID.")
head(d4)

# Show compression:
max.levl <- max(d4[,1])
max.levl
for(i in 1:max.levl){
  levl <- i
  levl.idxs <- which(d4[,1]==levl)
  print(paste("Level:", i, length(levl.idxs)))
  plot(d1[levl.idxs,1], d1[levl.idxs,2])
  Sys.sleep(0.5)
}

exp(c(min(d4[,2]),max(d4[,2])))
c(min(d4[,2]),max(d4[,2]))
for(i in 1:max.levl){
  levl <- i
  levl.idxs <- which(d4[,1]==levl)
  print(paste("Level:", i, length(levl.idxs)))
  plot3d(d1[levl.idxs,1], d1[levl.idxs,2], d4[levl.idxs,2], typ="p",
         xlim=c(min(d1[,1]),max(d1[,1])),
         ylim=c(min(d1[,2]),max(d1[,2])),
         zlim=c(0,245)
        )
  Sys.sleep(0.5)
  clear3d()
}
exp(d4[levl.idxs,2])
exp(c(min(d4[,2]),max(d4[,2])))
# c(min(d4[,2]),max(d4[,2]))
# exp(c(min(d4[,2]),max(d4[,2])))

plot3d(d1[,1], d1[,2], d4[,2], typ="p",
       xlim=c(min(d1[,1]),max(d1[,1])),
       ylim=c(min(d1[,2]),max(d1[,2])),
       zlim=c(0,245)
)


# Are the "tiebreakers" just uniform rv's assigned to samples with the same likelihood??
levl <- 24
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
