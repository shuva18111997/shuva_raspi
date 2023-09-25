cars = []

cars.append("Ford")
cars.append("Volvo")
cars.append("BMW")
cars.append("Honda")

for i in range(len(cars)):
    print("cars[%s] = "%i + cars[i])
    
#Delete the second element of the cars array.
cars.pop(0)

print(cars)

#We can also use the remove() method to remove an element from the array.
cars.remove("Volvo")

print(cars)