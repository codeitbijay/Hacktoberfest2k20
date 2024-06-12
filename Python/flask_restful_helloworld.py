from flask import Flask
from flask_restful import Api, Resource

app = Flask(__name__)
api = Api(app)

names = {
    "kukkik": {
        "age": 30,
        "gender": "male"
    },
    "vi": {
        "age": 37,
        "gender": 'female'
    }
}

## create class inheriting from Resource
class HelloWorld(Resource):

    ## get request to url
    def get(self, name):
        """
        Return dictionary; in rest api, the returned value has to be json serializable
        """
        return names[name]

    ## post request to url
    def post(self):
        """
        Return dictionary; in rest api, the returned value has to be json serializable
        """
        return {"data":"posted"}

# api.add_resource(HelloWorld, "/")
api.add_resource(HelloWorld, "/helloworld/<string:name>")


if __name__ == '__main__':
    app.run(debug=True)

##### test.py
# import requests
# BASE = 'http://127.0.0.1:5000/' ## flask default url
# response = requests.get(BASE + 'helloworld/vi')
# print(response.json()) ## {'age': 37, 'gender': 'female'}