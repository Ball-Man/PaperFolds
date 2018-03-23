## Paper Folds ##

### About folding paper ###

You can reach the moon(and beyond) by just folding a common paper 42 times. Incredible isn't it?
What about Mars? 52 times. But shall we stop here?

### Fold more ###

Find out how many times you have to fold your paper to reach every place you ever wanted. This easy program will ask for a distance(in meters) and will output the total number of folds neede to cover that distance. Everything you ever wanted in a bunch of KBs. 

### Compile and run ###

Compilation happens via makefile. This means once you are in the project root you can simply run
```
make
```

The binary is generated inside the build/ directory and is named `folds`. Since running the binary requires the config file(paper.config) I recommend copying the binary in a directory along with the config file. Although there is one fast solution which is running it directly from the build/ directory. To do so, while in the project root run:
```makefile
# On Windows
build\folds.exe
```
or
```bash
# On Unix systems
./build/folds
```

### Math ###

Behind this simple program there's a simple equation.
Let's say we have:
```
t: the paper thickness
f: the number of folds
d: the given distance
```
The standard equation would be:
```
t * 2^f = d

which evolves into
2^f = d / t
f = log2(d / t)
```
So thanks to this simple equation we're able to find how many folds are needed to cover the given distance. Of course, given the standard equation and 2 of the 3 parameters we're always able to calculate the third one. In our case, we want to find the `f` parameter, which means that we have to know the other 2 parameters(`t` and `d`).

The program doesn't stop here; Thanks to the logarithms properties the program oversimplifies the equations, so that it can make calculations for very long distances with very small paper thicknesses and almost never encounter an overflow.
