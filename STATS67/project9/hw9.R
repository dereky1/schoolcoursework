library("ggplot2")
ISLANDERS <- read.csv("Islander_Data_HW9.csv")

#1.3
exer<-ISLANDERS$ModeratePhysicalActivity
intel<-ISLANDERS$Intelligence

ggplot(ISLANDERS) + geom_point(aes(x=exer,y=intel)) + geom_smooth(aes(x=exer,y=intel, method="lm")) + labs(title="Moderate Physical Activity vs. Intelligence") + xlab("Intelligence of Islanders")+ ylab("Moderate Physical Activity")

summary(lm(exer~intel))


#2.3
music<-ISLANDERS$Music
hair<-ISLANDERS$HairColor

ggplot(ISLANDERS) + geom_bar(aes(x=music, fill=hair)) + labs(title="Music Preference vs. Hair Color") + xlab("Music Preference") + ylab("Hair Color")
plot(music, hair, main="Music Preference vs. Hair Color", xlab="Music Preference", ylab="Hair Color")
summary(music)
summary(hair)
chisq.test(table(music, hair))

#3.3
sex<-ISLANDERS$Gender

plot(music,sex, main="Music Preference vs. Gender", xlab="Music Preference", ylab="Gender")
chisq.test(table(music, sex))
table(music,sex)