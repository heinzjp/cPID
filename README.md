# cPID

## Description
The cPID library is a C-based implementation of a PID (Proportional-Integral-Derivative) controller designed for embedded systems and general-purpose control applications.

## Building
At the top level directory (with the Makefile) run the command:

    $ make
    

## Installing
To install the package, such that the .so is in /usr/local/lib and the header file is in /usr/local/include, run the command: 
    
    $ sudo make install

You need to update the system's linker cache so that it knows about the library. To do this, run: 
    
    $ sudo ldconfig

Check if the system can find the library by running the command: 

    $ ldconfig -p | grep libcPID

## Running Example
In a terminal, run the command: 

    $ ./build/example
