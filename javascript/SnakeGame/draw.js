const canvas = document.querySelector(".canvas");
const ctx = canvas.getContext("2d");
const scale = 10;
const rows = canvas.height / scale;
const columns = canvas.width / scale;
var snake;
var start = 0;

(function setup() {
  snake = new Snake();
  fruit = new Fruit();
  fruit.pickLocation();

  window.setInterval(() => {
    if (start) {
      ctx.clearRect(0, 0, canvas.width, canvas.height);
      fruit.draw();
      snake.update();
      snake.draw();

      if (snake.eat(fruit)) {
        fruit.pickLocation();
      }

      snake.checkCollision();
      document.querySelector(".current-score-value").innerText = snake.total;
    } else {
      document.querySelector(".current-score-value").innerText = "Press anything to start";
    }
  }, 50);
})();

window.addEventListener("keydown", (evt) => {
  start = 1;
  const direction = evt.key.replace("Arrow", "");
  snake.changeDirection(direction);
});
