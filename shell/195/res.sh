# Read from the file file.txt and output the tenth line to stdout.
c=0 # no space!
# for line in `cat file.txt` # use space
cat file.txt | while read line
do
    c=$[c + 1]  # no space!
    # echo $c
    if [ $c -eq 10 ]
    then
        echo $line
    fi
done