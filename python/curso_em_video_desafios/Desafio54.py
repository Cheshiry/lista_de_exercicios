from datetime import date

lista_anonasc = []

for amigos in range(0, 7):
    anonasc = int(input("Digite o ano de nascimento do "))
    
    anoatual = date.today().year
    
    idade = anoatual - anonasc
    
    if idade >=  18:    
        lista_anonasc.append(amigos)
        
print(lista_anonasc)
