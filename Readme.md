# Mirage

## Requirements

The project uses [CMake](https://cmake.org/) (3.18.0 or newer) to generate the project and solution files.

## VSCode

The project is fully compatible with [VSCode](https://code.visualstudio.com/) IDE with C++ and CMake extensions support for better development experience on different Operating Systems (OS). _The recommended extensions can be installed on opening the project._

## Without VSCode

CMake default build pipeline:
```
cd build && cmake ..
```

Create a symbolic link **in the root**, e.g. for `ccls` or other language server:
```
ln -s build/compile_commands.json .
```