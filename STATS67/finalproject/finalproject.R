ISLAND <- read.csv("ISLANDERz.csv")

mmean<- mean(ISLAND$Mtotal, na.rm=T)
mmean

mstd<- sd(ISLAND$Mtotal, na.rm=T)
mstd

mtot<-na.omit(ISLAND$Mtotal)
mtot

stot<-na.omit(ISLAND$Stotal)
stot

smean<-mean(ISLAND$Stotal, na.rm=T)
smean

sstd<-sd(ISLAND$Stotal, na.rm=T)
sstd

plot(mtot, stot, main="Masturbation vs Sitting = +IQ or -IQ", xlab="Activity Before IQ Test", ylab="IQ Score", names=c("Masturbation", "Sitting"))

summary(ISLAND)

tstat <- (mmean-smean)/sqrt((mstd^2/30)+(sstd^2/30))
tstat

pci<-(smean-mmean) + 1.67*(sqrt((mstd^2/30)+(sstd^2/30)))
nci<-(smean-mmean) - 1.67*(sqrt((mstd^2/30)+(sstd^2/30)))

nci
pci

pt(tstat, 29)
qt(.05, 29)

qqnorm(mtot)
qqline(mtot)
qqnorm(stot)
qqline(stot)