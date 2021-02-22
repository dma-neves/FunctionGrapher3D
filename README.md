# FunctionGrapher3D
![](https://github.com/dma-neves/FunctionGrapher3D/blob/master/other/function.gif)

**Description:**
  - A softawre renderer created to graph/plot 3d functions
  - I also added a simple program to facilitate the redefinition/modification of the function that is graphed. When the function is redefined the function graphing program is recompiled with the new given expression and parameters
  - Everything was written in C++ using the SFML library
  
**Requirements:**
  1. Linux operating system
  2. GCC(G++) compiler

**Building and running (Linux):**
  - Installing SFML: https://www.sfml-dev.org/tutorials/2.5/start-linux.php    
  - Compiling and running the function modifier: The included makefile will generate the executable FunctionModifier.out
  - Compiling and running the function grapher: The included makefile will generate the executable FunctionGrapher.out inside the bin folder
      
 **Camera controls:**
   - W, A, S, D for rotation
   - Up and Down arrow keys to zoom in and out
