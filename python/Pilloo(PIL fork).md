# 打开图片
```python

im = Image.open('test.png')
```

# 图片信息
```python
print(im.format, im.size, im.mode)
```

# 显示图片
```python
im.show()
```
调用系统图片显示软件打开图片

# 图片的矩形选择复制
```python
box = (100, 100, 400, 400)
region = im.crop(box)
region.show()
```
注意矩形的坐标要在图片范围内。左上角坐标为(0, 0)

# 旋转图片
```python
def roll(image, delta):
    """Roll an image sideways."""
    xsize, ysize = image.size

    delta = delta % xsize
    if delta == 0: return image

    part1 = image.crop((0, 0, delta, ysize))
    part2 = image.crop((delta, 0, xsize, ysize))
    part1.load()
    part2.load()
    image.paste(part2, (0, 0, xsize-delta, ysize))
    image.paste(part1, (xsize-delta, 0, xsize, ysize))

    return image
```

# 分开，合并