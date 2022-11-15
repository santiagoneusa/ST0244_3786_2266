import string
import requests
from bs4 import BeautifulSoup
import scraping as s


def ask_origin():
    
    origin_user_input = string.capwords(input('Origin Character: ')).split()
    
    # Organize the imput
    origin_url_end = '_'.join(origin_user_input)
    origin_url = 'http://en.wikipedia.org/wiki/' + origin_url_end
    
    return origin_user_input, origin_url


def ask_target():
    
    target_user_input = string.capwords(input('Target Character: '))
    return target_user_input


def data(url):
    
    # Downloading the data
    request = requests.get(url)
    content = BeautifulSoup(request.content, 'html.parser')
    
    return content
    

def create_abc():
    
    abc = ['a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z']
    abc = [x.upper() for x in abc]
    return abc


def search_origin_target():
    
    origin_user_input, origin_url = ask_origin()
    origin_content = data(origin_url)
    target_character = ask_target()
    
    path = []
    counter = 10
    found = False
    
    s.scraping(origin_content, target_character, path, counter, found)
    show_path(origin_user_input, found, path)  


def search_origin_abc():
    
    origin_user_input, origin_url = ask_origin()
    origin_content = data(origin_url)
    
    path = []
    abc = create_abc()
    
    position = 0
    counter = 26
    found = False
    
    path = s.scraping_abc(origin_content, path, counter, abc, position)
    show_path(origin_user_input, found, path)  


def show_path(origin_user_input, found, path):
    
    for word in origin_user_input: print(word, end = ' ')
    print('--> ', end = '')
    
    if found is False:
        for position in range(len(path)):
            if position < len(path) - 1: print(f'{path[position]} --> ', end = '')
            else: print(f'{path[position][0]}: {path[position][1]}')
    else:
           for position in range(len(path)):
                if position < len(path) - 1: print(f'{path[position]} --> ', end = '')
                else: print(path[position])