from flask import Flask, send_from_directory, render_template_string
import os

app = Flask(__name__)
BASE_DIR = os.path.dirname(os.path.abspath(__file__))

@app.route('/')
def index():
    files = [f for f in os.listdir(BASE_DIR) if f.endswith('.c')]
    return render_template_string("""
    <h1>Available C Files</h1>
    <ul>
    {% for file in files %}
      <li><a href="/download/{{ file }}">{{ file }}</a></li>
    {% endfor %}
    </ul>
    """, files=files)

@app.route('/download/<path:filename>')
def download(filename):
    return send_from_directory(BASE_DIR, filename, as_attachment=True)

if __name__ == '__main__':
    app.run()

