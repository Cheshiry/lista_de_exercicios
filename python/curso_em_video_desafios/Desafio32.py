from datetime import date


ano = int(input("Digite um ano se 0 verificará o ano atual:  "))

if ano == 0:
    ano = date.today().year
    print("{}".format(ano))

if ano % 4 == 0 and ano % 100 != 0 or ano % 400 == 0:
    print("o ano {} e bissexto".format(ano))

else:
    print("o ano {} não é bissexto".format(ano))
