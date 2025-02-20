const pokeApi = {}

function convertPokeApiDetailToPokemon(pokeDetail) {
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

pokeApi.getPokemonDetail = (pokemon) => {
    return fetch(pokemon.url)
            .then((response) => response.json())
            .then(convertPokeApiDetailToPokemon)
}

pokeApi.getPokemons = (offset = 0, limit = 10) => {
    const url = `https://pokeapi.co/api/v2/pokemon?offset=${offset}&limit=${limit}`
    
    return fetch(url)
        .then((response) => response.json())
        .then((jsonBody) => jsonBody.results)
        .then((pokemons) => pokemons.map(pokeApi.getPokemonDetail))
        .then((detailRequests) => Promise.all(detailRequests))
        .then((pokemonsDetails) => (pokemonsDetails))
        }


        function pokeInfo() {
            itemLIst = 
            console.log("Deu certo!");
        }
       
        

        /* // Modal e botão de fechar
    const modal = document.getElementById('janela-modal');
    const closeBtn = document.getElementById('fechar');
    const modalDetails = document.getElementById('modal');

    // Quando um item é clicado
    itemList.addEventListener('click', (event) => {
        if (event.target.tagName === 'li') {
            // Preencher os detalhes da modal com base no item
            
            data.forEach(pokemon => {
            pokemon.number = pokeDetail.id
            pokemon.name = pokeDetail.name
            pokemon.types = pokeDetail.types.map((typeSlot) => typeSlot.type.name)
        
            });
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
        }
    });


        

        */