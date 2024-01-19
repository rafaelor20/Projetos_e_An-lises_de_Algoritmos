# Script para gerar arquivo de entrada "input" com valor de n
n = int(input("Digite o valor de n: "))

with open("input", "w") as file:
    file.write(str(n))
