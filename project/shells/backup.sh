
clear

if [ $# != 1 ]
then
clear
echo 'You must enter a single folder name that specifies the folder to back up'
exit
fi

# check if the number of external arguments is equal to one



if [ ! -d $1 ]
then
clear
echo 'The folder you named does not exist. New folder and contents will be created'
mkdir $1&&touch $1/a.txt $1/b.txt
f=$(basename $(pwd)); #basename strips directory information and suffixes from file names i.e. it prints the file name NAME with any leading directory components removed.
echo "Folder $1 and its contents created to folder $f" 
sleep 5 #sleep command is used to create a dummy job. A dummy job helps in delaying the execution
fi

echo ---------------------------
date=`date +%F` #full date



if [ -d /tmp/backups/$1_$date ] #Is there another folder that was backed up today?
then
echo 'This folder was backed up today. Overwrite it anyway? (If your answer is yes press y. If your answer is no press n)'
read answer  #Inserted answer is placed in answer variable with "read answer" command
    if [ $answer != 'y' ]
    then
    exit #If answer is not "Y", existing.....
    fi
else
mkdir -p /tmp/backups/$1_$date  #mkdir -p: no error if existing, make parent directories as needed
echo  /backup folder and $1_$date folder created to /tmp folder.
sleep 5
fi

cp -R $1 /tmp/backups/$1_$date    #cp -R,-r: copy directories recursively
echo  $1 folder contents  backed up to folder /tmp/backups/$1_$date
sleep 5

echo backup completed
echo If you want you can delete /tmp/$1 folder and
echo /tmp/backups/$1_$date folder.
echo The /tmp folder itself will already be deleted when you shut down the system
sleep 1

echo MAINLY FOLDER CONTENTS
ls -l $1
sleep 1

echo BACKED UP FOLDER CONTENTS
ls -l /tmp/backups/$1_$date/$1/
echo Script ended.....
