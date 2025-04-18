from datetime import date
print("\033[1;96m+=" * 20)
print("Descubra se está atrasado no alistamento: ")
idade_ano = int(input("Digite seu ano de  nascimento:  "))
print("+=" * 20)
hoje = date.today().year

idade = hoje - idade_ano

if idade < 18:
    falta_ano = 18 - idade
    print(f" você tem {idade} e não precisa se alistar ainda faltam {falta_ano} ano(s).")

elif idade > 18:
       mais_18 = idade - 18
       print(f" você tem {idade} e já passou {mais_18} ano(s) de se alistar.")
       
else:
    print(f" você tem {idade} e já precisa se alistar.")
resp = str(input("Você já se alistou? s/n\n"))
print("+=" * 20)
if resp == "s":
    print("Você não precisase preocuparentão")
else:
    print("Procure saber sobre seu alistamento urgente é obrigatório!")    

