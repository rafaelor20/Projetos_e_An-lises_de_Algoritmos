# Geração do arquivo de entrada 'input'
with open('input', 'w') as file:
    file.write('5\n')  # Substitua 5 pelo número desejado de semanas

    for _ in range(5):  # Substitua 5 pelo número desejado de semanas
        preco = int(input("Digite o preço para a semana: "))
        file.write(f'{preco}\n')

print("Arquivo 'input' gerado com sucesso.")
