# FunctionGrapher3D

**Description:**
  - A softawre renderer created to graph/plot 3d functions
  - I also added a simple program to facilitate the redefinition/modification of the function that is graphed. When the function is redefined the function graphing program is recompiled with the new given expression and parameters
  - Everything was written in C++ using the SFML library
  
**Requirements:**
  1. Linux operating system
  2. GCC(G++) compiler

**Building and running (Linux):**
  1. *Installing SFML*
      - Use the command `sudo apt-get install libsfml-dev` using the terminal
      - A more comprehensive installation guide can be found at (https://www.sfml-dev.org/tutorials/2.5/start-linux.php)
      
  2. *Compiling and running the function modifier*
      - Inside the folder/directory 'FunctionModifier' you can compile the program using the `make` command
      - To run it use the command `./FunctionModifier.out`
      
  3. *Compiling and running the function grapher*
      - Inside the directory 'Grapher' you can compile the program using the `make` command
      - To run it continue to the 'bin' directory and use the command `./FunctionGrapher.out`
      
 **Camera controls:**
   - W, A, S, D for rotation
   - Up and Down arrow keys to zoom in and out
