// script.js

// Simulando uma resposta de API com o fetch
document.addEventListener('DOMContentLoaded', () => {
    // Suponha que temos os dados simulados de uma API
    const data = [
        { id: 1, name: 'Item 1', description: 'Detalhes do Item 1' },
        { id: 2, name: 'Item 2', description: 'Detalhes do Item 2' },
        { id: 3, name: 'Item 3', description: 'Detalhes do Item 3' }
    ];

    // Preenchendo a lista com os itens
    const itemList = document.getElementById('item-list');
    data.forEach(item => {
        const li = document.createElement('li');
        li.textContent = item.name;
        li.dataset.description = item.description; // Armazenando detalhes na data
        li.dataset.id = item.id;
        itemList.appendChild(li);
    });

    // Modal e botão de fechar
    const modal = document.getElementById('modal');
    const closeBtn = document.getElementById('close-btn');
    const modalDetails = document.getElementById('modal-details');

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
        }
    });
});
