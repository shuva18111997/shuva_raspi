import struct

f = open("data_mem.txt", "w")

#write the range here
negInt_for_3 = 0
posInt_for_3 = 7

negInt_for_5 = 0
posInt_for_5 = 2

cnt = 0

for i in range(negInt_for_3, posInt_for_3 + 1):
    for j in range(negInt_for_5, posInt_for_5 + 1):
        cnt = cnt + 1
        data = str("{0:08b}".format(cnt)) + " "
        f.write(data)
        print(i, j, data + "\n")
    f.write("\n")
    print("\n")
    
f.close()
