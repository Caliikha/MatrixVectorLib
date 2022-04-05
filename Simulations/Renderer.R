setwd("C:/Users/omaro/Documents/AUS/Programming_Tasks/LINUX_TESTING/GHMVLC/MVL/Simulations")
df <- read.csv(file.choose())
df
library(gganimate)
library(animation)
library(scatterplot3d)
library(ggplot2)
library(gg3D)
library(tidyverse)
library(transformr)
library(plotly)

my_data <- as_tibble(df)
my_data

graph<-function(i){ # makes a step time-based graph of the positions of the orbital objects
  
  qplot(x=0, y=0, z=0, geom="blank") + theme_void() +   axes_3D()
  ggplot(subset(my_data %>% slice(1:i)), aes(x=x, y=y, z=z)) + theme_void() + axes_3D() + stat_3D()
}
# time-based graph in a time-step
graph(303)
graph(2000)

# uses ggplot graphing to graph the time-based position of objects based on their position away from the origin
ggplot(subset(my_data %>% slice(1:2000)), aes(x=x, y=y, z=z, color = count), xlim=c(-2,2), ylim=c(-2,2), zlim=c(-2,2)) + theme_void() + axes_3D() + stat_3D()


# generates a graph that shows the distance from the origin object
origin_distance_path <- ggplot(df, aes(x = x, y = y, z = z)) +
  theme_void() +
  axes_3D(theta = -135, phi = 14) +
  stat_3D(geom = "path", theta = -135, phi = 14) +
  scale_color_viridis_c() +
  labs_3D(labs = c("x", "y", "z"), hjust = c(-15, 18, -21), vjust = c(0, 16, 7)) +
  coord_equal()

origin_distance_path


orbital_animation <- ggplot(df, aes(x = x, y = y, z = z), xlim=c(-2,2),ylim=c(-2,2),zlim=c(-2,2)) +
  theme_void() +
  axes_3D() +
  stat_3D() +
  labs_3D() +
  coord_equal() + geom_point() +
  transition_time(count)

animate(orbital_animation, nframes = 100, fps = 25)
anim_save("Simulation.gif")

# saves individual frames into an image file for analysis or animation
for (i in 10:20) {
  ggsave(graph(i), filename=paste("t", i, ".jpg"), width = 20, height = 20, units = "cm")
}

# generates a point time-based simulation animation with static range definition
saveHTML({
  for (i in 2:nrow(df)) {
    with(df[c(i,i+1),],scatterplot3d(x,y,z,type="p", xlim=range(df$x),ylim=range(df$y),zlim=range(df$z)))
  }
})

# generates a point time-based simulation animation with dynamic range definition
saveHTML({
  for (i in 2:nrow(df)) {
    with(df[c(i,i+1),],scatterplot3d(x,y,z,type="p", xlim=c(-2-max(x),2+max(x)),ylim=c(-2-max(y),2+max(y)),zlim=c(-2-max(z),2+max(z))))
  }
})

# same as previous generation however, uses origin-line rendering
saveHTML({
  for (i in 2:nrow(df)) {
    with(df[i-1:i,],scatterplot3d(x,y,z,type="l", xlim=range(df$x),ylim=range(df$y),zlim=range(df$z)))
  }
})

saveHTML({
  for (i in 2:nrow(df)) {
    with(df[c(i,i+1),],scatterplot3d(x,y,z,type="l", xlim=c(-2-max(x),2+max(x)),ylim=c(-2-max(y),2+max(y)),zlim=c(-2-max(z),2+max(z))))
  }
})

# same as previous generation however, uses x-y-plane line rendering
saveHTML({
  for (i in 2:nrow(df)) {
    with(df[i-1:i,],scatterplot3d(x,y,z,type="h", xlim=c(-2, 2),ylim=c(-2, 2),zlim=c(-2, 2)))
  }
})

saveHTML({
  for (i in 2:nrow(df)) {
    with(df[c(i,i+1),],scatterplot3d(x,y,z,type="h", xlim=c(-2-max(x),2+max(x)),ylim=c(-2-max(y),2+max(y)),zlim=c(-2-max(z),2+max(z))))
  }
})

# interactive dynamic render of the time-based simulation
library(rgl)
with(df,lines3d(x,y,z))
with(df[1,],points3d(x,y,z,size=7,col="red"))
with(df[-1,],points3d(x,y,z,col="blue"))
axes3d()
title3d(xlab="X",ylab="Y",zlab="Z")

library(rayshader)
distribution_1 = data.frame(x=rnorm(20000, 10, 1.9), y=rnorm(20000, 10, 1.2) )
distribution_2 = data.frame(x=rnorm(20000, 14.5, 1.9), y=rnorm(20000, 14.5, 1.9) )
distribution_3 = data.frame(x=rnorm(20000, 9.5, 1.9), y=rnorm(20000, 15.5, 1.9) )
data = rbind(distribution_1,distribution_2,distribution_3)

#Lines
Heat_Map_Plot = ggplot(data, aes(x=x, y=y)) +
  geom_hex(bins = 20, size = 0.5, color = "black") +
  scale_fill_viridis_c(option = "C")
Heat_Map_Plot