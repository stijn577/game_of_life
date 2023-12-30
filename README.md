# Conway's Game Of Life

## This is a game idea I got from a friend who was gonna write his own version in C++ using SFML to make the graphics. So I decided to have a little competition to see who could make it faster

### Running the code

Download the git repo and run the code using the makefile, I'm using nushell so you might have to tweak the SH variable and how it exactly calls the function, for example changing:

```Makefile
${SH} -c "<command for nushell>"
```

to the respective way to do so in your preferred shell. Other than that I'm planning to make some start configs in text that you can call after build using:

```sh
./a <filename>
```

where the filename contains a start configuration like a glider or a blinker. You could for example run

```sh
./a blinker
```

This will start the blinker program