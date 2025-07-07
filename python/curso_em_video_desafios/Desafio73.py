Times_campeonato = ("1º Palmeiras","2.º Santos","3.º Vasco da Gama",
"4.º Grêmio","5.º Flamengo","6.º Corinthians","7.º Internacional","8.º Cruzeiro","9.º São Paulo","10.º Atlético Mineiro","11.º Botafogo","12.º Fluminense","13.º Coritiba","14.º Bahia","15.º Goiás","16.º Guarani","17.º Sport","18.º Portuguesa","19.º Atlético Paranaense","20.º Vitória")
Times_campeonato_semnum = ("Palmeiras","Santos","Vasco da Gama","Grêmio","Flamengo","Corinthians","Internacional","Cruzeiro","São Paulo","Atlético Mineiro","Botafogo","Fluminense","Coritiba","Bahia","Goiás","Guarani","Sport","Portuguesa","Atlético Paranaense","Vitória")

print("Os cinco primeiros: ")
print(Times_campeonato[:5])

print("*"*90)
print("Os cinco ultimos: ")
print(Times_campeonato[-4:])

print("*"*90)
print("Em ordem alfabetica: ")
print(sorted(Times_campeonato_semnum))

print("*"*90)
if "chapecoense" in Times_campeonato:
    print("Foi encotrado o time!")
else:
    print("Infelizmente este time não está presente.")