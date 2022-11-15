# Programming Languages
This was a course I took in 2022-2 where I learned so much about programming paradigms and the various types of programming languajes there are in the world.
The firts part was an introduccion to assemblers and how they were helpful to connect people and computers. In the second part I learned how imperative languajes works, in this case using C++ (Project 1), in the third part we use functional programming in Scala to develop a program to solve prefix notation (Project 2) and at the end the teacher proposed a project mixing Web Scraping and Named Entity Recognition, in Python (Final Project).


## Project 1
The idea of this project was learning OOP and Data Structures (linked lists) recreating the popular game Wordle.

A word is given by the computer an the user has to guess in 6 attemps. If a letter in the user's word is in the computer's word but in a wrong position is printed in terminal with yellow but if it is in the correct position is printed with green. Given the case a a letter in the user's word is not in the computer's word it is printed with white.

This project is in C++, 'main.cpp' is the file that contain the interface but 'methods.h' is the header where the methods are. Download both but just compile and run the main.


## Project 2
The idea of this project was learning Functional Programing and use a new Data Structure (trees), but also applied a little bit of OOP.

Prefix notation is a way to write a math problem, for example '+57' means in infix notation '5+7'. The user write an operation (numbers, +, -, *, /) with prefix notation and the program organize the operation in a binary tree and then solve it traversing in-order.

In the support of the project to the teacher I had to add this rules:
- '@' pow
- '#' if a > b then a + b or if a < b then a - b
- '2' if '2' is followed with two numbers, it acts like division: '223' is equal to 2/3

This project is in Scala, the main file has all you need to run it and has a default test in the main object.


## Final Project
The idea of this project was using Graphs to store and search data.

Frigyes Karinthy proposed in his 1930 story "Chains" the theory of the six degrees of separation. This theory proposes that a person can contact any other person in the world using a maximum of five contacts. 
Determine if a person (p1) is connected to another person (p2). This connection will be determined from a network of contacts that will be formed automatically based on the people listed on the Wikipedia pages of p1, p2 and their derived contacts. 

This project is in Python.
scraping.py has two functions, the first is to search a path between p1 and p1, the second search a contact of p1 that starts with each letter of the alphabet.
training.py is an attemp of training a NER. It did a great work but not as the default does, but if you want to see what I did there is the file.
You have to download all the files and run the 'main.py'.

## Extra
To understand the operation of a NER i used:
1. Extract all the links and its information.
- Terminal asking the name and setting the url https://youtu.be/YY5skv756pc
- The request program https://youtu.be/gsj-qqEfkCk

2. Named Entity recognition:
- https://youtu.be/1ePkOSGoIFI
- https://youtu.be/9mXoGxAn6pM
- https://github.com/dreji18/NER-Training-Spacy-3.0/blob/main/NER%20Training%20with%20Spacy%20v3%20Notebook.ipynb
- https://spacy.io/usage/training#config
