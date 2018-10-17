# list of matrix kernels
smoothM = matrix(c(1,2,1,2,4,2,1,2,1)/16, 3,3)
sharpenM = matrix(c(0,-1,0,-1,5,-1,0,-1,0),3,3)
edgeM = matrix(c(-1,-1,-1,-1,8,-1,-1,-1,-1),3,3)

# read in image
library(jpeg)
img = readJPEG("./dog.jpg")
img = img[,,1]

# image convolution
img2 = imageConv(img, smoothM)  ## choose a matrix kernel


## plot two images
par(mar = c(0,0,0,0))
plot(0,0,type = "n")
rasterImage(img, -1, 0, 1, 1)
rasterImage(img2, -1, -1, 1, 0)


