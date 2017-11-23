@echo off
set /p STUDENT_NAME="Salut! Scrie numele tau cum este scris in catalog (ex. Gardus Matei): "
set /p ID_PROB1="Acum scrie numele primei probleme: "
set /P ID_PROB2="Acum a doua problema: "

powershell -c "(new-object System.Net.WebClient).DownloadFile('https://pastebin.com/raw/iVb9PNDF', 'findrepl.bat')"

set ID_PROB1=

pause