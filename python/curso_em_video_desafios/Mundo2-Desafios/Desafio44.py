from math import pow as quadrado


print("\033[1;36m*" * 100)
print("{:=^100}".format(" Calcule o quanto de juros da compra nas lojas Guanaba "))

preco_original = float(input("Digite o preço do produto: "))
opcao = int(input(""" 
Escolha a forma de pagamento: 
- 1. Dinheiro/ Cheque
- 2. À vista no cartão
- 3. 2x no cartão
- 4. 3x ou mais no cartão:
Qual sua opção: """))

print("\033[1;36m*" * 100)

if opcao == 1:
    novo_preco = preco_original - (preco_original * 0.10)
    print(f"{novo_preco:.2f}")
    
elif opcao == 2:
    novo_preco = preco_original - (preco_original * 0.05)
    print(f"{novo_preco:.2f}")

elif opcao == 3:

    novo_preco = preco_original

    parcela = preco_original / 2
    print(f"{novo_preco:.2f} em 2 parcelas de {parcela}")

elif opcao == 4:
    parcelas = int(input("Em quantas parcelas: "))
    novo_preco = preco_original + (preco_original * 0.20)

    preco_parcela = preco_original / parcelas
    print(f"{novo_preco:.2f} em {parcelas}x parcelas de {preco_parcela:.2f}")

else:
    print("Opção invalida de pagamento! Tente novamente!")
    print(f"Sua compra de {preco_original} vai custar {preco_original}, no final")