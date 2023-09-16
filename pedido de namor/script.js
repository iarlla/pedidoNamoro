function moveButtonNo() {
    const buttonNo = document.getElementById('buttonNo');
    const screenWidth = window.innerWidth - buttonNo.clientWidth;
    const screenHeight = window.innerHeight - buttonNo.clientHeight;

    const randomX = Math.floor(Math.random() * screenWidth);
    const randomY = Math.floor(Math.random() * screenHeight);

    buttonNo.style.left = `${randomX}px`;
    buttonNo.style.top = `${randomY}px`;
}

document.getElementById('buttonNo').addEventListener('mouseover', moveButtonNo);

document.getElementById('buttonYes').addEventListener('click', function() {
    alert("Claro que aceito! 💖");
});

