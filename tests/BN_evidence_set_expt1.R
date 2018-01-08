library(abind)
library(gRbase)
library(bayes705)

jen213 <- loadHuginNet("/Users/npetraco/latex/class/fos705/Applied_Bayes/R/6_graphical_models_in_brief/Jensen_2.13.net")

A <- jen213$cptlist$A
B <- jen213$cptlist$B
C <- jen213$cptlist$C

plot(jen213)
gRain2PrettyCPT(A, prior.nodeQ = T)
gRain2PrettyCPT(B, prior.nodeQ = F)
gRain2PrettyCPT(C, prior.nodeQ = F)


varNames(C)
nLevels(C)
valueLabels(C)

node <- "A"
ev.lev <- "a2"
node.idx <- which(varNames(C)==node)
ev.lev.idx <- which(valueLabels(C)[[node.idx]] == ev.lev)

asub(C, idx = ev.lev.idx, dims = node.idx) # Slice out the evidence level

asub(C, idx =  ev.lev.idx, drop=T, dims = node.idx) # Slice out all but the evidence level

