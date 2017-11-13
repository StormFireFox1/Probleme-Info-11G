#!/bin/sh

echo "Salut! Zii numele tau (nume prenume, ex. Gardus Matei): "
read -r STUDENT_SURNAME STUDENT_NAME
echo "Scrie repede numele celor doua probleme EXACT separate cu spatiu:"
read -r ID_PROB1 ID_PROB2

FOLDER_PROB1=$(find . -type d -name "$ID_PROB1")
FOLDER_PROB2=$(find . -type d -name "$ID_PROB2")

cd ~/Desktop
mkdir "$STUDENT_SURNAME $STUDENT_NAME"
cd "$STUDENT_NAME $STUDENT_SURNAME"
mkdir "$FOLDER_PROB1"
mkdir "$FOLDER_PROB2"
cd $OLDPWD
cp "./$FOLDER_PROB1/main.cpp" "~/Desktop/$STUDENT_SURNAME $STUDENT_NAME/$FOLDER_PROB1/main.cpp"
cp "./$FOLDER_PROB2/main.cpp" "~/Desktop/$STUDENT_SURNAME $STUDENT_NAME/$FOLDER_PROB2/main.cpp"

echo "Gata! Misto test, nu?"
sleep 2

