
//3) Faça um programa que dado uma lista de nomes imprima os nomes que começem com a letra "V".
// Lista de nomes
const nomes = ["Valentina", "Carlos", "Vitor", "Ana", "Veronica", "Bruno"];

// Função para verificar e imprimir nomes que começam com "V"
function imprimirNomesComV(lista) {
  for (let i = 0; i < lista.length; i++) {
    if (lista[i].startsWith("V")) {
      console.log(lista[i]);
    }
  }
}

// Chama a função com a lista de nomes
imprimirNomesComV(nomes);

/*
const nomes = ["Victor", "Ana", "Vanessa"];

// Função para filtrar e imprimir nomes que começam com a letra 'V'
for (var i = 0; i < nomes.length; i++) {
    // Filtra os nomes que começam com 'V'
    const nomesComV = nomes.filter(nome => nome.startsWith('V'));
    
    // Imprime os nomes filtrados
    nomesComV.forEach(nome => console.log(nome));
}


*/
