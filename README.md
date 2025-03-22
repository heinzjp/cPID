# cPID

Building and Installing
    At the top level directory (with the Makefile) run the command:
        $ make

Installing
    To install the package, such that the .so is in /usr/local/lib and the header file is in /usr/local/include, run the command: 
        $ sudo make install

    You need to update the system's linker cache so that it knows about the library. To do this, run: 
        $ sudo ldconfig

    Check if the system can find the library by running the command: $ ldconfig -p | grep libcPID

Running the example files

    In a terminal, run the command: $ ./build/example

