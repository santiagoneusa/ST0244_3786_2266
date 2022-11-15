import re
import string
import spacy
import methods as m


# Global variables

nlp = spacy.load('en_core_web_sm')
# In case you want to make you custom NER model with SpaCy and use is, change the npl with the following line
# nlp = spacy.load(r"......./output/model-best")

nlp.pipe_names
analized_1 = []
analized_2 = []
alphabet = []


def scraping(origin_content, target_character, path, counter, found):
    
    
    if counter == 0: 
        
        found = False
        return found, path
    
    else:
        
        # Create a new dictionary 
        information = {}
        
        # Analize each link in the HTML
        for link in origin_content.find_all('a', attrs={'href': re.compile('^/wiki/')}):
            
            # We'll store maximum 30 links per person.
            if len(information) <= 30:
                
                # Identify the identities in de link.
                document = nlp(link.text)
                
                # Analize identities in 'document'. A line can contain multiple identities.
                for entity in document.ents:
                        
                    # If is has this word is descarted.
                    if ('disambiguation' in link.text): pass
                    
                    else:
                        # If is not in analized_1 (loking for reducing repeated data)
                        if (entity.label_ == 'PERSON') and (link.text not in analized_1):
                            
                            # Creates a key and a value in the dictionary 'information'. 
                            name = string.capwords(link.text)
                            information[name] = 'http://en.wikipedia.org/' + (link.get('href'))
                            analized_1.append(name)
                                
            else: break
                                
                                
        # Search the target in 'information'.
        for name, link in information.items():
            if name == target_character:
                found = True
                path.append((name, link))
                return found, path

        
        # If it doesn't find the target, makes the recursion
        for name, link in information.items():
            path.append(name)
            found, path = scraping(m.data(link), target_character, path, counter - 1, found)
            if found is True: return found, path


def scraping_abc(origin_content, path, counter, abc, position):

    if counter == 0: return path
    
    else:
        
        information = {}

        for link in origin_content.find_all('a', attrs={'href': re.compile('^/wiki/')}):
            
            if len(information) <= 100:
           
                document = nlp(link.text)
                
                for entity in document.ents:
                        
                    if ('disambiguation' in link.text): pass
                    
                    else:
                        if (entity.label_ == 'PERSON') and (link.text not in analized_2):
                            name = string.capwords(link.text)
                            information[name] = 'http://en.wikipedia.org/' + (link.get('href'))
                            analized_2.append(name)
                                
            else: break
                                
        # Asume that the person with the letter is in the dictionary.               
        found = True
        
        for name, link in information.items():
            
            # If its found
            if name[0] == abc[position]:
                
                # Declare True because in other itetarions the value of found could change
                found = True
                path.append(name)
                path = scraping_abc(m.data(link), path, counter - 1, abc, position + 1)
                return path
            
            else:
                found = False
            
            
        if not found:
            print(f'there is no {abc[position]}')
            path = scraping_abc(m.data(link), path, counter - 1, abc, position + 1)
            return path
