library(gRbase)
library(gRain)

net1 <- loadHuginNet("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/inst/nets/ArtistTrace.net")
dev.off()
plot(net1)

net1$cptlist$Transfer
gRain2PrettyCPT(net1$cptlist$Transfer, prior.nodeQ=F)

net1 <- loadHuginNet("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/bayes705/inst/nets/golf.net")
dom(net1$cptlist$Distance)
