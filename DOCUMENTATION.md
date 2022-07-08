# Introduction
This document is the documentation for ```pastaignore```.
# Documentation
## How a pastaignore file works.
A ```pastaignore``` file consists of lines (called **strands**). A strand has a first regex, an operator and a second regex.
The first and second regex effectively are boolean (true=match) values combined into a single boolean using the operator, if this boolean is true, the file is included in the output file.
## Operators
```not```: first has to be true, second has to be false
<br>
```and```: both have to be true.
## Regexes
Both are in ```c++``` style. Both have to be in double quotes (```"```).