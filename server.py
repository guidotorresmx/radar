import logging
log = logging.getLogger('werkzeug')
log.setLevel(logging.ERROR)
import pprint
import json
import pandas as pd
import random
from flask import (
    Flask,
    jsonify,
    request
)


app = Flask(__name__)

pp = pprint.PrettyPrinter(indent=4)
print = pp.pprint

@app.route('/', methods=['POST'])
def add_message():

    content = json.loads(request.data)
    #df = pd.read_json(content)
    print(str(content))
    return jsonify(content)


if __name__ == '__main__':
    app.run(host='0.0.0.0', debug=True, port=5000)
