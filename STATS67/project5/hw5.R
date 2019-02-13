?qgamma
#1c
qgamma(.975,shape=5,rate=1)
qgamma(.025,shape=5,rate=1)

#2e
plot(seq(0, 100, .1),dgamma(seq(0, 100, .1), shape=17, rate=1.25 ), type="l", main="Hw 5: 1e", xlab="Number of Jobs", ylab="Gamma Distribution")
lines(seq(0, 100, .1),dgamma(seq(0, 100, .1), shape=19, rate=1.22 ))


#3a
?pbeta
plot(seq(0, 1, .001),dbeta(seq(0, 1, .001), shape1= 2, shape2=5 ), type="l", main="Beta(2,5)", xlab="x", ylab="density")

#3e
qbeta(.1,shape1 = 2,shape2 = 5)
qbeta(.9,shape1=2,shape2=5, lower.tail = T)