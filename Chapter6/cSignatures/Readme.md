# C Signatures
Observe major differences on how C and C++ compiler names the functions (signatures) into a compilation units
Compare with a C++ program

# Build
Just do 

```bash
mkdir build
cd build
cmake ..
make -j 4
```

# Test
Use nm to inspect binary signatures
```bash
nm cSignatures
0000000100000000 T __mh_execute_header
0000000100000880 T _main
                 U _printf
0000000100000840 T _sum_d
0000000100000860 T _sum_f
```

As you can see signatures are human readable an are easily identifiable on memory position
Whereas C++ uses name or signature mangling to support:
- function overloading
- templates
- namespaces
- classes and member functions
- operator overloading

E.g:
```
__Z3sumi      // sum(int)
__Z3sumd      // sum(double)
```

To demangle C++ binary there is a tool called c++filt
```
nm binary.out | c++filt
```