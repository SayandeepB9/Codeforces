from click import clear
import requests
from bs4 import BeautifulSoup
import os
import shutil

# Define your credentials
username = 'your_username'
password = 'your_password'

base_url = 'https://codeforces.com/contest/{}/problem/{}'

# Start a session
session = requests.Session()

# URL for the login page
login_url = 'https://codeforces.com/enter'

# Get the CSRF token
login_page = session.get(login_url)
soup = BeautifulSoup(login_page.content, 'html.parser')
csrf_token = soup.find('input', {'name': 'csrf_token'})['value']

# Define the payload for login
payload = {
    'csrf_token': csrf_token,
    'action': 'enter',
    'handleOrEmail': username,
    'password': password,
    '_tta': '176'
}

# Post the login request
session.post(login_url, data=payload)

# Function to check if a problem is solved
def is_solved(contest_id, problem_id):
    problem_url = base_url.format(contest_id, problem_id)
    response = session.get(problem_url)
    soup = BeautifulSoup(response.content, 'html.parser')
    table = soup.find('table', class_='rtable smaller')
    if table and 'Accepted' in table.get_text():
        return True
    return False

# Path configurations
current_directory = '.'
solved_directory = './solved'

# Ensure the solved directory exists
if not os.path.exists(solved_directory):
    os.makedirs(solved_directory)

# Iterate over files in the current directory
for filename in os.listdir(current_directory):
    if filename.endswith('.cpp'):
        # Check if the filename follows the specified format
        if len(filename) > 5 and filename[-4:] == '.cpp':
            contest_id = filename[:4]
            problem_id = filename[4]
            if contest_id.isdigit() and problem_id.isalpha():
                if is_solved(contest_id, problem_id):
                    source = os.path.join(current_directory, filename)
                    destination = os.path.join(solved_directory, filename)
                    shutil.move(source, destination)
                    print(f"Moved {filename} to solved directory")

print("Done!")