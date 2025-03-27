
## Quick

```
range(0,5): 0, 1, 2, 3, 4
vec[r, c] = input[r][c] # np.array[,] = list[][]
```
```
Ctrl-D or exit()
```

## Chapter 1: Getting Started

```
print("Hello Python interpreter!")
```
```
print("Hello world!")
```
```
x-terminal-emulator -e /bin/sh %c
# Try removing the quote marks
```

## Chapter 2: Variables and Simple Data Types

```
message = "Hello Python Crash Course world!"
print(message)
```
```
name = "ada lovelace"
print(name.title())
```
```
name = "Ada Lovelace"
print(name.upper())
print(name.lower())
```
```
print("\tPython")
```
```
print("Languages:\n\tPython\n\tC\n\tJavaScript")
```
```
double quotes would be best
```
```
favorite_language = 'python '
favorite_language.rstrip()
favorite_language.lstrip()
favorite_language.strip()
```
```
3 / 2
3 ** 2
```
```
age = 23
message = "Happy " + str(age) + "rd Birthday!"
```
```
# Say hello to everyone.
```

## Chapter 3: Introducing Lists

```
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[0].title())
```
```
bicycles = ['trek', 'cannondale', 'redline', 'specialized']
print(bicycles[-1])
```
```
motorcycles = ['honda', 'yamaha', 'suzuki']
motorcycles[0] = 'ducati'
motorcycles.append('ducati')
motorcycles = []

motorcycles = ['honda', 'yamaha', 'suzuki']
motorcycles.insert(0, 'ducati')
del motorcycles[0]
```
```
x = [1, 2, 3]
x.append([4, 5])
[1, 2, 3, [4, 5]]

x = [1, 2, 3]
x.extend([4, 5])
[1, 2, 3, 4, 5]
```
```
motorcycles = ['honda', 'yamaha', 'suzuki']
popped_motorcycle = motorcycles.pop()   # remove from end of list
first_owned = motorcycles.pop(0)
```
```
motorcycles = ['honda', 'yamaha', 'suzuki', 'ducati']
print(motorcycles)
motorcycles.remove('ducati')

too_expensive = 'ducati'
motorcycles.remove(too_expensive)
```
```
cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.sort()
cars.sort(reverse = True)
```
```
cars = ['bmw', 'audi', 'toyota', 'subaru']
print(sorted(cars))      # temporarily
```
```
cars = ['bmw', 'audi', 'toyota', 'subaru']
cars.reverse()

len(cars)
```

## Chapter 4: Working with Lists

```
magicians = ['alice', 'david', 'carolina']
for magician in magicians:
  print(magician)

# Always indent the line after the ‘for’ statement in a loop.
```
```
IndentationError: unexpected indent
Forgetting the Colon: SyntaxError: invalid syntax
```
```
for value in range(1,5):
  print(value)
1
2
3
4
# off-by-one behavior
```
```
numbers = list(range(1,6))
```
```
even_numbers = list(range(2, 11, 2))
```
```
squares = []
for value in range(1,11):
  square = value**2
  squares.append(square)
print(squares)
```
```
digits = [1, 2, 3, 4, 5, 6, 7, 8, 9, 0]
print(min(digits))
print(max(digits))
print(sum(digits))
squares = [value**2 for value in range(1,11)]
print(squares)
```
```
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print(players[0:3])  
# 0, 1, 2
# Python stops one item before the second index you specify.

print(players[:4])
# starts at the beginning of the list

print(players[2:])
# from the third item through the end of the list

print(players[-3:])
# last three players
```
```
players = ['charles', 'martina', 'michael', 'florence', 'eli']
print("Here are the first three players on my team:")
for player in players[:3]:
  print(player.title())
```
```
my_foods = ['pizza', 'falafel', 'carrot cake']
friend_foods = my_foods[:]         # create new data structure
```
```
my_foods = ['pizza', 'falafel', 'carrot cake']
# This doesn't work:
friend_foods = my_foods
my_foods.append('cannoli')
friend_foods.append('ice cream')

# now both variables point to the same list
# append twice
```
```
dimensions = (200, 50)
# tuple
```
```
dimensions = (200, 50)
dimensions[0] = 250
TypeError: 'tuple' object does not support item assignment
```
```
dimensions = (200, 50)
for dimension in dimensions:
  print(dimension)
```
```
dimensions = (200, 50)
dimensions = (400, 100)
# Writing over a Tuple
```

## Chapter 5: if Statements

