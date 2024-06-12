// TODO: MAKE A HIGHSCORE
(function () {
  if (localStorage.getItem("highscore") != null) {
    document.querySelector(".high-score-value").innerHTML = localStorage.getItem("highscore");
  }
  else {
    localStorage.setItem("highscore", 0);
    document.querySelector(".high-score-value").innerHTML = localStorage.getItem("highscore");
  }
})();
