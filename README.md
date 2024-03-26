## Setup

The code in this project leverages the **libcs50** library. To execute the code samples locally, you'll first need to install the library. Detailed instructions for this process are provided below.

#### Prerequisite

- You need to have a valid C compiler installed on your system prior to installing the library. If you're using a Unix-based system like macOS or Linux, you probably already have the **clang** or **gcc** compiler installed.

### Installation Process for Linux and Mac

1. Download the latest release from [CS50's libcs50 repository](https://github.com/cs50/libcs50/releases).
2. Extract the downloaded folder `libcs50-*.*`.
3. Navigate into the folder using `cd libcs50-*` .
4. Run `sudo make install` to install the library.

### Running the Program

To run your program, you need to link `libcs50` when compiling your code. For example, if your file is named **mario.c**, enter:

```bash
clang mario.c -o mario -lcs50
```

Then type `./mario` to run the program!
