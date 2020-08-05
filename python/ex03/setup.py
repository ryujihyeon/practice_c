# setup.py
from distutils.core import setup, Extension

setup(name = "_ex03",
        version = "1.0",
        description = "ex03",
        # cmdclass={'build_ext': Build},
        author = "gbox3d",
        author_email = "gbox3d@gmail.com",
        url = "https://gbox3d.blogspot.com/",
        ext_modules = [Extension("_ex03", ["_ext_main.c"])]
        )

