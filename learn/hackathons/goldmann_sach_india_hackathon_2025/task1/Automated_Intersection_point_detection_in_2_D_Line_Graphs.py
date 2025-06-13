from PIL import Image
filename = input()
image = Image.open(filename)
grey = image.convert("L")
bw = grey.point(lambda x: print(x), mode='1')
width, height = bw.size
for i in range(height):
    for j in range(width):
        print(bw.getpixel((i, j)), end=" ")
    print()

