"""_summary_
Crie um prom que leio o nome da cidade e mostre:
se ela começa com "Santo"
"""

nome = str(input("Digite o nome da sua cidade: ")).strip()

print(nome[:5].upper() == "SANTO")
