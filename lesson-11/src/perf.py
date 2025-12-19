#! /usr/bin/env python3

import time
import ctypes
from functools import lru_cache

import cffi

import cutils


MAX_N = 38

#@lru_cache(maxsize=100)
def fibonacci(n: int):
    if n <= 2:
        return 1
    return fibonacci(n-1) + fibonacci(n-2)

def py_fibonacci():
    start_ts = time.time()
    res = fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[python] Execution time is {end_ts-start_ts:.6f} seconds")
    return res

def ctypes_fibonacci():
    libc = ctypes.CDLL('./ctypes/libutils.so')
    libc.fibonacci.argstype = (ctypes.c_int)
    libc.fibonacci.restype = ctypes.c_int
    start_ts = time.time()
    res = libc.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[ctypes] Execution time is {end_ts-start_ts:.6f} seconds")
    return res

def cffi_fibonacci():
    cffi_builder = cffi.FFI()
    cffi_builder.cdef('''
    int fibonacci(int num);''')

    cffi_builder.set_source('utils',
    r'''int fibonacci(int num)
        {
        if (num <= 2)
            return 1;
        return fibonacci(num - 1) + fibonacci(num - 2);
    }
    ''')

    cffi_builder.compile()

    import utils
    start_ts = time.time()
    res = utils.lib.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[cffi] Execution time is {end_ts-start_ts:.6f} seconds")
    return res

def capi_fibonacci():
    start_ts = time.time()
    res = cutils.fibonacci(MAX_N)
    end_ts = time.time()
    print(f"[capi] Execution time is {end_ts-start_ts:.6f} seconds")
    return res

def main():
    py_res = py_fibonacci()
    ctypes_res = ctypes_fibonacci()
    cffi_res = cffi_fibonacci()
    capi_res = capi_fibonacci()
    assert 39088169 == py_res == ctypes_res == cffi_res == capi_res

if __name__ == "__main__":
    main()
