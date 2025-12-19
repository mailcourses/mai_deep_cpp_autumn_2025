#! /usr/bin/env python3

from setuptools import setup, Extension

def main():
    setup(name = "cutils",
          version = "0.0.1",
          author = "A. Kukhtichev",
          ext_modules = [Extension('cutils', ['cutils.cpp'])]
    )

if __name__ == "__main__":
    main()
