largura =  float(input("Digite a largura da parede: "))
altura =  float(input("Digite a altura da parede: "))

area = largura * altura

tinta_necessaria = area / 2

print(f"A parede tem {area}m² de área e\n vai precisar de {tinta_necessaria:.2f}l de tinta")