```
cars = ['audi', 'bmw', 'subaru', 'toyota']
for car in cars:
  if car == 'bmw':
    print(car.upper())
  else:
    print(car.title())
```
```
car = 'Audi'
car.lower() == 'audi'
```
```
if requested_topping != 'anchovies':
  print("Hold the anchovies!")

<, <=, >, >=
```
```
age_0 >= 21 and age_1 >= 21
(age_0 >= 21) and (age_1 >= 21)
age_0 >= 21 or age_1 >= 21
```
```
requested_toppings = ['mushrooms', 'onions', 'pineapple']
'mushrooms' in requested_toppings
```
```
banned_users = ['andrew', 'carolina', 'david']
user = 'marie'
if user not in banned_users:
  print(user.title() + ", you can post a response if you wish.")
```
```
if conditional_test:
  do something
```
```
age = 12
if age < 4:
  print("Your admission cost is $0.")
elif age < 18:
  print("Your admission cost is $5.")
else:
  print("Your admission cost is $10.")
```
```
age = 12
if age < 4:
  price = 0
elif age < 18:
  price = 5
elif age < 65:
  price = 10
elif age >= 65:
  price = 5
print("Your admission cost is $" + str(price) + ".")
```
```
requested_toppings = ['mushrooms', 'extra cheese']
if 'mushrooms' in requested_toppings:
  print("Adding mushrooms.")
```
```
requested_toppings = ['mushrooms', 'green peppers', 'extra cheese']
for requested_topping in requested_toppings:
  print("Adding " + requested_topping + ".")
```

## Chapter 6: Dictionaries

```
alien_0 = {'color': 'green', 'points': 5}
print(alien_0['color'])
print(alien_0['points'])

# list[] tuple() dictionary{:,:} set{,}
```
```
alien_0 = {}
alien_0['color'] = 'green'
alien_0['points'] = 5

alien_0 = {'color': 'green', 'points': 5}
alien_0['x_position'] = 0
alien_0['y_position'] = 25

alien_0 = {'color': 'green'}
alien_0['color'] = 'yellow'
```
```
alien_0 = {'color': 'green', 'points': 5}
del alien_0['points']
```
```
user_0 = {
  'username': 'efermi',
  'first': 'enrico',
  'last': 'fermi',
}
for key, value in user_0.items():
  print("\nKey: " + key)
  print("Value: " + value)

for k, v in user_0.items()
for name, language in favorite_languages.items():

for name in favorite_languages.keys():
for name in favorite_languages:

if 'erin' not in favorite_languages.keys():

for name in sorted(favorite_languages.keys()):

for language in favorite_languages.values():

for language in set(favorite_languages.values()):
```
```
favorite_languages = {
'jen': 'python',
'sarah': 'c',
'edward': 'ruby',
'phil': 'python',
}

friends = ['phil', 'sarah']
for name in favorite_languages.keys():
  print(name.title())
  if name in friends:
    print(" Hi " + name.title() +
      ", I see your favorite language is " +
      favorite_languages[name].title() + "!")
```
```
alien_0 = {'color': 'green', 'points': 5}
alien_1 = {'color': 'yellow', 'points': 10}
alien_2 = {'color': 'red', 'points': 15}
aliens = [alien_0, alien_1, alien_2]
```
```
for alien_number in range(30):
# range(3) == [0, 1, 2]
```
```
pizza = {
  'crust': 'thick',
  'toppings': ['mushrooms', 'extra cheese'],
}
```
```
users = {
  'aeinstein': {
    'first': 'albert',
    'last': 'einstein',
    'location': 'princeton',
  },
  'mcurie': {
    'first': 'marie',
    'last': 'curie',
    'location': 'paris',
  },
}
```

## Chapter 7: User Input and while Loops

```
message = input("I will repeat it back to you: ")
print(message)

# python3
```
```
height = input("How tall are you, in inches? ")
height = int(height)
```
```
4 % 3
```
```
current_number = 1
while current_number <= 5:
  print(current_number)
  current_number += 1
```
```
while message != 'quit':
  message = input(prompt)
  print(message)
```
```
while True:
  city = input(prompt)
  if city == 'quit':
    break
  else:
    print("I'd love to go to " + city.title() + "!")
```
```
current_number = 0
while current_number < 10:
  current_number += 1
  if current_number % 2 == 0:
    continue
  print(current_number)
```
```
unconfirmed_users = ['alice', 'brian', 'candace']
confirmed_users = []

while unconfirmed_users:
  current_user = unconfirmed_users.pop()
  print("Verifying user: " + current_user.title())
  confirmed_users.append(current_user)
  
print("\nThe following users have been confirmed:")
for confirmed_user in confirmed_users:
  print(confirmed_user.title())
```
```
pets = ['dog', 'cat', 'dog', 'goldfish', 'cat', 'rabbit', 'cat']
while 'cat' in pets:
  pets.remove('cat')
```
```
responses = {}
polling_active = True
while polling_active:
  name = input("\nWhat is your name? ")
  response = input("Which mountain ... to climb someday? ")
  responses[name] = response
  repeat = input("... to let another person respond? (yes/ no) ")
  if repeat == 'no':
    polling_active = False
print("\n--- Poll Results ---")
for name, response in responses.items():
  print(name + " would like to climb " + response + ".")
```

