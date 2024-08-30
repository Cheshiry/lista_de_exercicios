const nomes = ["Victor", "Ana", "Vanessa"];

// Função para filtrar e imprimir nomes que começam com a letra 'V'
for (var i = 0; i < nomes.length; i++) {
    // Filtra os nomes que começam com 'V'
    const nomesComV = nomes.filter(nome => nome.startsWith('V'));
    
    // Imprime os nomes filtrados
    nomesComV.forEach(nome => console.log(nome));
}


