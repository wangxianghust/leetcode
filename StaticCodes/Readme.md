count the numbers of the files:find all py files lines.
find . -name "*.py" | xargs grep -v "^$" | wc -l