## Chapter 8: Functions

```
def greet_user(username):
  """Display a simple greeting."""
  print("Hello, " + username.title() + "!")

greet_user('jesse')
```
```
def describe_pet(animal_type, pet_name):
  """Display information about a pet."""
  print("\nI have a " + animal_type + ".")
  print("My " + animal_type + "'s name is " + pet_name.title() + ".")

describe_pet('hamster', 'harry')
```
```
def describe_pet(pet_name, animal_type='dog'):
  """Display information about a pet."""
  print("\nI have a " + animal_type + ".")
  print("My " + animal_type + "'s name is " + pet_name.title() + ".")
  
describe_pet('willie')
```
```
def get_formatted_name(first_name, last_name):
  """Return a full name, neatly formatted."""
  full_name = first_name + ' ' + last_name
  return full_name.title()

musician = get_formatted_name('jimi', 'hendrix')
print(musician)
```
```
def get_formatted_name(first_name, last_name, middle_name=''):
```
```
def build_person(first_name, last_name, age=''):
  """Return a dictionary of information about a person."""
  person = {'first': first_name, 'last': last_name}
  if age:
    person['age'] = age
  return person
musician = build_person('jimi', 'hendrix', 27)
print(musician)
```
```
print_models(unprinted_designs, completed_models)

print_models(unprinted_designs[:], completed_models)
# Preventing a Function from Modifying a List
```
```
def make_pizza(*toppings):  # empty tuple
  """Print the list of toppings that have been requested."""
  print(toppings)

make_pizza('pepperoni')
make_pizza('mushrooms', 'green peppers', 'extra cheese')
```
```
def build_profile(first, last, **user_info): # empty dictionary
```
```
# pizza.py
def make_pizza(size, *toppings):

------

import pizza
pizza.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

------

from pizza import make_pizza
make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

------

from pizza import make_pizza as mp

import pizza as p
p.make_pizza(12, 'mushrooms', 'green peppers', 'extra cheese')

from pizza import *
```

## Chapter 9: Classes

```
class Dog():
    """A simple attempt to model a dog."""
    
    def __init__(self, name, age):
        """Initialize name and age attributes."""
        self.name = name
        self.age = age
        
    def sit(self):
        """Simulate a dog sitting in response to a command."""
        print(self.name.title() + " is now sitting.")

    def roll_over(self):
        """Simulate rolling over in response to a command."""
        print(self.name.title() + " rolled over!")
        

my_dog = Dog('willie', 6)

print("My dog's name is " + my_dog.name.title() + ".")
print("My dog is " + str(my_dog.age) + " years old.")
my_dog.sit()
```
```
def __init__(self, make, model, year):
  """Initialize attributes to describe a car."""
  self.make = make
  self.model = model
  self.year = year
  self.odometer_reading = 0
```
```
class Car():

class ElectricCar(Car):
  def __init__(self, make, model, year):
    super().__init__(make, model, year)
    self.battery_size = 70
```
```
class Car():
  def fill_gas_tank():

class ElectricCar(Car):
  def fill_gas_tank():
```
```
class Battery():

class ElectricCar(Car)
  def __init__(self, make, model, year):
    self.battery = Battery()
```
```
# car.py
class Car():
class Battery():
class ElectricCar(Car):

# my_car.py
from car import Car, ElectricCar

my_beetle = Car('volkswagen', 'beetle', 2016)
my_tesla = ElectricCar('tesla', 'roadster', 2016)

#
import car
my_beetle = car.Car('volkswagen', 'beetle', 2016)
my_tesla = car.ElectricCar('tesla', 'roadster', 2016)
```
```
# car.py
class Car():

# electric_car.py
from car import Car

class Battery():
class ElectricCar(Car):

# my_cars.py
from car import Car
from electric_car import ElectricCar
```
```
from collections import OrderedDict

favorite_languages = OrderedDict()

# always get responses back in the order they were added
```

## Chapter 10: Files and Exceptions

