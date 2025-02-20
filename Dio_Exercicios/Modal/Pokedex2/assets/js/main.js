const pokemonList = document.getElementById('pokemonList')
const loadMoreButton = document.getElementById('loadMoreBtn')

const maxRecords = 15
const limit = 10
let offset = 0



function loadPokemonItens(offset, limit) {

    pokeApi.getPokemons(offset, limit).then((pokemons = []) => {
        const newHtml = pokemons.map((pokemon) => {
                return `
                    <li onclick="abrirModal();" class="pokemon ${pokemon.type}">
                        <span class="number">#${pokemon.number}</span>
                        <span class="name">${pokemon.name}</span>
            
                        <div class="detail">
                            <ol class="types">
                                ${pokemon.types.map((type) => `<li class="type ${type}">${type}</li>`).join('')}
                            </ol>
            
                            <img src="${pokemon.photo}"
                                 alt="${pokemon.name}">
                        </div>
                    </li>
                `
            }
        ).join('')
        pokemonList.innerHTML += newHtml

        const pokeI = document.querySelectorAll('.pokemon');
        pokeI.forEach(item => {
            item.addEventListener('click', (e)=>{
                abrirModal(e.target.closest('.pokemon'));
            })
        })

    });
}

    loadPokemonItens(offset, limit)

    loadMoreButton.addEventListener('click', () => {
        offset += limit
        const qtdRecordsWithNexPage = offset + limit
    
        if (qtdRecordsWithNexPage >= maxRecords) {
            const newLimit = maxRecords - offset
            loadPokemonItens(offset, newLimit)
    
            loadMoreButton.parentElement.removeChild(loadMoreButton)
        } else {
            loadPokemonItens(offset, limit)
        }
    })

    function abrirModal(elemento) {
        const modal = document.getElementById('janela-modal');
        const conteudoModal = document.getElementById('conteudo-modal');
        
        // Coleta as informações do Pokémon a partir dos atributos data
        const pokem = new Pokemon;

        const number = elemento.getAttribute(pokem.number);
        const name = elemento.getAttribute(pokem.name);
        const types = elemento.getAttribute(pokem.type);
        const photo = elemento.getAttribute(pokem.photo);
    
        // Cria o conteúdo do modal
        const conteudo = `
            <h2>#${pokem.name} - ${name}</h2>
            <div class="types">
                <strong>Types:</strong>
                <span>${types}</span>
            </div>
            <img src="${photo}" alt="${name}" />
        `;
    
        // Coloca o conteúdo no modal
        conteudoModal.innerHTML = conteudo;
    
        // Abre o modal
        modal.classList.add('abrir');
    }
    