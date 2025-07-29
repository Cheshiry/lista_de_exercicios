palavras = ("alegria","amor","lua","uva","desafio","Dracula","python","html")

for p in palavras:
    print(f"\nA palavra {p.upper()} temos ", end =" ")
    for letra in p:
        if letra.lower() in ("aeiou"):
            print(letra, end = "")
            
print("\n")