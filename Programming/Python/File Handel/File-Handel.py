fname = "shuva"
print("File name is",fname)
fhand = open(fname,"a")
'''
'r' ==> for Read Mode (if file is not created then it gives an error)
'w' ==> for write Mode (if file is not created then it create a new file, if the file is created then it over write this file)
'a' ==> for append Mode (if file is not created then it create a new file, if the file is created then it start writing after last charecter)
'''
fhand.write("\nHello Shuva")
fhand.close()
fhand = open(fname,"r")
print(fhand.read())
fhand.close()
