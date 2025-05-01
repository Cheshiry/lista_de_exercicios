dias = int(input("Digite por quantos dias ficou com o carro: "))
km = float(input("Digite por quantos km rodou com o carro: "))  

total = (km * 0.15) + (dias * 60)

print("\nAndou {}km por {} dias e o total do aluguel ficou {:.2f}\n".format(km, dias, total))