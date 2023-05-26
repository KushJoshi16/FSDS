from flask import Flask, request, render_template, jsonify

app = Flask(__name__)

@app.route('/')
def home():
    return render_template("home_page.html", proxy_be='https://jsonplaceholder.typicode.com')
#     itemval= {
#     "item1": 203,
#     "item2": 20,
#     "item3": 860,
#     "item4": 203,
# })

if __name__ == "__main__":
    app.run(host="127.0.0.1", port=5000)
