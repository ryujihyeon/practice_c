from distutils.core import setup, Extension

setup(name = "_ex02",
        version = "1.0",
        description = "ex02",
        author = "gbox3d",
        author_email = "gbox3d@gmail.com",
        url = "https://gbox3d.blogspot.com/",
        ext_modules = [Extension("_ex02", ["ex02.c"])]
        )