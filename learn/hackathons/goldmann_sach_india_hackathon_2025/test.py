from PIL import Image, ImageOps
filename = input()
im = Image.open(filename)
im = ImageOps.grayscale(im)
im = im.point(lambda p: 255 if (p > 128) else 0)
im.show()

