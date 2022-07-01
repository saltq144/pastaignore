# Contributing
General rules:<br>
- If you're making a new feature that hasn't been suggested yet, please suggest it first. Don't make it if the suggestion (your or not) has received negative feedback.<br>
- Suggest features by making a new issue.
- Don't suggest features that are completely pointless.
- Please make tests. If you don't this program **will** break. It's not a question of if, it's a question of when.
- Please think about backwards compatibility. It's not fun to have to rewrite your entire ```.pastaignore``` file because someone reinvented regex.
- Bloat is bad. Try to think about code size atleast somewhat.
- Performance is a good thing. Don't do 78 nested for loops. Find a better way to implement your feature.
- Don't break the style of command-line arguments. This does overlap with backwards compatibility, but not completely.
- Don't push broken code. Testing doesn't take long.

First ```git clone``` this repo. Then make your changes. ```git add ```and ```commit```, make a pull request.
