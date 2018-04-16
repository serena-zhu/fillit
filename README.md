# <a name="top">fillit</a>

Fillit is a program that takes a file containing a list of Tetriminos and returns the result of arranging them in order to create the smallest possible square. 

Among all possible solutions for the smallest square, the one where Tetriminos are placed on their most upper-left position is selected. In the solution, each Tetrimino will be assgined a capital letter in accordance to the order it appearred in the file. The maximum number of Tetriminos that can be passed in a file is, therefore, 26.

This was completed as a two-member team project at 42.

[Language & Functions Used](#language_functions) | [Installation](#install) | [Usage](#usage) | [Example](#example)

## <a name="language_functions">Language & Functions Used</a>

The fillit program is written in C, using only the following functions from the standard C libraries:

* open
* close
* read
* write
* malloc
* free
* exit

<a href="#top">↥ back to top</a>

## <a name="install">Installation</a>

#### `Step 1` - clone the repo

```bash
$ git clone https://github.com/serena-zhu/fillit.git
```

#### `Step 2` - compile program

```bash
$ make
```

The Makefile will compile a progra named fillit.

<a href="#top">↥ back to top</a>

## <a name="usage">Usage</a>

#### `Valid Tetriminos`

* Each Tetrimino must be described with 4 lines of 4 characters, each line followed by a new line. 

* A Tetrimino is a classic piece of Tetris composed of 4 blocks, where blocks are represented by '#'.

* Empty characters are represented by '.'.

* Each block of a Tetrimino must touch at least one other block on any of its 4 sides.
A rotated Tetrimino describes a different Tetrimino, this program will not rotate any pieces.

Examples of valid descritpions of Tetriminos:

<img src="valid_tetriminos_example.png" width="400" height="60">

Examples of invalid descriptions of Tetriminos:

<img src="invalid_tetriminos_example.png" width="400" height="60">

#### `General Usage`
```bash
$ ./ft_ssl
usage: ./fillit source_file
```
Running the program without any parameters will prompt the usage message.

#### `Invalid Files`
```bash
$ ./ft_ssl invalid_file.txt
error
```
Passing an invalid (or empty) file will prompt the error message. 

<a href="#top">↥ back to top</a>

## <a name="example">Example</a>

Here is an example of a valid file and the solution:

<img src="program_example.png" width="200" height="400">

<a href="#top">↥ back to top</a>
