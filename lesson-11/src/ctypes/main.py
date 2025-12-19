#! /usr/bin/env python3

import ctypes

def main():
    libc = ctypes.CDLL('./libutils.so')
    libc.sum.argstype = (ctypes.c_int, ctypes.POINTER(ctypes.c_int))
    libc.sum.restype = ctypes.c_int

    arr = [1,2,3,4,5]
    arr_type = ctypes.c_int * len(arr)
    res = libc.sum(ctypes.c_int(len(arr)), arr_type(*arr))
    print(res)

if __name__ == "__main__":
    main()
