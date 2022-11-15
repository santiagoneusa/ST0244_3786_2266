import pandas as pd
import os
from tqdm import tqdm
import spacy
from spacy.tokens import DocBin

# If you want to work with your oun NER model you have to train it.
# These are some cases I used to train mine.

train_data = [("Early life and career of Santiago Neusa", {'entities': [(24, 38, 'Person')]}),
              ("In the 13th Samuel L. Jackson was born", {'entities': [(12, 29, 'Person')]}),
              ("Public image of Oprah Winfrey", {'entities': [(16, 29, 'Person')]}),
              ("Ayatollah Khomeini", {'entities': [(0, 17, 'Person')]}),
              ("Paul Estournelles de Constant", {'entities': [(0, 28, 'Person')]}),
              ("Alfonso García Robles", {'entities': [(0, 20, 'Person')]}),
              ("Michele Bachmann is a United States Senator", {'entities': [(0, 16, 'Person')]}),
              ("Rigoberta Menchú", {'entities': [(0, 15, 'Person')]}),
              ("Nelson Mandela was declared Democratic", {'entities': [(0, 13, 'Person')]}),
              ("2006 House Caucus leadership election", {'entities': [(0, 0, 'Person')]}),
              ("Denis Mukwege studied in Occidental College", {'entities': [(0, 12, 'Person')]}),
              ("Juan Manuel Santos", {'entities': [(0, 17, 'Person')]}),
              ("Malala Yousafzai", {'entities': [(0, 15, 'Person')]}),
              ("Killing of Osama bin Laden", {'entities': [(11, 26, 'Person')]}),
              ("Early life and career of Barack Obama", {'entities': [(25, 37, 'Person')]}),
              ("Family of Russ Feingold", {'entities': [(10, 23, 'Person')]}),
              ("Gary Johnson", {'entities': [(0, 11, 'Person')]}),
              ("American Friends Service Committee", {'entities': [(0, 0, 'Person')]}),
              ("/bəˈrɑːk huːˈseɪn oʊˈbɑːmə/ ", {'entities': [(0, 0, 'Person')]}),
              ("some of Wright's statements were criticized", {'entities': [(0, 0, 'Person')]}),
              ("Kalorama (Washington, D.C.)", {'entities': [(0, 0, 'Person')]}),
              ("Barack Obama (disambiguation)", {'entities': [(0, 12, 'Person')]}),
              ("Vice President", {'entities': [(0, 0, 'Person')]}),
              ("1 2 3 4 5 6 7 8 9 11 1231 13412 542345 0969 5634 2345427 23 63563", {'entities': [(0, 0, 'Person')]})
]

# Load other spacy model
nlp = spacy.load("en_core_web_sm")

# Create a DocBin object
db = DocBin()

for text, annot in tqdm(train_data): # Data in previous format
    
    doc = nlp.make_doc(text) # Create doc object from text
    ents = []
    
    for start, end, label in annot["entities"]: # add character indexes
        span = doc.char_span(start, end, label = label, alignment_mode = 'contract')
        
        if span is None: 
            print('Skipping entity')
        else:
            ents.append(span)
    
    doc.ents = ents # Label the text with the ents
    db.add(doc)

os.chdir(r'....../route')
db.to_disk("./train.spacy") # Save the docbin object