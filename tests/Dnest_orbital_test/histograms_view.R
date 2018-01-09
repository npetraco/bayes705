library(rgl)
source("/Users/npetraco/latex/class/chem302/R/orbitals/density.sampling.functions.R")

rt.dir <- "/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/tests/Dnest_orbital_test/"

# Saved samples at which likelihood evaluations occured??
d1 <- read.table(paste0(rt.dir,"sample.txt"), header = F )
dim(d1)
num.samps <- nrow(d1)
head(d1)
hist(d1[,1])
hist(d1[,2])
hist(d1[,3])
#plot(d1[,1], d1[,2])
#plot(d1[,1], d1[,3])
#plot(d1[,2], d1[,3])
dim(d1)
orb<-t(sapply(1:num.samps,function(x){spherical.to.cartesian(d1[x,1],d1[x,2],d1[x,3])}))
plot(orb[,1], orb[,2])
plot(orb[,1], orb[,3])
plot(orb[,2], orb[,3])
# plot3d(orb[,1], orb[,2], orb[,3], typ="p",
#        xlim=c(min(orb[,1]),max(orb[,1])),
#        ylim=c(min(orb[,2]),max(orb[,2])),
#        zlim=c(min(orb[,2]),max(orb[,2]))
# )


# Posterior sample
d3 <- read.table(paste0(rt.dir,"posterior_sample.txt"), header = F )
head(d3)
dim(d3)
hist(d3[,1])
hist(d3[,2])
hist(d3[,3])
#plot(d3[,1], d3[,2])
#plot(d3[,1], d3[,3])
#plot(d3[,2], d3[,3])
orb<-t(sapply(1:num.samps,function(x){spherical.to.cartesian(d3[x,1],d3[x,2],d3[x,3])}))
plot(orb[,1], orb[,2])
plot(orb[,1], orb[,3])
plot(orb[,2], orb[,3])
plot3d(orb[,1], orb[,2], orb[,3], typ="p",
       xlim=c(min(orb[,1]),max(orb[,1])),
       ylim=c(min(orb[,2]),max(orb[,2])),
       zlim=c(min(orb[,2]),max(orb[,2]))
)


# Likelihood values samplesd and saved??
d4 <- read.table(paste0(rt.dir,"sample_info.txt"), header = F )
colnames(d4) <- c("level assignment", "log likelihood", "tiebreaker", "ID.")
head(d4)

# Show compression:
max.levl <- max(d4[,1])
max.levl
orblk<-t(sapply(1:num.samps,function(x){spherical.to.cartesian(d1[x,1],d1[x,2],d1[x,3])}))
for(i in 1:max.levl){
  levl <- i
  levl.idxs <- which(d4[,1]==levl)
  print(paste("Level:", i, length(levl.idxs)))
  plot(orblk[levl.idxs,1], orblk[levl.idxs,2])
  Sys.sleep(0.5)
}


for(i in 1:max.levl){
  levl <- i
  levl.idxs <- which(d4[,1]==levl)
  print(paste("Level:", i, length(levl.idxs)))
  plot3d(d1[levl.idxs,1], d1[levl.idxs,2], exp(d4[levl.idxs,2]), typ="p",
         xlim=c(min(d1[,1]),max(d1[,1])),
         ylim=c(min(d1[,2]),max(d1[,2])),
         zlim=c(0,4.1)
        )
  Sys.sleep(0.5)
  clear3d()
}
exp(d4[levl.idxs,2])
exp(c(min(d4[,2]),max(d4[,2])))
c(min(d4[,2]),max(d4[,2]))
# c(min(d4[,2]),max(d4[,2]))
# exp(c(min(d4[,2]),max(d4[,2])))

plot3d(d1[,1], d1[,2], exp(d4[,2]), typ="p",
       xlim=c(min(d1[,1]),max(d1[,1])),
       ylim=c(min(d1[,2]),max(d1[,2])),
       zlim=exp(c(min(d4[,2]),max(d4[,2])))
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