```
file

4 3
1 2 3 4
2 3 4 5
6 7 8 9

====

with open('file') as f:   # next: next input line or EOF
    w, h = [int(x) for x in next(f).split()] # read first line
    array = []
    for line in f:                           # read rest of lines
        array.append([int(x) for x in line.split()])

with open('file') as f:
    w, h = [int(x) for x in next(f).split()]
    array = [[int(x) for x in line.split()] for line in f]

print(w, h)
print(array)
print(array[1][2])

(4, 3)
[[1, 2, 3, 4], [2, 3, 4, 5], [6, 7, 8, 9]]
4
```
```
filename = 'pi_digits.txt'

----

with open(filename) as file_object:
  contents = file_object.read()
  print(contents.rstrip())

----

with open('pi_digits.txt') as file_object:
  for line in file_object:
    print(line.rstrip())

----

with open(filename) as file_object:
    lines = file_object.readlines()

for line in lines:
    print(line.rstrip())

----

pi_string = ''
for line in lines:
  pi_string += line.strip()
print(pi_string)
print(len(pi_string))

----

print(pi_string[:52] + "...")
print(len(pi_string))

----

birthday = input("Enter your birthday, in the form mmddyy: ")
if birthday in pi_string:
```
```
filename = 'programming.txt'  # r, a, w, x - t, b

with open(filename, 'w') as file_object:
  file_object.write("I love programming.\n")
  file_object.write("I love creating new games.\n")

with open(filename, 'a') as file_object:
```
```
try:
  answer = int(first_number) / int(second_number)
except ZeroDivisionError:
  print("You can't divide by 0!")
else:
  print(answer)
```
```
filename = 'alice.txt'

try:
  with open(filename, encoding='utf-8') as f_obj:
    contents = f_obj.read()
except FileNotFoundError as e:
  msg = "Sorry, the file " + filename + " does not exist."
  print(msg)
else:
  words = contents.split()
  num_words = len(words)
  print("The file " + filename + " has about " + str(num_words) + " words.")

----

except FileNotFoundError:
  pass
```
```
line = "Row, row, row your boat"
line.count('row')
```
```
import json

numbers = [2, 3, 5, 7, 11, 13]

filename = 'numbers.json'
with open(filename, 'w') as file_object:
    json.dump(numbers, file_object)

----

import json

filename = 'numbers.json'
with open(filename) as file_object:
    numbers = json.load(file_object)
    
print(numbers)
```
```
fr = "YouTube.html"
fw = "yt_list.txt"

with open(fr, 'r') as fo:
  lines = fo.readlines()
  for line in lines:
	if 'rel="null" href="https://www.youtube.com/watch?v=' in line:
	  with open(fw, 'a') as f1:
		f1.write(line)
```
```
import os
os.remove("demofile.txt")

if os.path.exists("demofile.txt"):
  os.remove("demofile.txt")
else:
  print("The file does not exist")

os.rmdir("myfolder")
```
```
f = open("demofile.txt", "r")
print(f.read())

print(f.read(5))

print(f.readline())    # vs. readlines
print(f.readline())

f.close()
```

## Chapter 11: Testing Your Code

```
import unittest
from name_function import get_formatted_name

class NamesTestCase(unittest.TestCase):
  """Tests for 'name_function.py'."""
    
  def test_first_last_name(self):
    formatted_name = get_formatted_name('janis', 'joplin')
    self.assertEqual(formatted_name, 'Janis Joplin')
        
  def test_first_last_middle_name(self):
    formatted_name = get_formatted_name(
        'wolfgang', 'mozart', 'amadeus')
    self.assertEqual(formatted_name, 'Wolfgang Amadeus Mozart')            

unittest.main()
```
```
assertEqual(a, b)       Verify that a == b
assertNotEqual(a, b)    Verify that a != b
assertTrue(x)           Verify that x is True
assertFalse(x)          Verify that x is False
assertIn(item, list)    Verify that item is in list
assertNotIn(item, list) Verify that item is not in list
```
```
import unittest
from survey import AnonymousSurvey

class TestAnonymousSurvey(unittest.TestCase):
  """Tests for the class AnonymousSurvey."""
    
  def setUp(self):
    """
    Create a survey and a set of responses for use 
    in all test methods.
    """
    question = "What language did you first learn to speak?"
    self.my_survey = AnonymousSurvey(question)
    self.responses = ['English', 'Spanish', 'Mandarin']        
    
  def test_store_single_response(self):
    """Test that a single response is stored properly."""
    self.my_survey.store_response(self.responses[0])
    self.assertIn(self.responses[0], self.my_survey.responses)        
        
  def test_store_three_responses(self):
    """Test that three individual responses are stored properly."""
    for response in self.responses:
      self.my_survey.store_response(response)
    for response in self.responses:
      self.assertIn(response, self.my_survey.responses)            

unittest.main()
```

## Snippet

```
new_lines = []
np.array(new_lines)
```
```
import math
math.sqrt(4)
```
```
import os
filename, file_extension = os.path.splitext('/path/somefile.ext')
```

## ()[]{}

```
>>> int()
0

>>> str()
''

>>> dict()
{}

>>> set()
set()

>>> list()
[]

>>> tuple()
()

>>> b = np.arange( 4 )
>>> b
array([0, 1, 2, 3])

() - tuple: a sequence of items that can't be changed (immutable).
[] - list: a sequence of items that can be changed (mutable).
{} - dictionary or set

Parentheses are smooth and curved ().
Brackets are square [].
Braces are curly {}.
```

