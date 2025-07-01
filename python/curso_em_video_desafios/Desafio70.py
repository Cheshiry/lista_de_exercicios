'''nome produto
preco
produto mais barato
total
nome mais barato
acima de1000
'''
fim = "FIM"
resp = nome_menor = " "
soma_total = acima_1000 = menor_preco = 0
while True:
    nome_produto = str(input("Digite o nome do produto: ")).lower().split()
    preco = float(input("O valor foi R$"))

    soma_total += preco
    print("-"*50)
    resp = str(input("Gostaria de continuar comprando? [S/N]: ")).strip().upper()[0]
    print("-"*50)

    if preco >= 1000:
        acima_1000 += 1

    if menor_preco == 0:
        menor_preco = preco
        nome_menor = nome_produto

    elif preco < menor_preco:
        menor_preco = preco
        nome_menor = nome_produto

    if resp == "N":
        break
print(f"{fim:.^50}")
print(f"""
      O total da compra foi {soma_total:.2f}.
      O teve {acima_1000} produtos acima de R$1000.00.
      O produto mais barato {nome_menor} com o valor R${menor_preco:.2f}.
      """)