#!/bin/sh
#lets say file name is : "my file" 
#the file can be deleted by any of the following ways
#touch command is used to create empty files
touch 'my file'
rm 'my file'
touch 'my file'
rm my' 'file
touch 'my file'
rm m'y fi'le 
touch 'my file'
rm "my file"
touch 'my file'
rm my\ file
touch 'my file'
rm my" "file
touch 'my file' 
#only one file will left after exection

exit