# TerminalClipboard

A handy set of commands that allow for clipboard-like functionality on the command line. Using the system of pipes you know and love.

# Usage

```
tccopy - Standard input to clipboard. Either pipe data in or enter manually, using CTRL+D to finish.
tcpaste - Read clipboard data into standard output
tcclear - Erase clipboard
```

# Installation

NOTE: You will need the Boost.Interprocess headers installed

```
make buildlib
make installlib
make build
make install
```

# API

This also includes a C++ api for editing clipboard data. The header is pretty self explanitory, but make sure to not read from the clipboard if the size is 0.

# Disclaimer

This is only made to run on Linux, and since many operating systems lack persistand shared memory it might not function as well. It does use memory, so don't store too much or you'll have problems.
