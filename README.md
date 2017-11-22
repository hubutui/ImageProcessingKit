# ImageProcessingKit

Image Processing Kit - Power by Qt 5

## Introduction

This is just a personal homework for image processing. Many thanks to [ImageQt](https://github.com/cyrillu/ImageQt) for inspiration.

## Requirement

Qt 5.9 is required, and the Qt Image Formats add-on module provides optional support for other image file formats. One might install Qt Image Formats add-on module by install package qt5-imageformats. [CImg](http://cimg.eu) is used for image I/O too. Please be aware that to support more image format, [ImageMagick](https://www.imagemagick.org/script/index.php) is required by [CImg](http://cimg.eu).

## Compiling

Qt 5.9 is required, compiling under linux is tested, but not Windows. But, Qt is a cross-platform application framework, I don't think you will have any trouble compiling it in other system.

To compile ImageProcessingKit in Linux,

```shell
cd $src
qmake
make
```
