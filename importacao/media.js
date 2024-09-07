const { gets, print } = require('./funcoesMedia');

const media = gets();

if (media < 5) {
    print("Reprovado " + media);
} else if (media >= 5 && media <7) {
    print("Recuperação " + media);
} else {
    print("Aprovado "+ media);
}
