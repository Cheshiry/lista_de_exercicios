const { gets, print } = require('./funcoesMedia');

const media = gets();

if (media < 5) {
    print("Reprovado " + media);
} else if (media >= 5 && media < 7) {
    print("Recuperação " + media);
} else if (media >= 7){
    print("Aprovado " + media);
}else {
    print("Número invalido")
}
