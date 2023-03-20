# INTRODUCTION TO BETTY - The evil b'\*'tch

Contrary to popular believe, `betty` is a linter program that ensure that your code conforms to intitutional standards of coding. The linter is based on the [Linux Kernel coding style] (https://git.kernel.org/pub/scm/linux/kernel/git/torvalds/linux.git/plain/Documentation/process/coding-style.rst) borrowing much from the philosophies of from [Linus Torvalds](https://en.wikipedia.org/wiki/Linus_Torvalds) the creator of the Linux Kernel. 

## INSTALLING `betty` LOCALLY
I am ssuming you are using Linux on your machine or if you are on Windows you have installed linux flavors as `Ubuntu` through the app store.

```bash
git clone https://github.com/holbertonschool/Betty.git
cd Betty
sudo ./install.sh
```
The linter is successfully installed. The next process is to create a script to invoke the printer. Copy the below script and save it as `betty`

```bash
#!/bin/bash
# Simply a wrapper script to keep you from having to use betty-style
# and betty-doc separately on every item.
# Originally by Tim Britton (@wintermanc3r), multiargument added by
# Larry Madeo (@hillmonkey)

BIN_PATH="/usr/local/bin"
BETTY_STYLE="betty-style"
BETTY_DOC="betty-doc"

if [ "$#" = "0" ]; then
    echo "No arguments passed."
    exit 1
fi

for argument in "$@" ; do
    echo -e "\n========== $argument =========="
    ${BIN_PATH}/${BETTY_STYLE} "$argument"
    ${BIN_PATH}/${BETTY_DOC} "$argument"
done
```
After saving run the following commands:
```bash
chmod a+x betty
sudo mv betty /bin/
```
Now you can invoke the `betty` linter by just typing `betty` the followed with the `c` file that you aim on linting.

## RULES USING THE LINTER
