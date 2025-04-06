"""_summary_
Crie um prom que leio um numero 0 a 9999 e mostre:
EX: 1834

unidade:4
dezena:3
centena:8
milhar:1
"""

num = int(input("Digite um número:"))


print(num // 1 % 10, "unidade")
print(num // 10 % 10, "dezena")
print(num // 100 % 10, "centena")
print(num // 1000 % 10, "milhar")
