function convertPokeInfo(pokeDetail) {
    const pokemon = new Pokemon()
    pokemon.number = pokeDetail.id
    pokemon.name = pokeDetail.name
    pokemon.types = pokeDetail.types.map((typeSlot) => typeSlot.type.name)

    const types = pokeDetail.types.map((typeSlot) => typeSlot.type.name)
    const [type] = types

    pokemon.types = types
    pokemon.type = type

    pokemon.photo = pokeDetail.sprites.other.dream_world.front_default

    return pokemon
}

 

// Modal e botão de fechar
 const modal = document.getElementById('janela-modal');
 const closeBtn = document.getElementById('fechar');
 const modalDetails = document.getElementById('modal');
 const itemList = document.getElementById('pokemonList')



 // Quando um item é clicado
 itemList.addEventListener('click', (event) => {
     if (event.target.tagName === 'LI') {
         // Preencher os detalhes da modal com base no item
         modalDetails.textContent = event.target.dataset.description;
         modal.style.display = 'block';
     }
 });

 // Fechar a modal
 closeBtn.addEventListener('click', () => {
     modal.style.display = 'none';
 });

 // Fechar a modal ao clicar fora da janela modal
 window.addEventListener('click', (event) => {
     if (event.target === modal) {
         modal.style.display = 'none';
     
 }}); 

