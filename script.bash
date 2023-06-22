cd compilador
make all
cd ..
cat ./compilador/entrada.txt | ./compilador/saida > response.txt

arquivo="response.txt"
palavra="Erro:"

if ! grep -q "$palavra" "$arquivo"; then
  cat response.txt | ./mdp/interpretador
fi