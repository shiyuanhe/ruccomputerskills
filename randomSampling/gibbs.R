
mu = c(10,10)
(Sigma = matrix(c(10,8,8,13), 2,2))

samples = normalGibbs(mu, Sigma, 2000, 2000)


samples = t(samples)
samples = data.frame(samples)
colnames(samples) = c("x", "y")

library(ggplot2)
library(ellipse)
library(plyr)  ## not necessary, but convenient
alpha_levels <- seq(0.5,0.95,by=0.2) ## or whatever you want
names(alpha_levels) <- alpha_levels ## to get id column in result
Sigma = matrix(c(1,8/sqrt(130),8/sqrt(130),1), 2,2)
contour_data <- ldply(alpha_levels,ellipse,x=Sigma,
                      scale=sqrt(c(10,13)),  ## needed for positional matching
                      centre=mu)


ggplot(samples, aes(x,y))+ stat_density_2d(aes(fill = ..density..), geom = "raster", contour = FALSE) +
    scale_fill_distiller(palette=4, direction=-1) +
    scale_x_continuous(expand = c(0, 0)) +
    scale_y_continuous(expand = c(0, 0)) +
    theme(legend.position='none') + geom_path(aes(x,y,group=.id), data = contour_data)

