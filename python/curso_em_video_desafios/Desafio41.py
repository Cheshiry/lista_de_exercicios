from datetime import date

print("\033[1;95m*" * 50)
print("Classificação Nacional de atletas: ")

ano_nasc = int(input("Digite o ano de nascimento do atleta: "))

ano = date.today().year

idade = ano - ano_nasc

if idade <= 9:
    print(f"Quem nasceu em {ano_nasc} é")
    print("Mirim com ",idade,"anos")
    
elif idade <= 14:
    print(f"Quem nasceu em {ano_nasc} é")
    print("Infantil", idade,"anos")
    
elif idade <= 19:
    print(f"Quem nasceu em {ano_nasc} é")
    print("Junior", idade,"anos")
    
elif idade < 20:
    print(f"Quem nasceu em {ano_nasc} é")
    print("Sênior", idade,"anos")
    
else:
    print(f"Quem nasceu em {ano_nasc} é")
    print("Master", idade,"anos")
