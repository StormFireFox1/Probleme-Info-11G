declare -a arr=("Anton-Sabin" "Badea-Stefan" "Chitu-Tudor" "Craciun-Bianca" "Dinca-Toni" "Dinu-Horia" "Feodor-Iris" "Gardus-Matei" "Goidea-Andreea" "Gutu-Bianca" "Ionita-Diana" "Lescaie-Denisa" "Letinu-Andrei" "Margineanu-Ana" "Melinte-Irina" "Nicolae-Stefan" "Niculescu-Tudor" "Pasca-Mihai" "Paterau-Tudor" "Petcu-Vlad" "Pirvu-Diana" "Pruna-Teodor" "Stanciu-Teodora" "Tanase-Catalin" "Tiganas-Teodor" "Tigau-David" "Vulpe-Matei")

for i in "${arr[@]}"
do
   git checkout -b "$i"
   git push --set-upstream origin "$i"
   git checkout master
done
git push
