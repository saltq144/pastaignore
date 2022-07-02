![](https://img.shields.io/static/v1?label=tests&message=passing&color=success) ![](https://img.shields.io/static/v1?label=version&message=1.0&color=informational) ![](https://img.shields.io/static/v1?label=build&message=passing&color=success) ![](https://shields.io/github/directory-file-count/saltq144/pastaignore) ![](https://img.shields.io/github/languages/code-size/saltq144/pastaignore) ![](https://img.shields.io/github/license/saltq144/pastaignore) ![](https://img.shields.io/github/last-commit/saltq144/pastaignore)
# Getting started.
## Building
Requirements: ```g++ (c++20)```, ```make```
<br>Run ```make``` and move ```pastaignore``` to somewhere in your ```path``` environment such as ```/usr/local/bin/```.
## Example .pastaignore file
```
".*\.o" not "\.\/demo\/important.*\.o"
```
This will create an output file with all files in current directory and subdirectories and subsubdirectories an... But it will only add to the output files that match the first regex ( ```".*\.o"``` ) but not ( ```not```) files that match the second regex ( ```"\.\/demo\/important.*\.o"```). There isn't currently anything else in ```pastaignore```. See ```CONTRIBUTING.md``` if you want to change that.

<br><br><br><br>
See ```pastaignore -h``` for list of flags.