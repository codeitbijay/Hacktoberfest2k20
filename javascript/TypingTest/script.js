const setOfWords = ["Full of the joys of spring. This idiom is good for expressing delight, joy, energy, and enthusiasm. ",
    "This is another great idiom that means the same thing as the expression “on cloud nine.In other words, you are ecstatically happy about something. You simply feel wonderful.",
    "This is said about a person who is completely satisfied with his life or with a certain situation in life. Everything is fine with him, he never complains, and he simply enjoys life. If the word “not” is added, it has the opposite meaning.",
    "This is today’s last idiom that can be used to describe happiness. The color red is bright and can be associated with happiness. This idiom is used when a person is very happy and is going to go celebrate something with friends or relatives, or going out to a bar, club, or party to have a good time.",
    "If you do good, people will accuse you of selfish ulterior motives. Do good anyway.If you are successful, you will win false friends and true enemies. Succeed anyway. The good you do today will be forgotten tomorrow. Do good anyway.",
    "There's nothing like deep breaths after laughing that hard. Nothing in the world like a sore stomach for the right reasons.",
    "Every man has his secret sorrows which the world knows not; and often times we call a man cold when he is only sad.",
    "To be so strong that nothing can disturb your peace of mind. To talk health, happiness, and prosperity to every person you meet."
]
const text = document.getElementById('msg');
const typeWords = document.getElementById('myWords');
const btn = document.getElementById('btn');
let startTime, endTime;

const playGame = () => {
    let randomNumber = Math.floor(Math.random() * setOfWords.length);
    text.innerHTML = setOfWords[randomNumber];
    let date = new Date();
    startTime = date.getTime();
    btn.innerText = "Done";
}
const endPlay = () => {

    let date = new Date();
    endTime = date.getTime();
    let totalTime = Math.round(((endTime - startTime) / 1000));
    let totalStr = typeWords.value;
    let strCount = totalStr.split(" ").length;
    let speed = Math.round(((strCount / totalTime) * 100));
    let lastWords = "your typing speed is : " + speed + " Words per minute ";
    lastWords += compareWords(text.innerText, totalStr);
    text.innerText = lastWords;
}
const compareWords = (str1, str2) => {
    let words1 = str1.split(" ");
    let words2 = str2.split(" ");
    let count = 0;
    words1.forEach(function (item, index) {
        if (item == words2[index]) {
            count++;
        }
    });
    let errorWords = (words1.length - count);
    return (count + " correct ot of  " + words1.length + " words and total no of errors are " + errorWords + ".");
}

btn.addEventListener('click', function () {
    if (this.innerText == "Start") {
        typeWords.disabled = false;
        playGame();
    } else if (this.innerText == "Done") {
        typeWords.disabled = true;
        btn.innerText = "Start";
        endPlay();
        myWords.value = "";
    }
})