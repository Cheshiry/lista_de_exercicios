from math import pow as quadrado


print("\033[1;36m*" * 100)
print("Calcule o quanto de juros da compra: ")

preco_original = float(input("Digite o preço do produto: "))
opcao = int(input(""" 
Escolha a forma de pagamento: 
- 1. Dinheiro/ Cheque
- 2. À vista no cartão
- 3. 2x no cartão
- 4. 3x ou mais no cartão:
"""))

print("\033[1;36m*" * 100)

if opcao == 1:
    novo_preco = preco_original - (preco_original * 0.10)
    print(f"{novo_preco:.2f}")
    
elif opcao == 2:
    novo_preco = preco_original - (preco_original * 0.05)
    print(f"{novo_preco:.2f}")

elif opcao == 3:
    novo_preco = preco_original
    print(f"{novo_preco:.2f}")

else:
    novo_preco = preco_original + (preco_original * 0.20)
    print(f"{novo_preco:.2f}")