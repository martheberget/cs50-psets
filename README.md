## Setup

The code in this project leverages the **libcs50** library. To execute the code samples locally, you'll first need to install the library. Detailed instructions for this process are provided below.

Keep in mind that you need to have a valid C compiler installed on your system prior to installing the library. For Unix-based systems such as macOS and Linux, the **clang** or **gcc** compiler is typically pre-installed.

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
