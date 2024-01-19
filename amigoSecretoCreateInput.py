import random

n = 4
with open("input", "w") as file:
    file.write(f"{n}\n")
    file.write(f"3\n")
    file.write(f"3\n")
    file.write(f"1\n")
    file.write(f"3\n")

# Gerar escolhas aleatórias para cada funcionário
escolhas = random.sample(range(1, n + 1), n)

# Salvar os dados no arquivo
#with open("input", "w") as file:
#    file.write(f"{n}\n")
#    for escolha in escolhas:
#        file.write(f"{escolha}\n")
