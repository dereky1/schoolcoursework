ANES2016 <- read.csv("ANES2016.csv")
#part 1 summary of numerical
ANES2016[which(ANES2016$ftpolice == 998),15] <- NA
summary(ANES2016$ftpolice)
#part 2 graphic of numerical
hist1 <- hist(ANES2016$ftpolice, main="How Would you rate the Police?", xlab = "Ratings (0 Meaning Bad to 100 Meaning Good)", ylab = "Number of Ratings")
#part 3 graphic of numerical turned categorical
data1 <- cut(ANES2016$ftpolice, breaks= seq(0,100,20), labels = c("Highly Negative", "Negative","Neutral","Positive", "Highly Positive"))
summary(data1)
table(data1)
barplot(table(data1), main="How Would you rate the Police?", xlab="Ratings", ylab="Number of Ratings")
#part4
warm1 <- cut(ANES2016$warmbad, breaks=seq(0,3,1), labels = c("Good","Bad","Neither"))
warm2 <- cut(ANES2016$warmcause, breaks=seq(0,3,1), labels= c("Human Activity", "Natural Causes", "Equally Both"))
plot(warm2, warm1, xlab="What is Causing Global Warming?", ylab="Opinions on Future Global Warming" , main="The Warming of the Earth")
par(mar=c(5,4,5,0.5))
#part5
ANES2016[which(ANES2016$fttrump == 998),11]<- NA
summary(ANES2016$fttrump)
ANES2016[which(ANES2016$ftmuslim == 998),18] <- NA
summary(ANES2016$ftmuslim)
plot(ANES2016$fttrump, ANES2016$ftmuslim, xlab="Ratings on Donald Trump", ylab="Ratings on Muslims", main="How people Rate Muslims Vs. Donald Trump")
#part6
ANES2016[which(ANES2016$fthisp == 998), 9] <- NA
summary(ANES2016$fthisp)
wage <- cut(ANES2016$minwage, breaks=seq(0,4,1), labels = c("Raise", "Kept It the Same", "Lowered", "Eliminated"))
plot(wage, ANES2016$fthisp, ylab="Ratings on Hispanics" ,xlab="What Should Happen to Minimum Wage?", main="How People Rate Hispanics\nVs.\nViews on Minimum Wage")
#part7
#ANES2016[which(ANES2016$lazyb == 998), 23] <- 0
#ANES2016[which(ANES2016$lazyw == 998), 24] <- 0
#ANES2016[which(ANES2016$lazyh == 998), 25] <- 0
lazy1<-cut(ANES2016$lazyb, breaks=seq(0,5,1), labels = c("Extremely", "Very", "Moderately", "Slightly","Not at All" ))
lazy2<-cut(ANES2016$lazyw, breaks=seq(0,5,1), labels = c("Extremely", "Very", "Moderately", "Slightly","Not at All" ))
lazy3<-cut(ANES2016$lazyh, breaks=seq(0,5,1), labels = c("Extremely", "Very", "Moderately", "Slightly","Not at All" ))
par(mfrow = c(1, 3)) 
barplot(table(lazy1), ylab="Number of Ratings", beside = TRUE,col = "Black", main = "\nBlacks")
barplot(table(lazy2), beside = TRUE,col = "white", main = "\nWhites")
barplot(table(lazy3), beside = TRUE,col = "Brown", main = "\nHispanics")
mtext("How well does the term 'Lazy' describe most people in these groups?", side = 3, line = -46, outer = TRUE)
mtext("Laziness by Between Blacks, Whites and Hispanic", side = 3, line=-2, outer=TRUE)