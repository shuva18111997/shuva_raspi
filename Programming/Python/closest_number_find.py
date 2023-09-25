def closest(lst, K):
     
    return lst[min(range(len(lst)), key = lambda i: abs(lst[i]-K))]

lst = [1, 2, 3, 4, 5, 6, 9, 10, 12, 15, 18, 20, 25, 30, 36, 45, 50, 60, 75, 90, 100, 150, 180, 225, 300, 450, 900]
K = 215
reminder = closest(lst, K)
print(reminder)