from flask import Flask,render_template,request
from chatterbot import ChatBot
from chatterbot.trainers import ChatterBotCorpusTrainer
app=Flask(__name__)
english_bot=ChatBot("Chatterbot",storage_adapter="chatterbot.storage.SQLStorageAdapter")
trainer=ChatterBotCorpusTrainer(english_bot)
trainer.train("chatterbot.corpus.english")
trainer.train("data/data.yml")


@app.route("/")
def index():
    return render_template("index.html") #to send context to html file 
    
@app.route("/get")
def get_bot_response():
    userText=request.args.get("msg") #to get data from input,we write javascript to index.html
    return str(english_bot.get_response(userText))
  
if __name__=="__main__":
    app.run(debug=True)