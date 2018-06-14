Clear-Host
$Surname = Read-Host -Prompt 'Salut! Zii numele tau'
$FirstName = Read-Host -Prompt 'Acum zii prenumele tau'
$FirstID = Read-Host -Prompt 'Scrie repede numele primei probleme'
$SecondID = Read-Host -Prompt 'Scrie repede numele celei de a doua probleme'

$OriginalDirectory = $PWD

$FOLDER_PROB1 = Get-ChildItem $OriginalDirectory $FirstID -Recurse -Directory
$FOLDER_PROB2 = Get-ChildItem $OriginalDirectory $SecondID -Recurse -Directory

Set-Location ~\Desktop

mkdir "$Surname $FirstName"
Set-Location "~\Desktop\$Surname $FirstName"
mkdir "$FOLDER_PROB1"
mkdir "$FOLDER_PROB2"

Copy-Item -Path "$OriginalDirectory\$FOLDER_PROB1\main.cpp" -Destination "~\Desktop\$Surname $FirstName\$FOLDER_PROB1\main.cpp"
Copy-Item -Path "$OriginalDirectory\$FOLDER_PROB2\main.cpp" -Destination "~\Desktop\$Surname $FirstName\$FOLDER_PROB2\main.cpp"

Write-Host "Cleaning up..."
$OriginalPath = Split-Path -Path $OriginalDirectory -Parent
Remove-Item "$OriginalPath\master.zip"

Write-Host "Gata! Misto test, nu?"
Start-Sleep 2
Clear-Host