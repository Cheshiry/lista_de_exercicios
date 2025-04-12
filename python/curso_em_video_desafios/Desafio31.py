distania = float(input("Digite a distancia: "))

if distania < 200:
    valor = distania * 0.50
    print("Você vai pagar {}".format(valor))

else:
    valor = distania * 0.45
    print("Você vai pagar {}".format(valor))